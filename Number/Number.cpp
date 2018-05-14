//
// Created by cookc on 2018-05-03.
//

#include "Number.h"
#include <cmath>
#include <algorithm>
#include <cctype>

//================================
//      CONSTRUCTORS
//================================

Number::Number() : isPositive{true}, digits{'0'}, base{10} {}

Number::Number(const std::vector<char> &dig, bool isPos, int b) : isPositive{isPos}, digits{dig}, base{b} {}

Number::Number(const std::string &s, int b) : base{b} {
    if (s.empty()) {
        throw BadNumberStringException(0, s);
    } else {
        char firstChar = s[0];
        this->isPositive = firstChar != '-';
        int startIndex{0};
        if (firstChar == '-' || firstChar == '+') {
            ++startIndex;
        } else if (firstChar != '.' && !isdigit(firstChar)) {
            throw BadNumberStringException(0, s);
        }
        int periodIndex = s.find('.');
        int endIndex = s.length();
        if (periodIndex != std::string::npos) {
            //decimal - need to fill decDigits
            endIndex = periodIndex - 1;
            for (int i = periodIndex + 1; i < s.length(); ++i) {
                char c = s[i];
                if (!isdigit(c) && c != '\0') {
                    throw BadNumberStringException(i, s);
                }
                if (c != '\0') {
                    this->decDigits.push_back(c);
                }
            }
        }
        for (endIndex; endIndex >= startIndex; --endIndex) {
            char c = s[endIndex];
            if (!isdigit(c) && c != '\0') {
                throw BadNumberStringException(endIndex, s);
            }
            if (c != '\0') {
                this->digits.push_back(s[endIndex]);
            }
        }
    }
    //trim zeros from end of decimal
    while (!decDigits.empty() && decDigits[decDigits.size() - 1] == '0') {
        decDigits.pop_back();
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

Number::Number(long double f, int b) : Number(std::to_string(f), b) {}

//need to implement double and float constructors on their own, as long double introduces extra floating point error

Number::Number(double f, int b) : Number(std::to_string(f), b) {
}

Number::Number(float f, int b) : Number(std::to_string(f), b) {
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

std::vector<char> Number::computePosAddDecimalDigits(const Number &other, int *finalCarry) const {
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
    int length = lhsLength > rhsLength ? lhsLength : rhsLength;
    int index{length - 1}, carry{0};
    while (index >= 0) {
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
        --index;
    }
    //clear dangling .0 at end of what is now whole number
    if (resDig.size() == 1 && resDig[0] == '0') {
        resDig.clear();
    }
    std::reverse(resDig.begin(), resDig.end());
    *finalCarry = carry; //used to add onto ones column if not not here
    return resDig;
}

bool Number::isZero() const {
    return this->decDigits.empty() && this->digits.size() == 1 && this->digits[0] == '0';
}

int Number::addChars(char dig1, char dig2) {
    return (int) dig1 - Number::ASCII_INT_CONV + (int) dig2 - Number::ASCII_INT_CONV;
}

int Number::subChars(char dig1, char dig2) {
    return (int) dig1 - Number::ASCII_INT_CONV - ((int) dig2 - Number::ASCII_INT_CONV);
}

std::vector<char> Number::findDigDiff(const Number &other) const {
    if (*this == other) {
        return std::vector<char>{'0'}; //if equal, no difference
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

std::vector<char> Number::subtractDec(const Number &other, int *finalBorrow) const {
    *finalBorrow = 0;
    std::vector<char> thisDec{this->decDigits};
    std::vector<char> otherDec{other.decDigits};

    if (otherDec.empty() && thisDec.empty() || *this == other) {
        return std::vector<char>{}; //no trailing 0
    }
    //if one empty, the other is the difference
    if (otherDec.empty()) {
        return thisDec;
    }
    if (thisDec.empty()) {
        thisDec.push_back(Number::intToChar(10));
        *finalBorrow = 1;
    }

    Number thisNum(std::vector<char>('0'), thisDec);
    Number otherNum(std::vector<char>('0'), otherDec);
    if (thisNum == otherNum) {
        return std::vector<char>();
    } else if (otherNum > thisNum) {
        //get borrow set up, as this decimals are smaller
        *finalBorrow = 1;
        thisDec[0] += 10;
    }
    //pad shorter decimal with 0s to get to same length (don't change value)
    int thisLength = thisDec.size(), otherLength = otherDec.size();
    int length = thisLength > otherLength ? thisLength : otherLength;
    while (thisDec.size() != otherDec.size()) {
        if (thisDec.size() < length) {
            thisDec.push_back('0');
        } else {
            otherDec.push_back('0');
        }
    }

    //subtract
    std::vector<char> resDec;
    length = thisDec.size(); //both decimals have same length
    int index{length - 1}, borrow{0};
    for (index; index >= 0; --index) {
        int diff = Number::subChars(thisDec[index], otherDec[index]) - borrow;
        if (diff < 0) {
            diff += base;
            borrow = 1;
        }
        resDec.push_back(Number::intToChar(diff));
    }
    std::reverse(resDec.begin(), resDec.end());
    //trim extra zeros at left side
    while (resDec.size() > 1 && resDec[resDec.size() - 1] == '0') {
        resDec.pop_back();
    }
    if (*finalBorrow == 0) {
        //don't change finalBorrow if already set to 1
        *finalBorrow = borrow;
    }
    return resDec;
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
    rLength = rDig.size();
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

Number Number::absAdd(const Number &lhs, const Number &rhs) {
    auto *carry = new int(0);
    Number num;
    num.digits = lhs.computePosAddDigits(rhs);
    num.decDigits = lhs.computePosAddDecimalDigits(rhs, carry);
    num.digits = num.computePosAddDigits(*carry);
    delete carry;
    return num;
}