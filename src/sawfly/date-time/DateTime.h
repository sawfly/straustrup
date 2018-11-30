//
// Created by eugene on 16.11.18.
//

#include <ctime>
#include <iostream>
#include <regex>
#include "Format.h"

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

    ul getYear(std::string format = "Y");

    us getMonth(std::string format = "M");

    ul getDay(std::string format = "D");

    ul getHours(std::string format = "H");

    ul getMinutes(std::string format = "N");

    ul getSeconds(std::string format = "S");

    std::map<std::string, std::string> getFormats(std::string type);


private:
    ul year;
    us month;
    us day;
    us hours;
    us minutes;
    us seconds;
    std::tm cTime;
    std::map<std::string, std::string> mapOfFormatPatterns;
    std::map<std::string, std::string> mapOfYearFormatsPatterns;
    std::map<std::string, std::string> mapOfMonthFormatsPatterns;
    std::map<std::string, std::string> mapOfDayFormatsPatterns;
    std::map<std::string, std::string> mapOfDaysFormatsPatterns;
    std::map<std::string, Format *> formats;
    std::map<std::string, std::string> mapFormats;
    std::vector<std::string> formatNames;
    std::vector<std::string> parsedFormats;
    std::map<std::string, std::string (DateTime::*)()> mapOfFormattingMethods;

    void parseFormat(std::string &format);

    std::map<std::string, std::string> getYearFormats();

    std::map<std::string, std::string> getMonthFormats();

    std::map<std::string, std::string> getDayFormats();

    std::map<std::string, std::string> getHourFormats();

    std::map<std::string, std::string> getMinuteFormats();

    std::map<std::string, std::string> getSecondFormats();

    void composeFormats();

    void bindFormatsMethods();

    std::string getFullYears();
    std::string getShortYears();

    static const std::string TYPE_YEAR;
    static const std::string TYPE_MONTH;
    static const std::string TYPE_DAY;
    static const std::string TYPE_HOUR;
    static const std::string TYPE_MINUTE;
    static const std::string TYPE_SECOND;
    const int ADD_TO_YEAR = 1900;

};


#endif //STRAUSTRUP_DATETIME_H
