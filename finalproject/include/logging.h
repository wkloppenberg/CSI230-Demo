/**
 * @file logging.h
 * @brief Log function declarations
 * @author William Kloppenberg
 * @assignment Final Project
 * @date 12/8/20
 */
#ifndef LOGGING_H
#define LOGGING_H
#include <string>
#include <fstream>

using namespace std;

/**
 * @brief Creates a placemark for the .kml file
 * @date 12/8/20
 * @return Returns a boolean that indicates the log message was created
 * @param logMsg String that contains the log's message
 * @param logFile ofstream to the log file
 */
bool log(string logMsg, ofstream& logFile);

#endif