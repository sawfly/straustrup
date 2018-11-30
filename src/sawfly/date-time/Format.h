//
// Created by eugene on 26.11.18.
//

#include <iostream>
#include <map>
#include <vector>

#ifndef STRAUSTRUP_FORMATS_H
#define STRAUSTRUP_FORMATS_H


class Format {
public:
    Format();

    Format *setFormats(std::map<std::string, std::string> &);

    std::map<std::string, std::string> *getFormats();

    void select(std::string format = "");

    std::map<std::string, std::string> getSelectedFormat();

private:
    std::map<std::string, std::string> formats;
    std::string selectedFormat;
};


#endif //STRAUSTRUP_FORMATS_H
