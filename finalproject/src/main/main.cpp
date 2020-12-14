/**
 * @file main.cpp
 * @brief Driver code for the project
 * @author William Kloppenberg
 * @assignment Final Project
 * @date 12/10/20
 */
#include <iostream>
#include <pwd.h>
#include <unistd.h>
#include <libgen.h>
#include <limits.h>
#include "fileprocessing.h"
#include "logging.h"

using namespace std;

int main(int argc, char* argv[])
{
    int opt = 0; //For switch case
    bool optErr = true; //Error
    bool kmlFlag = false; //.kml file flag
    bool logFlag = false; //Log file flag
    //Values for the .kml and log files
    string kmlValue, logValue;

    while ((opt = getopt(argc, argv, "k:l:")) != EOF)
    {
        switch(opt)
        {
            case 'k': //.kml case
                kmlFlag = true;
                kmlValue = optarg;
                break;
            case 'l': //Log case
                logFlag = true;
                logValue = optarg;
                break;
            default:
                optErr = true; //Error
                break;
        }
    }

    //Output flag information
    cout << ".kml Flag: " << kmlFlag << " Log Flag: " << logFlag << endl;

    //.kml and log flags both exist
    if (kmlFlag && logFlag)
    {
        cout << "Flags have been set." << endl;
        //No option arguments entered for .kml or log
        if(logValue.empty() || kmlValue.empty())
        {
            cout << "ERROR: Option arguments have not been set." << endl;
            optErr = true;
        }
        else //Option arguments have been entered
        {
            ofstream writeLog; //ofstream to write to the log file
            writeLog.open(logValue, ios_base::app);
            //File exists
            if (writeLog)
            {
                //Message to write to log file
                string logMsg = "The .kml file is " + kmlValue + ", and the log file is " + logValue;
                //Call the log function to put this information into the log file
                log(logMsg, writeLog);
                optErr = false;
                //Close the ofstream
                writeLog.close();

                //ifstream to process the .csv file
                ifstream inputFile;
                inputFile.open(kmlValue);
                //File exists
                if (inputFile)
                {
                    //Total number of items processed from the readCSV function
                    int totalItems = readCSV(inputFile, kmlValue + ".kml");
                    //Close the ifstream
                    inputFile.close();

                    //The total number of processed items exceeds 0
                    if(totalItems != 0)
                    {
                        cout << "A total of " << totalItems << " items were processed." << endl;
                        optErr = false;
                    }
                    else
                    {
                        cout << "ERROR: No items were processed." << endl;
                        optErr = true;
                    }
                    
                }
                else //File doesn't exist or can't be opened
                {
                    cout << "ERROR: The file was not found or could not be opened." << endl;
                    optErr = true;
                }
                
            }
            else //File doesn't exist or can't be opened
            {
                cout << "ERROR: The file was not found or could not be opened." << endl;
                optErr = true;   
            }
        }
    }
    else //Flags haven't been set
    {
        cout << "ERROR: Flags have not been set." << endl;
        optErr = true;
    }

    //If optErr is set to true, end the program with a failure.
    if (optErr)
    {
        return EXIT_FAILURE;
    }

    //End the program successfully if there are no errors.
    return EXIT_SUCCESS;
}