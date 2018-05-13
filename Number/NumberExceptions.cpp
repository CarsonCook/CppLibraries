//
// Created by cookc on 2018-05-12.
//

#include "Number.h"

BadNumberStringException::BadNumberStringException(int c, const std::string &m) : pos{c}, detail{m} {
    message = std::string(
            std::string("Tried to create a Number with a bad string: At position ") + std::to_string(pos) +
            " in string: " + detail);
}

const char *BadNumberStringException::what() const noexcept {
    return message.c_str();
}

BadSubscriptAccess::BadSubscriptAccess(const Number &val, const Number &i, int b, const std::string &det) : value{val},
                                                                                                            index{i},
                                                                                                            base{b},
                                                                                                            detail{det} {

    message = (std::string("Accessing ") + (std::string) value + std::string(" at ") + (std::string) index +
               std::string(" with base ") +
               std::to_string(base) + std::string(" gives error: ") + detail);
}

const char *BadSubscriptAccess::what() const noexcept {
    return message.c_str();
}