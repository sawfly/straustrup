//
// Created by eugene on 16.11.18.
//

#include "DateTime.h"
#include "../utils/Utils.h"

DateTime DateTime::now() {
    std::time_t t = time(nullptr);
    this->cTime = *gmtime(&t);

    return *this;
}

std::string DateTime::format(std::string &format) {
    std::string f = format;
    this->parseFormat(format);
    std::string parsedFormat = "";
    auto parsedFormatsIterator = this->parsedFormats.begin();

    while (parsedFormatsIterator != this->parsedFormats.end()) {
        auto isFounded = this->mapOfFormattingMethods.find(*parsedFormatsIterator);

        if (isFounded != this->mapOfFormattingMethods.end()) {
            parsedFormat.append((this->*this->mapOfFormattingMethods[*parsedFormatsIterator])());
        } else {
            parsedFormat.append(*parsedFormatsIterator);
        }

        parsedFormatsIterator++;
    }
    return parsedFormat;
}

void DateTime::parseFormat(std::string &format) {
    std::vector<std::string> formatComponents;
    std::string outOfMaps;
    ul start = 0, len = 1;

    if (this->mapFormats.empty()) {
        this->composeFormats();
    }

    for (int i = 0; i < format.length(); ++i) {
        std::string character = format.substr(static_cast<ul>(i), 1);
        auto res = this->mapFormats.find(character);

        if (res != this->mapFormats.end()) {
            outOfMaps = format.substr(start, len);

            if (!outOfMaps.empty() && i > 0) {
                formatComponents.push_back(outOfMaps);
            }

            formatComponents.push_back(res->second);
            start = static_cast<ul>(i + 1);
            len = 0;
            continue;
        }

        len++;
    }

    outOfMaps = format.substr(start, len);

    if (!outOfMaps.empty()) {
        formatComponents.push_back(outOfMaps);
    }

    this->parsedFormats = formatComponents;
}

DateTime::DateTime() {
    this->formatNames = {
            DateTime::TYPE_YEAR,
            DateTime::TYPE_MONTH,
            DateTime::TYPE_DAY,
            DateTime::TYPE_HOUR,
            DateTime::TYPE_MINUTE,
            DateTime::TYPE_SECOND,
            DateTime::TYPE_MERIDIEM,
    };

    auto iteratorFormatNames = this->formatNames.begin();

    while (iteratorFormatNames != this->formatNames.end()) {
        auto *format = new Format();

        try {
            std::map<std::string, std::string> formatsMap = this->getFormats(*iteratorFormatNames);
            format->setFormats(formatsMap);
            this->formats[*iteratorFormatNames] = format;
        } catch (const std::invalid_argument &e) {
            std::cout << e.what() << '\n';
        }

        iteratorFormatNames++;
    }

    this->bindFormatsMethods();

    this->now();
}

std::map<std::string, std::string> DateTime::getFormats(std::string type) {
    if (type == DateTime::TYPE_YEAR) {
        return this->getYearFormats();
    } else if (type == DateTime::TYPE_MONTH) {
        return this->getMonthFormats();
    } else if (type == DateTime::TYPE_DAY) {
        return this->getDayFormats();
    } else if (type == DateTime::TYPE_HOUR) {
        return this->getHourFormats();
    } else if (type == DateTime::TYPE_MINUTE) {
        return this->getMinuteFormats();
    } else if (type == DateTime::TYPE_SECOND) {
        return this->getSecondFormats();
    } else if (type == DateTime::TYPE_MERIDIEM) {
        return this->getPartOfDayFormats();
    }

    throw std::invalid_argument("unsupported format type.");
}

std::map<std::string, std::string> DateTime::getYearFormats() {
    std::map<std::string, std::string> formats;
    formats["Y"] = "getFullYears";
    formats["y"] = "getShortYears";

    return formats;
}

std::map<std::string, std::string> DateTime::getMonthFormats() {
    std::map<std::string, std::string> formats;
    formats["M"] = "getZerofillMonth";
    formats["m"] = "getZerofreeMonth";

    return formats;
}

std::map<std::string, std::string> DateTime::getDayFormats() {
    std::map<std::string, std::string> formats;
    formats["D"] = "getZerofillDay";
    formats["d"] = "getZerofreeDay";

    return formats;
}

std::map<std::string, std::string> DateTime::getHourFormats() {
    std::map<std::string, std::string> formats;
    formats["C"] = "getZerofree24Hours";
    formats["H"] = "getZerofill24Hours";
    formats["c"] = "getZerofree12Hours";
    formats["h"] = "getZerofill12Hours";

    return formats;
}

std::map<std::string, std::string> DateTime::getMinuteFormats() {
    std::map<std::string, std::string> formats;
    formats["N"] = "getZerofillMinutes";
    formats["n"] = "getZerofreeMinutes";

    return formats;
}

std::map<std::string, std::string> DateTime::getSecondFormats() {
    std::map<std::string, std::string> formats;
    formats["S"] = "getZerofillSeconds";
    formats["s"] = "getZerofreeSeconds";

    return formats;
}

std::map<std::string, std::string> DateTime::getPartOfDayFormats() {
    std::map<std::string, std::string> formats;
    formats["p"] = "getAmPm";

    return formats;
}

const std::string DateTime::TYPE_YEAR = "year";
const std::string DateTime::TYPE_MONTH = "month";
const std::string DateTime::TYPE_DAY = "day";
const std::string DateTime::TYPE_HOUR = "hour";
const std::string DateTime::TYPE_MINUTE = "minute";
const std::string DateTime::TYPE_SECOND = "second";
const std::string DateTime::TYPE_MERIDIEM = "meridiem";

void DateTime::composeFormats() {
    auto formatsIterator = this->formats.begin();
    std::map<std::string, std::string> formats;

    while (formatsIterator != this->formats.end()) {
        auto formatsFromFormat = formatsIterator->second->getFormats();
        auto localFormatIterator = formatsFromFormat->begin();

        while (localFormatIterator != formatsFromFormat->end()) {
            this->mapFormats[localFormatIterator->first] = localFormatIterator->second;
            localFormatIterator++;
        }

        formatsIterator++;
    }
}

void DateTime::bindFormatsMethods() {
    this->mapOfFormattingMethods["getFullYears"] = &DateTime::getFullYears;
    this->mapOfFormattingMethods["getShortYears"] = &DateTime::getShortYears;
    this->mapOfFormattingMethods["getZerofreeMonth"] = &DateTime::getZerofreeMonth;
    this->mapOfFormattingMethods["getZerofillMonth"] = &DateTime::getZerofillMonth;
    this->mapOfFormattingMethods["getZerofreeDay"] = &DateTime::getZerofreeDay;
    this->mapOfFormattingMethods["getZerofillDay"] = &DateTime::getZerofillDay;
    this->mapOfFormattingMethods["getZerofree24Hours"] = &DateTime::getZerofree24Hours;
    this->mapOfFormattingMethods["getZerofill24Hours"] = &DateTime::getZerofill24Hours;
    this->mapOfFormattingMethods["getZerofree12Hours"] = &DateTime::getZerofree12Hours;
    this->mapOfFormattingMethods["getZerofill12Hours"] = &DateTime::getZerofill12Hours;
    this->mapOfFormattingMethods["getZerofreeMinutes"] = &DateTime::getZerofreeMinutes;
    this->mapOfFormattingMethods["getZerofillMinutes"] = &DateTime::getZerofillMinutes;
    this->mapOfFormattingMethods["getZerofreeSeconds"] = &DateTime::getZerofreeSeconds;
    this->mapOfFormattingMethods["getZerofillSeconds"] = &DateTime::getZerofillSeconds;
    this->mapOfFormattingMethods["getAmPm"] = &DateTime::getAmPm;
}

std::string DateTime::getFullYears() {
    return std::to_string(this->cTime.tm_year + this->ADD_TO_YEAR);
}

std::string DateTime::getShortYears() {
    std::string fullYear = this->getFullYears();
    us fullYearLength = static_cast<us>(fullYear.length());

    switch (fullYearLength) {
        case 1:
            return Utils::stringFill(fullYear, '0', 2);
        case 2:
            return fullYear;
        case 3:
            return fullYear.substr(1, 2);
        default:
            return fullYear.substr(2, 2);
    }
}

std::string DateTime::getZerofreeMonth() {
    return std::to_string(this->cTime.tm_mon + 1);
}

std::string DateTime::getZerofillMonth() {
    return Utils::stringFill(this->getZerofreeMonth(), '0', 2);
}

std::string DateTime::getZerofreeDay() {
    return std::to_string(this->cTime.tm_mday);
}

std::string DateTime::getZerofillDay() {
    return Utils::stringFill(this->getZerofreeDay(), '0', 2);
}

std::string DateTime::getZerofree24Hours() {
    return std::to_string(this->cTime.tm_hour);
}

std::string DateTime::getZerofill24Hours() {
    return Utils::stringFill(this->getZerofree24Hours(), '0', 2);
}

std::string DateTime::getZerofree12Hours() {
    return std::to_string(this->cTime.tm_hour > 12 ? 24 - std::stoi(this->getZerofree24Hours()): std::stoi(this->getZerofree24Hours()));
}

std::string DateTime::getZerofill12Hours() {
    return Utils::stringFill(this->getZerofree12Hours(), '0', 2);
}

std::string DateTime::getZerofreeMinutes() {
    return std::to_string(this->cTime.tm_min);
}

std::string DateTime::getZerofillMinutes() {
    return Utils::stringFill(this->getZerofreeMinutes(), '0', 2);
}

std::string DateTime::getZerofreeSeconds() {
    return std::to_string(this->cTime.tm_sec < 60 ? this->cTime.tm_sec : 0);
}

std::string DateTime::getZerofillSeconds() {
    return Utils::stringFill(this->getZerofreeSeconds(), '0', 2);
}

std::string DateTime::getAmPm() {
    if(this->cTime.tm_hour >= 0 && this->cTime.tm_hour < 12){
        return "AM";
    }

    return "PM";
}