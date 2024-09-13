#!/usr/bin/env python

import sys
import argparse
import json
import re
import subprocess
import os

ZONES_DIR = "/usr/share/zoneinfo/"
PROJECT_DIR = "/project/"
OUTPUT_FOLDER = PROJECT_DIR + "output/"
TEMPLATES_DIR = PROJECT_DIR + "templates/"

C_TEMPLATE_DECLARATION = "//! Declaration goes here!"


def write_file(file_path, text):
    # Get the directory from the file path
    directory = os.path.dirname(file_path)
    # Check if the directory exists, and create it if it doesn't
    if not os.path.exists(directory):
        os.makedirs(directory)
    # Write the string to the file
    with open(file_path, "w", encoding="utf-8") as file:
        file.write(text)

def parse_timezones(file_path):
    timezones = []
    with open(file_path, 'r', encoding='utf-8') as file:
        for line in file:
            # Ignore comment lines
            if line.startswith('#'):
                continue
            # Split the line into columns
            columns = line.split()
            if len(columns) >= 3:
                # Extract the third column (time zone)
                timezone = columns[2]
                timezones.append(timezone)
    return timezones

ZONES = parse_timezones(ZONES_DIR + "zonenow.tab")

def get_tzdata_version():
    # Run the pacman command to get package information
    result = subprocess.run(['pacman', '-Qi', 'tzdata'], stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
    
    # Check if the command was successful
    if result.returncode != 0:
        raise Exception(f"Error getting tzdata version: {result.stderr.strip()}")
    
    # Parse the output to find the version line
    for line in result.stdout.split('\n'):
        if line.startswith('Version'):
            # Extract and return the version number
            return line.split(':')[1].strip()
    
    raise Exception("Timezone database version information not found")

TZ_VERSION = get_tzdata_version()
write_file(OUTPUT_FOLDER + "db_vers.txt", TZ_VERSION)

def get_tz_string(timezone):
    data = open(ZONES_DIR + timezone, "rb").read().split(b"\n")[-2]
    return data.decode("utf-8")


def make_timezones_dict():
    result = {}
    for timezone in ZONES:
        timezone = timezone.strip()
        result[timezone] = get_tz_string(timezone)
    return result

def print_csv(timezones_dict):
    csv = []
    for name, tz in timezones_dict.items():
        csv.append('"{}","{}"'.format(name, tz))
    write_file(OUTPUT_FOLDER + "csv/embedded_tz_db.csv", "\n".join(csv))


def print_json(timezones_dict):
    json_obj = json.dumps(
        timezones_dict, indent=4, sort_keys=True, separators=(",", ":")
    )
    write_file(OUTPUT_FOLDER + "json/embedded_tz_db.json", json_obj)
    
    js = "//IANA time Zone database. Current zones only.\n"
    js += "const embedded_tz_IanaDbVers = \"%s\";\n\n" % ( TZ_VERSION )
    js += "// List of currently active time zones\n";
    js += "const embedded_tz_db = " + json_obj + ";"
    write_file(OUTPUT_FOLDER + "json/embedded_tz_db.js", js)

def hash_str(value):
    strSum = 0
    for char in value:
        strSum += ord(char.lower().replace(' ','_'))
    return strSum & 0xFF

def print_embedded(timezones_dict):
    pairs = [
        '\n  {"%s", "%s"}' % (name, posix_str)
        for name, posix_str in timezones_dict.items()
    ]
    hashTable = [
        '\n  %s' % (hash_str(name))
        for name, tz in timezones_dict.items()
    ]
    declaration = "static const char * TZ_DATA_VERS = \"%s\";\n\n" % ( TZ_VERSION )
    declaration += "static const embeddedTz_t embedded_tz_db_zones[%s] = {%s\n};\n\n" % (
        len(pairs),
        ",".join(pairs),
    )
    
    declaration += "/** This hash table allows for faster lookup of the timezone names. Timezones are not in alphabetical order. \n"
    declaration += " *  Timezone names are converted to lower case and then summed. The 8 bit sum is stored here.\n **/\n"
    declaration += "static const unsigned char embedded_tz_db_hashTable[%s] = {%s\n};" % (
        len(hashTable),
        ",".join(hashTable),
    )
    with open(TEMPLATES_DIR + "embedded_tz_db.template.c") as template:
        template_c = template.read()
    write_file(OUTPUT_FOLDER + "c/embedded_tz_db.c", template_c.replace(C_TEMPLATE_DECLARATION, declaration))
    
    with open(TEMPLATES_DIR + "embedded_tz_db.template.h") as template:
        template_h = template.read()
    write_file(OUTPUT_FOLDER + "c/embedded_tz_db.h", template_h.replace("/*!!{NUM_ZONES}*/", "%s" %(len(pairs))))
    
def print_cSharp(timezones_dict):
    csZones = [
        '\n            {"%s", "%s"}' % (name, posix_str)
        for name, posix_str in timezones_dict.items()
    ]
    declaration = "public static readonly string IanaTzDatabaseVersion = \"%s\";\n\n" % ( TZ_VERSION )
    declaration += "        /// This dictionary contains only CURRENT timezones and their POSIX rule definitions.\n"
    declaration += "        public static Dictionary<string, string> IanaCurrentZones = new Dictionary<string, string>()\n        {%s\n        };" % (
        ",".join(csZones),
    )
    
    with open(TEMPLATES_DIR + "embedded_tz_db.template.cs") as template:
        template_cs = template.read()
        
    write_file(OUTPUT_FOLDER + "c_sharp/embedded_tz_db.cs", template_cs.replace(C_TEMPLATE_DECLARATION, declaration))


if __name__ == "__main__":
    parser = argparse.ArgumentParser(
        description="Generates POSIX timezones strings reading data from " + ZONES_DIR
    )
    group = parser.add_mutually_exclusive_group(required=True)
    group.add_argument("-a", "--all", action="store_true", help="builds all")
    group.add_argument("-j", "--json", action="store_true", help="builds JSON/Javascript output")
    group.add_argument("-c", "--csv", action="store_true", help="builds CSV output")
    group.add_argument("-e", "--embedded", action="store_true", help="builds C output")
    group.add_argument("-s", "--csharp", action="store_true", help="builds C# output")
    data = parser.parse_args()

    timezones = make_timezones_dict()

    if data.all:
        print_json(timezones)
        print_csv(timezones)
        print_embedded(timezones)
        print_cSharp(timezones)
    if data.json:
        print_json(timezones)
    elif data.csv:
        print_csv(timezones)
    elif data.embedded:
        print_embedded(timezones)
    elif data.csharp:
        print_cSharp(timezones)
