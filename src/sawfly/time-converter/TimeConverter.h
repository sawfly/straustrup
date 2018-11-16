//
// Created by eugene on 16.11.18.
//
#include <string>

#ifndef STRAUSTRUP_TIMECONVERTER_H
#define STRAUSTRUP_TIMECONVERTER_H

/**
 *  Get seconds and (or) minutes and (or) hours and (or) days and generates string like "166 day(s) 16 hour(s)"
 */
class TimeConverter {
    int seconds = 0;
    int minutes = 0;
    int hours = 0;
    int days = 0;
    std::string normalizedPeriod = "";
    int normalizedPeriodLength = 0;
    enum types {
        SECONDS, MINUTES, HOURS
    };
    int type = SECONDS;

    void secondsToMinutes();

    void minutesToHours();

    void hoursToDays();

    void resetNormalizedPeriod();

public:
    TimeConverter();

    void setSeconds(const int &);

    void setMinutes(const int &);

    void setHours(const int &);

    std::string getNormalizedPeriod();

    void compute();
};

#endif //STRAUSTRUP_TIMECONVERTER_H
