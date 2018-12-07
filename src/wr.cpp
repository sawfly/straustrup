#include <iostream>
#include <string>
#include <cstring>

#include "sawfly/time-converter/TimeConverter.h"
#include "sawfly/date-time/DateTime.h"
#include "sawfly/utils/Utils.h"


int main() {
    const int COMPONENTS = 10000;
    const int HOURS_FOR_100 = 80;
    int streams = 3;
    int present = 1600;
    int left = COMPONENTS - present;
    int production = 100;
    int leftTime = left / production * HOURS_FOR_100 / streams;

    TimeConverter tc;
    tc.setHours(leftTime);
    tc.compute();

    std::cout << tc.getNormalizedPeriod();
    std::cout << std::endl;
    std::cout << leftTime;

    DateTime dateTime;
    std::string f = "Y--p";
    std::cout << dateTime.now().format(f) << "THE END!\n";

    std::cout << Utils::stringFill("string", '_', 19, false);
    return 0;
    std::string ss = "rstring to parsei_";
    std::string *sss = &ss;
    std::vector <std::string> ssv;
    std::map <std::string, std::string> myMap;
    myMap["i_"] = "{I_I}";
    myMap["i"] = "{IiI}";
    myMap["r"] = "{RrR}";

    auto ttest = ss.find("i_");

    std::cout << ttest;

    auto mapIterator = myMap.begin();
    while (mapIterator != myMap.end()){
        std::cout << mapIterator->first << "\n";
        mapIterator++;
    }
        return 0;

//    auto stringIterator = sss.begin();
    auto vectorIterator = ssv.begin();
    //symbol_by_symbol
    unsigned long int start = 0, len = 1;
    std::string outOfMaps;
    for (int i=0; i < ss.length(); ++i)
    {
        std::string tt = ss.substr(i, 1);
        auto res = myMap.find(tt);
        if(res != myMap.end()){
            outOfMaps = ss.substr(start, len);
            if(!outOfMaps.empty()){
                ssv.push_back(outOfMaps);
            }
            ssv.push_back(res->second);
            start = static_cast<unsigned long>(i + 1);
            len = 0;
        } else {
            len++;
        }
//        ssv.push_back(ss.substr(start, len));
        std::cout << tt << "\n";
    }
    outOfMaps = ss.substr(start, len);
    if(!outOfMaps.empty()){
        ssv.push_back(outOfMaps);
    }
//    ssv[index] = outOfMaps;

    auto it = ssv.begin();
    while(it != ssv.end()){
        std::cout << *it << "\n";
        it++;
    }
//    while (stringIterator != sss.end()){
//        std::cout <<
//        typeof(*stringIterator)/* << "\n"*/;
////        std::string symbol = stringIterator;
////        const char * symbol = stringIterator->c_str();
////        auto mapIter = myMap.find(symbol);
////        if(mapIter) {
////
////        }
//        stringIterator++;
//    }

//    sss.find()


//    std::cout << sss << "\n";

    return 0;
}

