/**
 * @file logger.h
 * @brief Lecture 10.2 sample code
 * handles parsing a lat/long csv file and converting it to kml format
 * @author William Kloppenberg
 * @assignment Lecture 10.2
 * @date 11/14/20
 */
#ifndef EARTH_UTILS_H
#define EARTH_UTILS_H
#include <string>
#include <fstream>
using namespace std;

//constants
const string KMLHEADER1 = "<?xml version=\"1.0\" encoding=\"UTF-8\"?>";
const string KMLHEADER2 = "<kml xmlns=\"http://www.opengis.net/kml/2.2\">";
const string KMLFOOTER = "</kml>";
const string KMLDOCSTART = "<Document>";
const string KMLDOCEND = "</Document>";

/**
 * @brief writes a placemark record into an existing kmlFIle
 * @date 11/14/20
 * @param name string representing concatentated capital, country
 * @param latitude string representing latitude
 * @param longitude string representing longitude
 */
void writePlacemark(ofstream& kmlFile, string name, string latitude, string longitude);

/**
 * @brief processes a country capital csv file
 * @date 11/14/20
 * @return returns the number of records processed
 * @param inFile ifstream to an open, validated csv file
 * @param kmlFileName string containing the name of the kml file to make
 * @param logFile ofstream reference, validation expected
 */
int processCSV(ifstream& inFile, string kmlFileName);

#endif