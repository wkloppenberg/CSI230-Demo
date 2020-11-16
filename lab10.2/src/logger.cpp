/**
 * @file logger.cpp
 * @brief Lecture 10.2 sample code
 * handles the declaration of all logging functionality
 * @author William Kloppenberg
 * @assignment Lecture 10.2
 * @date 11/12/20
 */

#include <iostream>
#include <pwd.h>
#include <unistd.h>
#include <libgen.h>
#include <limits.h>
#include "logger.h"

using namespace std;

bool log(string msg, string programName, ofstream& logFile)
{
    string strTime;

    //get the time
    time_t logTime = time(0);
    strTime = ctime(&logTime);

    //time off newline
    int timeSize = strTime.size();
    if (timeSize)
    {
        strTime[timeSize - 1] = ' ';
    }

    //get program name (I couldn't get this to work in this file and couldn't find any information)
    //int argc;
    //char *argv[0];
    //string strProgramName = basename(argv[0]);
    //get pid
    pid_t pid = getpid();
    //get hostname
    char hostname[HOST_NAME_MAX];
    int strHostName = gethostname(hostname, HOST_NAME_MAX);

    if (logFile)
    {
        //write log
        logFile << strTime << strHostName << " " << "[" << pid << "]: " << msg << endl;
        return true;
    }
    else
    {
        return false;
    }
    
}