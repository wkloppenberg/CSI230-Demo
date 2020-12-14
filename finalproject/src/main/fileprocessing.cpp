/**
 * @file fileprocessing.cpp
 * @brief Implements the functions in fileprocessing.h
 * @author William Kloppenberg
 * @assignment Final Project
 * @date 12/6/20
 */
#include "fileprocessing.h"
#include <sstream>

using namespace std;

void newPlacemark(ofstream& kmlFile, string name, string latitude, string longitude)
{
    //The .kml file exists
    if (kmlFile)
    {
        //Write the necessary information
        kmlFile << "<Placemark>" << "\n";
        kmlFile << "<name>" << name << "</name>" << "\n";
        kmlFile << "<Point><coordinates>" << latitude << ',' << longitude << "</coordinates></Point>" << "\n";
        kmlFile << "</Placemark>" << "\n";
    }
}

int readCSV(ifstream& inputFile, string kmlFilename)
{
    //Information to get from .csv file
    string strName, strLatitude, strLongitude;
    string csvLine; //Whole line in the .csv file
    int itemNum = 0; //Total number of items processed

    //The .csv file exists
    if (inputFile)
    {
        //Write to the .kml file
        ofstream kmlFile(kmlFilename);
        //Headers and start of the .kml document
        kmlFile << KMLHEAD1 << "\n";
        kmlFile << KMLHEAD2 << "\n";
        kmlFile << KMLSTART << "\n";

        getline(inputFile, csvLine); //Skip the .csv file's first line
        //Loop through the rest of the .csv file
        while (getline(inputFile, csvLine))
        {
            //stringstream to extract information from .csv file
            stringstream strStream(csvLine);
            //Get information separated by commas
            getline(strStream, strName, ',');
            getline(strStream, strLatitude, ',');
            getline(strStream, strLongitude, ',');

            //Call the newPlacemark function to write placemarks to the
            //.kml file using the extracted information
            newPlacemark(kmlFile, strName, strLatitude, strLongitude);

            itemNum++; //Increment total number of items processed
        }

        //End of the .kml document and footer
        kmlFile << KMLEND << "\n";
        kmlFile << KMLFOOT << "\n";
        kmlFile.close(); //Close the .kml file

        return itemNum; //Return the total
    }
}