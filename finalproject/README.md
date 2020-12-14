# Overview
This program takes coordinates that have been extracted from photographs and put into a .csv file,
and converts the information taken from the .csv file into a .kml format that can be viewed on Google Earth.
It also creates a log file that gives information on the name of the .kml and log files created.

# Instructions
The two arguments this program takes are -k, for the .kml file, and -l, for the log file. To create
the .kml and log files, type:

main -k [ FULL CSV FILE NAME ] -l [ DESIRED LOG FILE NAME ].txt

Once this is finished, the .kml file is ready to be loaded into Google Earth.