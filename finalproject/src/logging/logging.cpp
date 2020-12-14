/**
 * @file logging.cpp
 * @brief Log function implementation
 * @author William Kloppenberg
 * @assignment Final Project
 * @date 12/8/20
 */
#include <iostream>
#include <pwd.h>
#include <unistd.h>
#include <libgen.h>
#include <limits.h>
#include "logging.h"

using namespace std;

bool log(string logMsg, ofstream& logFile)
{
    //Get the current time and date
    time_t logTime = time(0);
    string strTime = ctime(&logTime);
    //Time newline
    int timeSize = strTime.size();
    if (timeSize)
    {
        strTime[timeSize - 1] = ' ';
    }

    //Get the process ID (PID)
    pid_t pid = getpid();

    //Get the hostname
    char hostname[HOST_NAME_MAX];
    int strHostname = gethostname(hostname, HOST_NAME_MAX);

    //The log file exists
    if(logFile)
    {
        //Write out the log to the log file
        logFile << strTime << " " << strHostname << " " << "[" << pid << "]: " << logMsg << endl;

        return true; //Log file written successfully
    }
    else
    {
        return false; //Log file does not exist
    }
    
}