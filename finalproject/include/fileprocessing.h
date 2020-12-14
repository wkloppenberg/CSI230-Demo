/**
 * @file fileprocessing.h
 * @brief Takes information from a .csv file and puts it into a .kml file
 * for use with Google Earth
 * @author William Kloppenberg
 * @assignment Final Project
 * @date 12/6/20
 */
#ifndef FILEPROCESSING_H
#define FILEPROCESSING_H
#include <string>
#include <fstream>

using namespace std;

//Constants
const string KMLHEAD1 = "<?xml version=\"1.0\" encoding=\"UTF-8\"?>";
const string KMLHEAD2 = "<kml xmlns=\"http://www.opengis.net/kml/2.2\">";
const string KMLSTART = "<Document>";
const string KMLEND = "</Document>";
const string KMLFOOT = "</kml>";

/**
 * @brief Creates a placemark for the .kml file
 * @date 12/6/20
 * @param kmlFile ofstream to the .kml file
 * @param name String that represents the location's name
 * @param latitude String that represents the location's latitude
 * @param longitude String that represents the location's longitude
 */
void newPlacemark(ofstream& kmlFile, string name, string latitude, string longitude);

/**
 * @brief Reads and processes a .csv file to get the information
 * for the .kml file
 * @date 12/6/20
 * @return Returns the total number of items processed
 * @param inputFile ifstream to the .csv file
 * @param kmlFilename String that contains the name of the .kml file
 * to be made
 */
int readCSV(ifstream& inputFile, string kmlFilename);

#endif