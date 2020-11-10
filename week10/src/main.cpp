/**
* @file main.cpp
* @brief  Week 10, C++ Review and Warmup from CSI140
*
* @author William Kloppenberg
* @assignment Lecture 10.1
* @date 11/7/2020
* 
*/

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <numeric>
#include <algorithm>
#include "util.h"

using namespace std;

int main()
{
    srand (time(0)); //random seed
    
    vector <string> strVec;
    strVec.push_back("A");
    strVec.push_back("B");
    strVec.push_back("C");
    strVec.push_back("D");
    strVec.push_back("E");

    cout << "String vector elements: ";
    for (string s: strVec){
        cout << s << ", ";
    }

    cout << "\n";

    cout << "Random elements from string vector: ";
    cout << randomElement(strVec) << ", ";
    cout << randomElement(strVec);

    cout << "\n";

    vector <double> dubVec;
    dubVec.push_back(0.5);
    dubVec.push_back(1.0);
    dubVec.push_back(1.5);
    dubVec.push_back(2.0);
    dubVec.push_back(2.5);

        cout << "Double vector elements: ";
    for (double d: dubVec){
        cout << d << ", ";
    }

    cout << "\n";

    cout << "Sum of elements in double vector: ";
    cout << sum(dubVec) << endl;
    cout << "Average of elements in double vector: ";
    cout << avg(dubVec) << endl;
    cout << "Smallest element in double vector: ";
    cout << lowest(dubVec) << endl;

    string testString = "A little bird with a yellow bill";
    cout << "String to be converted to camel case: " << testString << endl;
    cout << "String converted to camel case: " << camelCase(testString) << endl;

    return EXIT_SUCCESS;
}