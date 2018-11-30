//
// Created by eugene on 16.11.18.
//

#include "DateTime.h"

typedef std::string (DateTime::*FredMemFn)();  // Please do this!

DateTime DateTime::now() {
    std::time_t t = time(nullptr);
    this->cTime = *gmtime(&t);

    return *this;
}

std::string DateTime::format(std::string &format) {
//    std::map<std::string, std::regex> mapOfPatterns;
    std::string f = format;
//    std::cout << this->mapOfFormatPatterns["fullYear"];
//    for(auto i : this->mapOfFormatPatterns){
//        std::cout << this->mapOfFormatPatterns[i];
//    }


    auto it = this->mapOfFormatPatterns.begin();
    while (it != this->mapOfFormatPatterns.end()) {
//        std::cout << std::regex_replace(f.begin(), f.end()) << "\n";
        std::cout << it->first << ":\t" << it->second << "\n";
        it++;
    }
//    std::map<std::string, int>::iterator it = mapOfWords.begin();
//    while(it != mapOfWords.end())
//    {
//        std::cout<<it->first<<" :: "<<it->second<<std::endl;
//        it++;
//    }

    this->parseFormat(format);
    std::string parsedFormat = "";
    auto parsedFormatsIterator = this->parsedFormats.begin();
    while (parsedFormatsIterator != this->parsedFormats.end()) {
        std::cout << *parsedFormatsIterator << "\n";
        auto isFounded = this->mapOfFormattingMethods.find(*parsedFormatsIterator);
        if (isFounded != this->mapOfFormattingMethods.end()) {
            parsedFormat.append((this->*this->mapOfFormattingMethods[*parsedFormatsIterator])());
            std::cout << "!!!!" << (this->*this->mapOfFormattingMethods[*parsedFormatsIterator])() << "\n";
        } else {
            parsedFormat.append(*parsedFormatsIterator);
        }
        parsedFormatsIterator++;
    }
//    std::cout << "MF";
//    FredMemFn r = this->mapOfFormattingMethods["getFullYears"];
////    std::cout << r->*();
//    DateTime t;
//    std::cout << (this->*r)() << "\n";
//    std::cout << (this->*this->mapOfFormattingMethods["getFullYears"])() << "\n";
    return parsedFormat;
}

void DateTime::parseFormat(std::string &format) {
    std::vector<std::string> formatComponents;
    std::string outOfMaps;
    if (this->mapFormats.empty()) {
        this->composeFormats();
    }

    unsigned long int start = 0, len = 1;
    for (int i = 0; i < format.length(); ++i) {
        std::string character = format.substr(static_cast<unsigned long>(i), 1);
        auto res = this->mapFormats.find(character);
        if (res != this->mapFormats.end()) {
            outOfMaps = format.substr(start, len);
            if (!outOfMaps.empty() && i > 0) {
                formatComponents.push_back(outOfMaps);
            }
            formatComponents.push_back(res->second);
            start = static_cast<unsigned long>(i + 1);
            len = 0;
            continue;
        }
        len++;

//        ssv.push_back(ss.substr(start, len));
        std::cout << character << "\n";
    }
//    formatComponents
    outOfMaps = format.substr(start, len);

    if (!outOfMaps.empty()) {
        formatComponents.push_back(outOfMaps);
    }

    for (auto i = 0; i < formatComponents.size(); i++) {
        std::cout << "--->" << formatComponents[i] << "\n";
    }

    this->parsedFormats = formatComponents;


//    std::cout << "end!!!!!!!!!!!!!!!\n";
//    if (format == "Y") {
//        std::cout << "YEAR!!!\n";
//        std::cout << this->cTime.tm_year << "YEAR!!!\n";
////        std::cout << &this->formats["year"]->getSelectedFormat()->begin()->first;
//        Format yFormat  = *this->formats["year"];
//        std::map<std::string, std::string> selectedFormat = yFormat.getSelectedFormat();
//        auto iterator = *selectedFormat.begin();
////        iterator = *selectedFormat->begin();
//        std::cout << iterator.second;
//    }
//    std::cout << format;
}

DateTime::DateTime() {
    this->mapOfFormatPatterns = {
            {"fullYear",           "Y"},
            {"shortYear",          "y"},
            {"fullMonth",          "M"},
            {"shortMonth",         "m"},
            {"fullDay",            "D"},
            {"shortDay",           "d"},
            {"hours24",            "H"},
            {"hours24LeadingZero", "0H"},
            {"hours12",            "h"},
            {"hours12LeadingZero", "0h"},
            {"minutes",            "N"},
            {"minutesLeadingZero", "n"},
            {"seconds",            "S"},
            {"secondsLeadingZero", "s"},
    };
    this->formatNames = {
            DateTime::TYPE_YEAR,
            DateTime::TYPE_MONTH,
            DateTime::TYPE_DAY,
            DateTime::TYPE_HOUR,
            DateTime::TYPE_MINUTE,
            DateTime::TYPE_SECOND,
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

ul DateTime::getYear(std::string format) {
    return 0;
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
    formats["С"] = "getZerofree24Hours";
    formats["H"] = "getZerofill24Hours";
    formats["с"] = "getZerofree12Hours";
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

const std::string DateTime::TYPE_YEAR = "year";
const std::string DateTime::TYPE_MONTH = "month";
const std::string DateTime::TYPE_DAY = "day";
const std::string DateTime::TYPE_HOUR = "hour";
const std::string DateTime::TYPE_MINUTE = "minute";
const std::string DateTime::TYPE_SECOND = "second";

//const int DateTime::ADD_TO_YEAR = 1900;

void DateTime::composeFormats() {
    auto formatsIterator = this->formats.begin();
    std::map<std::string, std::string> formats;
    while (formatsIterator != this->formats.end()) {
        std::cout << formatsIterator->first << "\n";
        auto formatsFromFormat = formatsIterator->second->getFormats();
        auto localFormatIterator = formatsFromFormat->begin();
        while (localFormatIterator != formatsFromFormat->end()) {
            this->mapFormats[localFormatIterator->first] = localFormatIterator->second;
            localFormatIterator++;
        }
        formatsIterator++;
    }
}

std::string DateTime::getFullYears() {
    return std::to_string(this->cTime.tm_year + this->ADD_TO_YEAR);
}

void DateTime::bindFormatsMethods() {
    this->mapOfFormattingMethods["getFullYears"] = &DateTime::getFullYears;
    this->mapOfFormattingMethods["getShortYears"] = &DateTime::getShortYears;
}

std::string DateTime::getShortYears() {
    std::string fullYear = this->getFullYears();
    us fullYearLength = static_cast<us>(fullYear.length());
    switch (fullYearLength) {
        case 1:
            return "0" + fullYear;
        case 2:
            return fullYear;
        case 3:
            return fullYear.substr(1, 2);
        default:
            return fullYear.substr(2, 2);
    }
}

//std::map<std::string, std::regex> mapOfFormatPatterns = {
//        {"Yyyy",  "Y"}, {"yy", "y"},
//        {"mo",  "M"}, {"yy", "y"},
//};