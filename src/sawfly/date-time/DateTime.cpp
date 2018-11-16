//
// Created by eugene on 16.11.18.
//

#include "DateTime.h"

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
        std::cout << std::regex_replace(f.begin(), f.end()) << "\n";
        it++;
    }
//    std::map<std::string, int>::iterator it = mapOfWords.begin();
//    while(it != mapOfWords.end())
//    {
//        std::cout<<it->first<<" :: "<<it->second<<std::endl;
//        it++;
//    }

    this->parseFormat(format);
    return std::__cxx11::string("asdad");
}

void DateTime::parseFormat(std::string &format) {
    std::cout << format;
}

DateTime::DateTime() {
    this->mapOfFormatPatterns = {
            {"fullYear",           std::regex("Y")},
            {"shortYear",          std::regex("y")},
            {"fullMonth",          std::regex("Y")},
            {"shortMonth",         std::regex("y")},
            {"fullDay",            std::regex("Y")},
            {"shortDay",           std::regex("y")},
            {"hours24",            std::regex("Y")},
            {"hours24LeadingZero", std::regex("Y")},
            {"hours12",            std::regex("y")},
            {"hours12LeadingZero", std::regex("y")},
            {"minutes",            std::regex("Y")},
            {"minutesLeadingZero", std::regex("y")},
            {"seconds",            std::regex("Y")},
            {"secondsLeadingZero", std::regex("y")},
    };
}

//std::map<std::string, std::regex> mapOfFormatPatterns = {
//        {"Yyyy",  "Y"}, {"yy", "y"},
//        {"mo",  "M"}, {"yy", "y"},
//};


