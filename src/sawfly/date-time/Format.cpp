//
// Created by eugene on 26.11.18.
//

#include "Format.h"

Format::Format() {

}

Format *Format::setFormats(std::map<std::string, std::string> &formats) {
    this->formats = formats;
    this->select();

    return this;
}

std::map<std::string, std::string> *Format::getFormats() {
    return &this->formats;
}

void Format::select(std::string format) {
    auto formatsIterator = this->formats.begin();

    if(format.empty()){
        this->selectedFormat = formatsIterator->first;
        return;
    }

    this->formats.find(format);

    if(formatsIterator == this->formats.end()){
        this->selectedFormat = formatsIterator->first;
    }
}

std::map<std::string, std::string> Format::getSelectedFormat() {
    auto formatsIterator = this->formats.begin();
    this->formats.find(this->selectedFormat);
    std::map<std::string, std::string> selected;
    selected[formatsIterator->first] = formatsIterator->second;

    return selected;
}
