//
// Created by eugene on 16.11.18.
//

#include "TimeConverter.h"

/**
 *
 * @param seconds
 */
void TimeConverter::setSeconds(const int &seconds) {
    this->seconds = seconds;
    this->type = HOURS;
    this->resetNormalizedPeriod();
}

void TimeConverter::setMinutes(const int &minutes) {
    this->minutes = minutes;
    this->type = MINUTES;
    this->resetNormalizedPeriod();
}
/**
 *
 * @param hours
 */
void TimeConverter::setHours(const int &hours) {
    this->hours = hours;
    this->type = HOURS;
    this->resetNormalizedPeriod();
}
/**
 *
 */
TimeConverter::TimeConverter() {

}
/**
 *
 * @return
 */
std::string TimeConverter::getNormalizedPeriod() {
    if(this->normalizedPeriodLength) {
        return this->normalizedPeriod;
    }

    bool addSpace = false;

    if (this->days) {
        this->normalizedPeriod += std::to_string(this->days) + " day(s)",
                addSpace = true;
    }
    if(this->hours){
        this->normalizedPeriod += addSpace ? " " : "";
        addSpace = true;
        this->normalizedPeriod += std::to_string(this->hours) + " hour(s)";
    }
    if(this->minutes){
        this->normalizedPeriod += addSpace ? " " : "";
        addSpace = true;
        this->normalizedPeriod += std::to_string(this->minutes) + " minutes(s)";
    }
    if(this->seconds){
        this->normalizedPeriod += addSpace ? " " : "";
        this->normalizedPeriod += std::to_string(this->seconds) + " seconds(s)";
    }

    this->normalizedPeriodLength = static_cast<int>(this->normalizedPeriod.length());

    return this->getNormalizedPeriod();
}
/**
 *
 */
void TimeConverter::compute() {
    switch (this->type) {
        case SECONDS:
            this->secondsToMinutes();
        case MINUTES:
            this->minutesToHours();
        case HOURS:
            this->hoursToDays();
        default:
            break;
    }
}

/**
 *
 */
void TimeConverter::secondsToMinutes() {
    int minutesInSeconds = this->seconds / 60;
    this->seconds -= minutesInSeconds * 60;
    this->minutes += minutesInSeconds;
}
/**
 *
 */
void TimeConverter::minutesToHours() {
    int hoursInMinutes = this->minutes / 60;
    this->minutes -= hoursInMinutes * 60;
    this->hours += hoursInMinutes;
}

/**
 *
 */
void TimeConverter::hoursToDays() {
    int daysInHours = this->hours / 24;
    this->hours -= daysInHours * 24;
    this->days += daysInHours;
}
/**
 *
 */
void TimeConverter::resetNormalizedPeriod() {
    if(this->normalizedPeriodLength) {
        this->normalizedPeriod = "";
        this->normalizedPeriodLength = 0;
    }
}