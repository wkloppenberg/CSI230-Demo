/**
* @file util.cpp
* @brief  Week 10, C++ Review and Warmup from CSI140
*
* @author William Kloppenberg
* @assignment Lecture 10.1
* @date 11/7/2020
* @credits https://www.geeksforgeeks.org/camel-case-given-sentence/ for the camel case function
*/

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <numeric>
#include "util.h"
#include <algorithm>
using namespace std;

string randomElement(vector<string> vec){
    int randNum = rand() % 5;
    string element = vec.at(randNum);

    return element;
}

double sum(vector<double> vec){
    accumulate(vec.begin(), vec.end(), 0);
}

double avg(vector<double> vec){
    double sumOfVec = sum(vec); //the sum using the sum() function
    double average = sumOfVec / vec.size();

    return average;
}

double lowest(vector<double> vec){
    double minElm = *min_element(vec.begin(), vec.end());
}

string camelCase(string& refStr){
    int res = 0; //handles spaces
    refStr[0] = tolower(refStr[0]); //converts first letter to lowercase

    for (int i = 0; i < refStr.length(); i++){
        if (refStr[i] == ' '){ //if there is a space, convert to uppercase
            refStr[i + 1] = toupper(refStr[i + 1]);
        }
        else { //if no space, copy the character
            refStr[res++] = refStr[i];
        }
    }
    return refStr.substr(0, res); //return the converted string to main
}