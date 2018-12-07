//
// Created by eugene on 07.12.18.
//

#include "Utils.h"

std::string Utils::stringFill(std::string stringToFill, char what, unsigned long int toLength, bool feelBefore) {
    std::string fill = "";
    auto stringToFillLength = stringToFill.length();


    for (; stringToFillLength < toLength; toLength--) {
        fill += what;
    }

    if(feelBefore){
        return fill + stringToFill;
    }
    return stringToFill + fill;
}
