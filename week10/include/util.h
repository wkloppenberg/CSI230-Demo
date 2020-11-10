/**
* @file util.h
* @brief  Week 10, C++ Review and Warmup from CSI140
*
* @author William Kloppenberg
* @assignment Lecture 10.1
* @date 11/7/2020
* 
*/

#ifndef UTIL_H
#define UTIL_H
using namespace std;

/**
 * @brief returns a random element from a vector
 * @date 11/7/2020
 * @param vector<string> vec, the vector containing the elements
 * @return string element, the random element
 */
string randomElement(vector<string> vec);

/**
 * @brief returns the sum of elements in a vector
 * @date 11/8/2020
 * @param vector<double> vec, the vector containing the elements
 * @return the sum of elements using accumulate
 */
double sum(vector<double> vec);

/**
 * @brief returns the average of elements in a vector
 * @date 11/8/2020
 * @param vector<double> vec, the vector containing the elements
 * @return double average, the sum of the vector's elements divided by its size
 */
double avg(vector<double> vec);

/**
 * @brief returns the lowest element in a vector
 * @date 11/9/2020
 * @param vector<double> vec, the vector containing the elements
 * @return double minElm, the smallest element using min_element
 */
double lowest(vector<double> vec);

/**
 * @brief converts a string to camel case
 * @date 11/9/2020
 * @param string& refStr, the referenced string
 * @return the string converted to camel case
 */
string camelCase(string& refStr);

#endif