//
// Created by cookc on 2018-05-06.
//

#include "Number.h"

//================================
//      CONVERSION OPERATORS
//================================

Number::operator long long() const {
    long long num{0};
    int power{0};
    for (auto c : digits) {
        int n = Number::charToInt(c);
        for (int i{0}; i < power; ++i) {
            n *= 10;
        }
        num += n;
        ++power;
    }
    if (!isPositive) {
        num = -num;
    }
    return num;
}

Number::operator bool() const {
    return this != nullptr;
}

//================================
//      STREAM OPERATORS
//================================

std::ostream &operator<<(std::ostream &os, const Number &num) {
    os << (num.isPositive ? "" : "-");
    std::vector<char> digits = num.digits;
    for (int i = num.digits.size() - 1; i >= 0; --i) {
        os << digits[i];
    }
    return os;
}

std::istream &operator>>(std::istream &is, Number &num) {
    bool isPos;
    is >> isPos;
    std::string decLine, digLine;
    std::getline(std::cin, digLine);
    std::getline(std::cin, decLine);
    std::vector<char> dig(digLine.begin(), digLine.end());
    std::vector<char> dec(decLine.begin(), decLine.end());
    num = Number(dig, dec, isPos);
}

//================================
//      ARITHMETIC OPERATORS
//================================

Number operator+(const Number &lhs, const Number &rhs) {
    //if 1 is zero, result is value of the one that isn't zero
    if (lhs.isZero() || rhs.isZero()) {
        return lhs.isZero() ? Number{rhs} : Number{lhs};
    }

    //else have work to do
    if (!lhs.isPositive && !rhs.isPositive) {
        return Number(lhs.computePosAddDigits(rhs), false);
    } else if (lhs.isPositive && rhs.isPositive) {
        return Number(lhs.computePosAddDigits(rhs), true);
    } else {
        //one positive, one negative - turn into (original positive) - (positive of original negative)
        Number tempL{lhs};
        Number tempR{rhs};
        if (lhs.isPositive) {
            tempR.isPositive = true;
            return tempL - tempR;
        } else {
            tempL.isPositive = true;
            return tempR - tempL;
        }
    }
}

Number operator-(const Number &lhs, const Number &rhs) {
    //if equal, return zero.
    //if both zero, return zero. if one zero, return other value, maybe switch to negative
    if (lhs == rhs || (lhs.isZero() && rhs.isZero())) {
        return Number{0};
    } else if (lhs.isZero()) {
        return Number{rhs};
    } else if (rhs.isZero()) {
        return Number{lhs};
    }
    if (!rhs.isPositive) {
        Number r{rhs};
        r.isPositive = true;
        return lhs + r;
    } else if (!lhs.isPositive && rhs.isPositive) {
        Number l{lhs};
        l.isPositive = true;
        Number temp{l + rhs};
        temp.isPositive = false;
        return temp;
    }
    //return the difference, negative if rhs > rhs. By here, can't be -
    return Number{lhs.findDiff(rhs), lhs > rhs};
}

Number operator*(const Number &lhs, const Number &rhs) {
    //if either zero, return 0
    if (lhs.isZero() || rhs.isZero()) {
        return Number{0};
    }
    Number res{0};
    for (Number i{1}; i <= lhs; ++i) {
        res += rhs;
    }
    return res;
}

//TODO make this much more efficient - * is slow as hell and * is used WITHIN the for loop
Number operator/(const Number &lhs, const Number &rhs) {
    //special cases
    if (rhs.isZero()) {
        throw std::overflow_error("dividing by zero");
    }
    if (rhs == 1) {
        return Number{lhs};
    }
    if (lhs.isZero()) {
        return 0;
    }
    for (Number i{1}; i <= lhs; ++i) {
        if (i * rhs == lhs) {
            return i;
        }
    }
    return 0; //undefined
}

//================================
//      BOOLEAN OPERATORS
//================================

bool operator==(const Number &lhs, const Number &rhs) {
    if (lhs.isPositive != rhs.isPositive) {
        return false;
    }
    if (lhs.decDigits != rhs.decDigits) {
        return false;
    }
    return lhs.digits == rhs.digits;
}

bool operator!=(const Number &lhs, const Number &rhs) {
    return !(lhs == rhs);
}

bool operator>(const Number &lhs, const Number &rhs) {
    //check sign first
    if (lhs.isPositive != rhs.isPositive) {
        return lhs.isPositive; //not the same, so if lhs positive, lhs > rhs. if lhs negative, rhs > lhs.
    }
    int lLength = lhs.digits.size();
    int rLength = rhs.digits.size();
    if (lLength != rLength) {
        //return longer if positive, shorter if negative - at this point lhs and rhs have same sign
        if (lhs.isPositive) {
            return lLength > rLength;
        } else {
            return lLength < rLength;
        }
    }
    return lhs.absIsBigger(rhs);
}

bool operator>=(const Number &lhs, const Number &rhs) {
    return lhs > rhs || lhs == rhs;
}

bool operator<(const Number &lhs, const Number &rhs) {
    return !(lhs > rhs || lhs == rhs);
}

bool operator<=(const Number &lhs, const Number &rhs) {
    return !(lhs > rhs);
}

//================================
//      ASSIGNMENT OPERATORS
//================================

Number &Number::operator=(const Number &other) {
    if (&other == this) {
        return *this;
    }
    (*this).isPositive = other.isPositive;
    (*this).digits = other.digits;
    (*this).decDigits = other.decDigits;
    return *this;
}

Number &Number::operator+=(const Number &other) {
    auto *temp = new Number{*this + other};
    this->isPositive = temp->isPositive;
    this->digits = temp->digits;
    this->decDigits = temp->decDigits;
    return *this;
}

Number &Number::operator-=(const Number &other) {
    auto *temp = new Number{*this - other};
    this->isPositive = temp->isPositive;
    this->digits = temp->digits;
    this->decDigits = temp->decDigits;
    this->isPositive = temp->isPositive;
    this->digits = temp->digits;
    this->decDigits = temp->decDigits;
    return *this;
}

Number &Number::operator*=(const Number &other) {
    Number *temp = new Number{*this * other};
    this->isPositive = temp->isPositive;
    this->digits = temp->digits;
    this->decDigits = temp->decDigits;
    return *this;
}

Number &Number::operator/=(const Number &other) {
    auto *temp = new Number{*this / other};
    this->isPositive = temp->isPositive;
    this->digits = temp->digits;
    this->decDigits = temp->decDigits;
    return *this;
}

Number &Number::operator%=(const Number &other) {
    //  auto *temp = new Number{*this % other};
    /* this->isPositive=temp->isPositive;
     this->digits=temp->digits;
     this->decDigits=temp->decDigits;
     return *this;*/
}

Number &Number::operator++() {
    auto *temp = new Number{*this + 1};
    this->isPositive = temp->isPositive;
    this->digits = temp->digits;
    this->decDigits = temp->decDigits;
    return *this;
}

const Number Number::operator++(int) {
    Number copy = *this;
    ++(*this);
    return copy;
}

Number &Number::operator--() {
    auto *temp = new Number{*this - 1};
    this->isPositive = temp->isPositive;
    this->digits = temp->digits;
    this->decDigits = temp->decDigits;
}

const Number Number::operator--(int) {
    Number copy{*this};
    --(*this);
    return copy;
}