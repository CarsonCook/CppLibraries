//
// Created by cookc on 2018-05-12.
//

#include "Number.h"

BadNumberStringException::BadNumberStringException(int c, const std::string &m) {
    str = m;
    pos = c;
}

const char *BadNumberStringException::what() const noexcept {
    return std::string(std::string("Tried to create a Number with a bad string: At position ") + std::to_string(pos) +
                       " in string: " + str).c_str();
}