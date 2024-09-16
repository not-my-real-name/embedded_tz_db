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

# This template is recognized in c/cs files and removed/replaced with dynamically generated data.
C_TEMPLATE_DECLARATION = "//! Declaration goes here!"

# Short zone list - Taken from https://github.com/mattjohnsonpint/TimeZoneNames
# Installed nuget package and then run the following: 
#    var db = TZNames.GetDisplayNames("en-US", true);
# The short list is intended to be used to make a timezone selection drop down list much shorter.
# The full list should be used when looking up an IANA zone to cover the possibility of it not being in this list.
SHORT_ZONE_LIST = [
    "Etc/GMT+12",
    "Etc/GMT+11",
    "America/Adak",
    "Pacific/Honolulu",
    "Pacific/Marquesas",
    "America/Anchorage",
    "Etc/GMT+9",
    "America/Tijuana",
    "Etc/GMT+8",
    "America/Los_Angeles",
    "America/Phoenix",
    "America/Chihuahua",
    "America/Denver",
    "America/Whitehorse",
    "America/Guatemala",
    "America/Chicago",
    "Pacific/Easter",
    "America/Mexico_City",
    "America/Regina",
    "America/Bogota",
    "America/Cancun",
    "America/New_York",
    "America/Port-au-Prince",
    "America/Havana",
    "America/Indiana/Indianapolis",
    "America/Grand_Turk",
    "America/Asuncion",
    "America/Halifax",
    "America/Caracas",
    "America/Cuiaba",
    "America/La_Paz",
    "America/Santiago",
    "America/St_Johns",
    "America/Araguaina",
    "America/Sao_Paulo",
    "America/Cayenne",
    "America/Argentina/Buenos_Aires",
    "America/Nuuk",
    "America/Montevideo",
    "America/Punta_Arenas",
    "America/Miquelon",
    "America/Bahia",
    "Etc/GMT+2",
    "Atlantic/Azores",
    "Atlantic/Cape_Verde",
    "Etc/UTC",
    "Europe/London",
    "Africa/Abidjan",
    "Africa/Sao_Tome",
    "Africa/Casablanca",
    "Europe/Berlin",
    "Europe/Budapest",
    "Europe/Paris",
    "Europe/Warsaw",
    "Africa/Lagos",
    "Europe/Bucharest",
    "Asia/Beirut",
    "Africa/Cairo",
    "Europe/Chisinau",
    "Asia/Damascus",
    "Asia/Hebron",
    "Africa/Johannesburg",
    "Europe/Kyiv",
    "Asia/Jerusalem",
    "Africa/Juba",
    "Europe/Kaliningrad",
    "Africa/Khartoum",
    "Africa/Tripoli",
    "Africa/Windhoek",
    "Asia/Amman",
    "Asia/Baghdad",
    "Europe/Istanbul",
    "Asia/Riyadh",
    "Europe/Minsk",
    "Europe/Moscow",
    "Africa/Nairobi",
    "Europe/Volgograd",
    "Asia/Tehran",
    "Asia/Dubai",
    "Europe/Astrakhan",
    "Asia/Baku",
    "Europe/Samara",
    "Indian/Mauritius",
    "Europe/Saratov",
    "Asia/Tbilisi",
    "Asia/Yerevan",
    "Asia/Kabul",
    "Asia/Tashkent",
    "Asia/Yekaterinburg",
    "Asia/Karachi",
    "Asia/Qyzylorda",
    "Asia/Kolkata",
    "Asia/Colombo",
    "Asia/Kathmandu",
    "Asia/Almaty",
    "Asia/Dhaka",
    "Asia/Omsk",
    "Asia/Yangon",
    "Asia/Bangkok",
    "Asia/Barnaul",
    "Asia/Hovd",
    "Asia/Krasnoyarsk",
    "Asia/Novosibirsk",
    "Asia/Tomsk",
    "Asia/Shanghai",
    "Asia/Irkutsk",
    "Asia/Singapore",
    "Australia/Perth",
    "Asia/Taipei",
    "Asia/Ulaanbaatar",
    "Australia/Eucla",
    "Asia/Chita",
    "Asia/Tokyo",
    "Asia/Pyongyang",
    "Asia/Seoul",
    "Asia/Yakutsk",
    "Australia/Adelaide",
    "Australia/Darwin",
    "Australia/Brisbane",
    "Australia/Sydney",
    "Pacific/Port_Moresby",
    "Australia/Hobart",
    "Asia/Vladivostok",
    "Australia/Lord_Howe",
    "Pacific/Bougainville",
    "Asia/Srednekolymsk",
    "Asia/Magadan",
    "Pacific/Norfolk",
    "Asia/Sakhalin",
    "Pacific/Guadalcanal",
    "Asia/Kamchatka",
    "Pacific/Auckland",
    "Etc/GMT-12",
    "Pacific/Fiji",
    "Pacific/Chatham",
    "Etc/GMT-13",
    "Pacific/Tongatapu",
    "Pacific/Apia",
    "Pacific/Kiritimati",
]

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

#The zone now file includes only the current zones. However, it has some limitations that make it unsuitable for 
# the application of presenting timezone selection options to users. It has lots of zones omitted becuase the rule is identical.
# This means you would have to select "Asia/Kamchatka" if you wanted "Pacific/Fiji" which is not at all intuitive.
# It would require better parsing to show more options.
#ZONES = parse_timezones(ZONES_DIR + "zonenow.tab")
ALL_ZONES = parse_timezones(ZONES_DIR + "zone.tab")

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


def make_timezones_dict(zoneList):
    result = {}
    for timezone in zoneList:
        timezone = timezone.strip()
        result[timezone] = get_tz_string(timezone)
    return result

def print_csv(timezones_short, timezones_all):
    csv = []
    for name, tz in timezones_short.items():
        csv.append('"{}","{}"'.format(name, tz))
    write_file(OUTPUT_FOLDER + "csv/embedded_tz_db_short.csv", "\n".join(csv))
    csv = []
    for name, tz in timezones_all.items():
        csv.append('"{}","{}"'.format(name, tz))
    write_file(OUTPUT_FOLDER + "csv/embedded_tz_db.csv", "\n".join(csv))


def print_json(timezones_short, timezones_all):
    json_obj_short = json.dumps(
        timezones_short, indent=4, sort_keys=True, separators=(",", ":")
    )
    json_obj = json.dumps(
        timezones_all, indent=4, sort_keys=True, separators=(",", ":")
    )
    
    write_file(OUTPUT_FOLDER + "json/embedded_tz_db_short.json", json_obj_short)
    write_file(OUTPUT_FOLDER + "json/embedded_tz_db.json", json_obj)
    
    js = "//IANA time Zone database version used to generate this file.\n"
    js += "const embedded_tz_IanaDbVers = \"%s\";\n\n" % ( TZ_VERSION )
    js += "// Short List of selectable time zones for embedded devices\n";
    js += "const embedded_tz_db_short = " + json_obj_short + ";\n"
    write_file(OUTPUT_FOLDER + "json/embedded_tz_db_short.js", js)
    
    js = "//IANA time Zone database version used to generate this file.\n"
    js += "const embedded_tz_IanaDbVers = \"%s\";\n\n" % ( TZ_VERSION )
    js += "// Short List of selectable time zones for embedded devices\n";
    
    shortNameList = []
    for name, tz in timezones_short.items():
        shortNameList.append('\n    "{}"'.format(name))
    js += "const embedded_tz_db_shortNameList = [" + ",".join(shortNameList) + "\n];\n"
    js += "\n// Complete List of IANA time zones and the associated posix rule for each\n";
    js += "const embedded_tz_db = " + json_obj + ";"
    write_file(OUTPUT_FOLDER + "json/embedded_tz_db.js", js)

def hash_str(value):
    strSum = 0
    for char in value:
        strSum += ord(char.lower().replace(' ','_'))
    return strSum & 0xFF

def print_embedded(timezones_short, timezones_all):
    pairs = [
        '\n  {"%s", "%s"}' % (name, posix_str)
        for name, posix_str in timezones_all.items()
    ]
    hashTable = [
        '\n  %s' % (hash_str(name))
        for name, tz in timezones_all.items()
    ]
    
    pairs_short = [
        '\n  {"%s", "%s"}' % (name, posix_str)
        for name, posix_str in timezones_short.items()
    ]
    hashTable_short = [
        '\n  %s' % (hash_str(name))
        for name, tz in timezones_short.items()
    ]
    
    declaration = "static const char * TZ_DATA_VERS = \"%s\";\n\n" % ( TZ_VERSION )
    
    declaration += "#if TZ_DB_USE_SHORT_LIST\n";
    declaration += "static const embeddedTz_t embedded_tz_db_zones[%s] = {%s\n};\n\n" % (
        len(pairs_short),
        ",".join(pairs_short),
    )
    declaration += "/** This hash table allows for faster lookup of the timezone names. Timezones are not in alphabetical order. \n"
    declaration += " *  Timezone names are converted to lower case and then summed. The 8 bit sum is stored here.\n **/\n"
    declaration += "static const unsigned char embedded_tz_db_hashTable[%s] = {%s\n};\n" % (
        len(hashTable_short),
        ",".join(hashTable_short),
    )
    declaration += "#else\n//Full List\n";
    declaration += "static const embeddedTz_t embedded_tz_db_zones[%s] = {%s\n};\n\n" % (
        len(pairs),
        ",".join(pairs),
    )
    declaration += "/** This hash table allows for faster lookup of the timezone names. Timezones are not in alphabetical order. \n"
    declaration += " *  Timezone names are converted to lower case and then summed. The 8 bit sum is stored here.\n **/\n"
    declaration += "static const unsigned char embedded_tz_db_hashTable[%s] = {%s\n};\n" % (
        len(hashTable),
        ",".join(hashTable),
    )
    declaration += "#endif\n";
    
    with open(TEMPLATES_DIR + "embedded_tz_db.template.c") as template:
        template_c = template.read()
    write_file(OUTPUT_FOLDER + "c/embedded_tz_db.c", template_c.replace(C_TEMPLATE_DECLARATION, declaration))
    
    with open(TEMPLATES_DIR + "embedded_tz_db.template.h") as template:
        template_h = template.read()
        
    header = template_h.replace("/*!!{NUM_ZONES}*/", "%s" %(len(pairs)))
    header = header.replace("/*!!{NUM_ZONES_SHORT}*/", "%s" %(len(pairs_short)))
    write_file(OUTPUT_FOLDER + "c/embedded_tz_db.h", header)
    
def print_cSharp(timezones_short, timezones_all):
    csZones = [
        '\n            {"%s", "%s"}' % (name, posix_str)
        for name, posix_str in timezones_all.items()
    ]
    
    csZonesShort = [
        '\n            {"%s", "%s"}' % (name, posix_str)
        for name, posix_str in timezones_short.items()
    ]
    
    declaration = "public static readonly string IanaTzDatabaseVersion = \"%s\";\n\n" % ( TZ_VERSION )
    declaration += "        /// This dictionary contains only selected timezones and their POSIX rule definitions. \n"
    declaration += "        /// It is intended as a shorter list to make it simpler to select the correct zone.\n"
    declaration += "        public static Dictionary<string, string> IanaZones_short = new Dictionary<string, string>()\n        {%s\n        };\n" % (
        ",".join(csZonesShort),
    )
    declaration += "        /// This dictionary contains all timezones and their POSIX rule definitions.\n"
    declaration += "        public static Dictionary<string, string> IanaZones = new Dictionary<string, string>()\n        {%s\n        };" % (
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

    timezones_short = make_timezones_dict(SHORT_ZONE_LIST)
    timezones_all = make_timezones_dict(ALL_ZONES)

    if data.all:
        print_json(timezones_short, timezones_all)
        print_csv(timezones_short, timezones_all)
        print_embedded(timezones_short, timezones_all)
        print_cSharp(timezones_short, timezones_all)
    if data.json:
        print_json(timezones_short, timezones_all)
    elif data.csv:
        print_csv(timezones_short, timezones_all)
    elif data.embedded:
        print_embedded(timezones_short, timezones_all)
    elif data.csharp:
        print_cSharp(timezones_short, timezones_all)
