//
// Created by cookc on 2018-05-03.
//

#include "Number.h"
#include <cmath>

//================================
//      CONSTRUCTORS
//================================

Number::Number() : isPositive{true}, digits{'0'}, base{10} {}

Number::Number(const std::vector<char> &dig, bool isPos, int b) : isPositive{isPos}, digits{dig}, base{b} {}

Number::Number(const std::string &s, int b) : base{b} {
    if (s.empty()) {
        this->isPositive = true;
        this->digits.push_back('0');
    } else {
        char firstChar = s[0];
        this->isPositive = firstChar != '-';
        int startIndex{0};
        if (firstChar == '-' || firstChar == '+') {
            ++startIndex;
        }
        int periodIndex = s.find('.');
        int endIndex = s.length() - 1; //last char is null
        if (periodIndex != std::string::npos) {
            //decimal - need to fill decDigits
            endIndex = periodIndex - 1;
            for (int i = periodIndex + 1; i < s.length() - 1; ++i) {
                this->decDigits.push_back(s[i]);
            }
        }
        for (endIndex; endIndex >= startIndex; --endIndex) {
            this->digits.push_back(s[endIndex]);
        }
    }
}

Number::Number(int i, int b) : Number((long long) i, b) {}

Number::Number(long i, int b) : Number((long long) i, b) {}

Number::Number(short i, int b) : Number((long long) i, b) {}

Number::Number(char c, int b) : Number((long long) Number::charToInt(c), b) {}

Number::Number(const std::vector<char> &dig, const std::vector<char> &dec, bool isPos, int b) : isPositive{isPos},
                                                                                                base{b},
                                                                                                digits{dig},
                                                                                                decDigits{dec} {}

Number::Number(long double f, int b) : base{b} {
    initFloatingPoint<long double>(f);
}

//need to implement double and float constructors on their own, as long double introduces extra floating point error

Number::Number(double f, int b) : base{b} {
    initFloatingPoint<double>(f);
}

Number::Number(float f, int b) : base{b} {
    initFloatingPoint<float>(f);
}

Number::Number(long long in, int b) : base{b} {
    //special case
    if (in == 0) {
        this->isPositive = true;
        this->digits.push_back('0');
    }
    this->isPositive = in >= 0;
    long long cur = in >= 0 ? in : -in;
    while (cur != 0) {
        this->digits.push_back(Number::intToChar(cur % base));//convert to ascii rep. of number
        cur = cur / base;
    }
}

Number::Number(const Number &other) = default;

//================================
//      FUNCTIONS
//================================

std::vector<char> Number::computePosAddDigits(const Number &rhs) const {
    std::vector<char> resDig;
    std::vector<char> lhsDig{this->digits};
    std::vector<char> rhsDig{rhs.digits};
    int rhsLength = rhsDig.size();
    int lhsLength = lhsDig.size();
    int index{0}, carry{0};
    int length = lhsLength > rhsLength ? lhsLength : rhsLength;
    while (index < length) {
        int add;
        if (index < lhsLength && index < rhsLength) {
            add = addChars(lhsDig[index], rhsDig[index]);
        } else if (index < lhsLength) {
            add = (int) lhsDig[index] - Number::ASCII_INT_CONV;
        } else {
            add = (int) rhsDig[index] - Number::ASCII_INT_CONV;
        }
        resDig.push_back(Number::intToChar((add + carry) % base));
        carry = (add + carry) / base;
        ++index;
    }
    //add any leftover carry
    if (carry > 0) {
        resDig.push_back(Number::intToChar(carry % base));
    }
    return resDig;
}

std::vector<char>
Number::computePosAddDecimalDigits(const Number &other, int *finalCarry) const { //TODO crawl through digits reversley
    *finalCarry = 0;
    if (other.decDigits.empty() && this->decDigits.empty()) {
        return this->decDigits;
    } else if (other.decDigits.empty()) {
        return this->decDigits;
    } else if (this->decDigits.empty()) {
        return other.decDigits;
    }

    std::vector<char> resDig;
    std::vector<char> lhsDig{this->decDigits};
    std::vector<char> rhsDig{other.decDigits};
    int rhsLength = rhsDig.size();
    int lhsLength = lhsDig.size();
    int index{0}, carry{0};
    int length = lhsLength > rhsLength ? lhsLength : rhsLength;
    while (index < length) {
        int add;
        if (index < lhsLength && index < rhsLength) {
            add = addChars(lhsDig[index], rhsDig[index]);
        } else if (index < lhsLength) {
            add = (int) lhsDig[index] - Number::ASCII_INT_CONV;
        } else {
            add = (int) rhsDig[index] - Number::ASCII_INT_CONV;
        }
        resDig.push_back(Number::intToChar((add + carry) % base));
        carry = (add + carry) / base;
        ++index;
    }
    *finalCarry = carry; //used to add onto ones column if not not here
    return resDig;
}

bool Number::isZero() const {
    return this->decDigits.empty() && this->digits[0] == 0;
}

int Number::addChars(char dig1, char dig2) {
    return (int) dig1 - Number::ASCII_INT_CONV + (int) dig2 - Number::ASCII_INT_CONV;
}

int Number::subChars(char dig1, char dig2) {
    return (int) dig1 - Number::ASCII_INT_CONV - ((int) dig2 - Number::ASCII_INT_CONV);
}

std::vector<char> Number::findDiff(const Number &other) const {
    if (*this == other) {
        return std::vector<char>{0}; //if equal, no difference
    }
    std::vector<char> resDig;
    std::vector<char> bigDig{this->absIsBigger(other) ? this->digits : other.digits};
    std::vector<char> smallDig{this->absIsBigger(other) ? other.digits : this->digits};
    int smallLength = smallDig.size();
    int bigLength = bigDig.size();
    int borrow{0};
    int index{0};

    //subtract smaller number from larger
    for (index; index < smallLength; ++index) {
        int diff = Number::subChars(bigDig[index], smallDig[index]) - borrow;
        if (diff < 0) {
            diff += base;
            borrow = 1;
        }
        resDig.push_back(Number::intToChar(diff));
    }
    //push on leftover bigger numbers, with borrow subtracted
    for (index; index < bigLength; ++index) {
        int diff = (int) bigDig[index] - Number::ASCII_INT_CONV - borrow;
        if (diff < 0) {
            diff += base;
            borrow = 1;;
        } else {
            borrow = 0;
        }
        resDig.push_back(Number::intToChar(diff));
    }
    //trim extra zeros at left side
    while (resDig.size() > 1 && resDig[resDig.size() - 1] == '0') {
        resDig.pop_back();
    }
    return resDig;
}

int Number::charToInt(char c) {
    return (int) c - Number::ASCII_INT_CONV;
}

char Number::intToChar(long long i) {
    return (char) (i + Number::ASCII_INT_CONV);
}

bool Number::absIsBigger(const Number &other) const {
    std::vector<char> lDig{this->digits};
    std::vector<char> rDig{other.digits};
    int lLength = lDig.size();
    int rLength = rDig.size();
    if (lLength != rLength) {
        return lLength > rLength;
    }
    //compare digits most significant to least - by here, have same length
    for (int i{lLength - 1}; i >= 0; --i) {
        int l = Number::charToInt(lDig[i]);
        int r = Number::charToInt(rDig[i]);
        if (l != r) {
            return l > r;
        }
    }
    //compare decDigits most significant to least
    lDig = this->decDigits;
    rDig = other.decDigits;
    lLength = lDig.size();
    rLength = lDig.size();
    int length{lLength < rLength ? lLength : rLength};
    for (int i{0}; i < length; ++i) {
        int l = Number::charToInt(lDig[i]);
        int r = Number::charToInt(rDig[i]);
        if (l != r) {
            return l > r;
        }
    }
    //here, have same decimal digits up to one ends - more decimals = bigger
    return lLength > rLength;
}

template<typename T>
void Number::initFloatingPoint(T f) {
    auto dig = (long long) f;
    T dec = f - dig;

    //do digits to left of .
    //special case
    if (dig == 0) {
        this->isPositive = true;
        this->digits.push_back('0');
    }
    this->isPositive = dig >= 0;
    long long cur = dig >= 0 ? dig : -dig;
    while (cur != 0) {
        this->digits.push_back(Number::intToChar(cur % base));//convert to ascii rep. of number
        cur = cur / base;
    }

    //do digits to right of .
    long long div{10};
    while (dec != 0) {
        auto val = (int) (dec * div);
        this->decDigits.push_back(Number::intToChar(val));
        dec = dec * div - val;
    }
}