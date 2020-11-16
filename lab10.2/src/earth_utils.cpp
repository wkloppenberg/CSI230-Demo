/**
 * @file logger.h
 * @brief Lecture 10.2 sample code
 * implements google earth file utilities
 * @author William Kloppenberg
 * @assignment Lecture 10.2
 * @date 11/14/20
 */

#include "earth_utils.h"
#include <sstream>
#include <iostream> //test
using namespace std;

void writePlacemark(ofstream& kmlFile, string name, string latitude, string longitude)
{
    if (kmlFile)
    {
        kmlFile << "<Placemark>" << "\n";
        kmlFile << "<name>" << name << "</name>" << "\n";
        kmlFile << "<Point><coordinates>" << latitude << ',' << longitude << "</coordinates></Point>" << "\n";
        kmlFile << "</Placemark>" << "\n";
    }
}

int processCSV(ifstream& inFile, string kmlFileName)
{
    string strCountry, strCapital, strLat, strLong;
    string strLine; //the entire line in a csv file
    int recordCount = 0;
    
    //set records written to 0
    //bail returning records if inFIle doesn't exist
    //if it does exist
    //create the kmlFIle
    //write header out
    //read each line in inFile (skip first)
    if (inFile)
    {
        ofstream kmlFile(kmlFileName);
        kmlFile << KMLHEADER1 << "\n";
        kmlFile << KMLHEADER2 << "\n";
        kmlFile << KMLDOCSTART << "\n";

        //skip past first line
        getline(inFile, strLine);
        //cout << strLine << endl; //debug
        //loop through all the other lines
        while (getline(inFile, strLine))
        {
            stringstream s_stream(strLine);
            getline(s_stream, strCountry, ',');
            getline(s_stream, strCapital, ',');
            getline(s_stream, strLat, ',');
            getline(s_stream, strLong, ',');

            string strName = strCountry + ", " + strCapital;

            cout << strCountry << " ~ " << strCapital << " ~ " << strLat << " ~ " << strLong << endl;

            writePlacemark(kmlFile, strName, strLat, strLong);
            recordCount++;
        }

        kmlFile << KMLDOCEND << "\n";
        kmlFile << KMLFOOTER << "\n";
        kmlFile.close();

        return recordCount;
    }
    //call WritePlacemark to create a record
    //increment record count
    //write any footer out
    //return record count
}