#include <iostream>
#include <string>
#include <cstring>

#include "sawfly/time-converter/TimeConverter.h"


int main() {
    const int COMPONENTS = 10000;
    const int HOURS_FOR_100 = 80;
    int streams = 2;
    int present = 0;
    int left = COMPONENTS - present;
    int production = 100;
    int leftTime = left / production * HOURS_FOR_100 / streams;

    TimeConverter tc;
    tc.setHours(leftTime);
    tc.compute();

    std::cout << tc.getNormalizedPeriod();
    std::cout << std::endl;
    std::cout << leftTime;

    return 0;
}

