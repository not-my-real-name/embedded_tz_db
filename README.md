# Embedded Timezone Database
This library contains a minimal list of [IANA Time Zone Database](https://www.iana.org/time-zones) names
(like "America/New_York" and "China/Shanghai") and their equivalent [POSIX `"TZ"` rule descriptions](https://www.freebsd.org/cgi/man.cgi?query=tzset)
(like "EST5EDT,M3.2.0,M11.1." and "CST-8"). This allows devices to contain a list of supported rules in firmware, and creates a list for
supporting software tools to use when configuring them.

This particular fork features a reduced set of timezones. Many of the timezones are historical and presenting the full list is not helpful. 

The output from this library is an include file for embedded C, C#, and Javascript based applications. There is also a generic CSV format file. 
It gives a common set of timezones and rules to work from. 

All timezone information is obtained from the 'tzdata' package in linux. This means that you need to re-build a new docker image in 
order to get update timezone information.

# Usage

## Build Docker image
To build the docker image, open a terminal in the root directory of this project (same directory as the docker file) and use the following command:
```sh
docker build -t embedded-tz-db .
```
## Build output files 
To build all output files, open a terminal in the root directory and run:
```sh
docker run --rm -v .\:/project -w /project -e HOME=/tmp -i embedded-tz-db ./gen-tz.py -a
```

The following options are available for the python script: 
```sh
  -h, --help      show this help message and exit
  -a, --all       builds all
  -j, --json      builds JSON/Javascript output
  -c, --csv       builds CSV output
  -e, --embedded  builds C output
  -s, --csharp    builds C# output
```

### To run interactively, navigate to the same directory in a terminal and run: 
```sh
docker run --rm -v .\:/project -w /project -e HOME=/tmp -it embedded-tz-db 
```

## Output file usage
See `example/example.c` for an embedded use case.

For other platforms the appropriate include file can be found in the output folder.


