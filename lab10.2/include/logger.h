/**
 * @file logger.h
 * @brief Lecture 10.2 sample code
 * handles the declaration of all logging functionality
 * @author William Kloppenberg
 * @assignment Lecture 10.2
 * @date 11/12/20
 */
#ifndef LOGGER_H
#define LOGGER_H
#include <string>
#include <fstream>
using namespace std;

/**
 * @brief creates a discrete syslog message
 * @date 11/12/20
 * @return returns a boolean indicating message was written ok
 * @param msg string containing syslog message
 * @param programName string containing the program name
 * @param logFile ofstream reference, validation expected
 */

bool log(string msg, string programName, ofstream& logFile);

#endif