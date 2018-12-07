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
 * Formats:
 *  - Years:
 *    Y => 2018
 *    y => 18
 *  - Months:
 *    M => 06
 *    m => 6
 *  - Days:
 *    D => 07
 *    d => 7
 *  - Hours:
 *    H => 08; 20
 *    C => 8; 20
 *    h => 08
 *    c => 8
 *  - Minutes:
 *    N => 08
 *    n => 8
 *  - Seconds:
 *    S => 08
 *    s => 8
 *  - After/Before Noon:
 *    p => AM||PM
 */
class DateTime {
public:
    /**
     * Constructor
     */
    DateTime();

    /**
     *
     * @return
     */
    DateTime now();

    /**
     * Gets format string and returns time as string according to format
     * std::string @return
     */
    std::string format(std::string &);

private:
    /**
     * Constants for binding formats
     */
    static const std::string TYPE_YEAR;
    static const std::string TYPE_MONTH;
    static const std::string TYPE_DAY;
    static const std::string TYPE_HOUR;
    static const std::string TYPE_MINUTE;
    static const std::string TYPE_SECOND;
    static const std::string TYPE_MERIDIEM;

    /**
     * Conjunction to get normal year
     */
    const int ADD_TO_YEAR = 1900;

    /**
     * struct tm
     */
    std::tm cTime;

    /**
     * keeps Format objects
     */
    std::map<std::string, Format *> formats;

    std::map<std::string, std::string> mapFormats;
    std::vector<std::string> formatNames;
    std::vector<std::string> parsedFormats;
    std::map<std::string, std::string (DateTime::*)()> mapOfFormattingMethods;

    /**
     * Calls methods according to type
     * @param type
     * @return
     */
    std::map<std::string, std::string> getFormats(std::string type);

    std::map<std::string, std::string> getYearFormats();

    std::map<std::string, std::string> getMonthFormats();

    std::map<std::string, std::string> getDayFormats();

    std::map<std::string, std::string> getHourFormats();

    std::map<std::string, std::string> getMinuteFormats();

    std::map<std::string, std::string> getSecondFormats();

    std::map<std::string, std::string> getPartOfDayFormats();

    void bindFormatsMethods();

    void composeFormats();

    /**
     * parses format string
     * @param format
     */
    void parseFormat(std::string &format);

    std::string getFullYears();

    std::string getShortYears();

    std::string getZerofillMonth();

    std::string getZerofreeMonth();

    std::string getZerofillDay();

    std::string getZerofreeDay();

    std::string getZerofree24Hours();

    std::string getZerofill24Hours();

    std::string getZerofree12Hours();

    std::string getZerofill12Hours();

    std::string getZerofreeMinutes();

    std::string getZerofillMinutes();

    std::string getZerofreeSeconds();

    std::string getZerofillSeconds();

    std::string getAmPm();


};


#endif //STRAUSTRUP_DATETIME_H
