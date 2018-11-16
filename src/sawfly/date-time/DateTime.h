//
// Created by eugene on 16.11.18.
//

#include <ctime>
#include <iostream>
#include <regex>

#ifndef STRAUSTRUP_DATETIME_H
#define STRAUSTRUP_DATETIME_H

typedef unsigned short us;
typedef unsigned long ul;
/**
 * Formats
 *  Y/y
 *  M/m
 *  D/d
 *  H/h
 *  Mi/mi
 *  S/s
 *  AP
 */
class DateTime {
public:
    DateTime();
    DateTime now();
    std::string format(std::string &);


private:
    ul year;
    us month;
    us day;
    us hours;
    us minutes;
    us seconds;
    std::tm cTime;
    std::map<std::string, std::regex> mapOfFormatPatterns;

    void parseFormat(std::string &format);
};


#endif //STRAUSTRUP_DATETIME_H
