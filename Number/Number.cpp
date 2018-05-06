//
// Created by cookc on 2018-05-03.
//

#include "Number.h"
#include <cmath>

Number::Number() : isPositive(true), digits('0') {}

Number::Number(const std::vector<char> &dig, bool isPos) : isPositive(isPos), digits(dig) {
}

Number::Number(const std::vector<char> &dig) : Number(dig, true) {}

Number::Number(int in) {
    //special case
    if (in == 0) {
        this->isPositive = true;
        this->digits.push_back('0');
    }
    this->isPositive = in >= 0;
    int cur = in >= 0 ? in : -in;
    while (cur != 0) {
        this->digits.push_back((char) ((cur % 10) + Number::ASCII_INT_CONV));//convert to ascii rep. of number
        cur = cur / 10;
    }
}

Number::Number(const Number &other) = default;

std::vector<char> Number::computePosAddDigits(const Number &lhs, const Number &rhs) {
    std::vector<char> resDig;
    std::vector<char> lhsDig = lhs.digits;
    std::vector<char> rhsDig = rhs.digits;
    int rhsLength = rhsDig.size();
    int lhsLength = lhsDig.size();
    int index = 0, carry = 0;
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
        resDig.push_back((char) ((add + carry) % 10 + Number::ASCII_INT_CONV));
        carry = (add + carry) / 10;
        ++index;
    }
    //add any leftover carry
    if (carry > 0) {
        resDig.push_back((char) (carry % 10 + Number::ASCII_INT_CONV));
    }
    return resDig;
}

std::ostream &operator<<(std::ostream &os, const Number &num) {
    os << (num.isPositive ? "" : "-");
    std::vector<char> digits = num.digits;
    for (int i = num.digits.size() - 1; i >= 0; --i) {
        os << digits[i];
    }
    return os;
}

Number operator+(const Number &lhs, const Number &rhs) {
    //if 1 is zero, result is value of the one that isn't zero
    if (lhs.isZero() || rhs.isZero()) {
        return lhs.isZero() ? Number(rhs) : Number(lhs);
    }

    //else have work to do
    if (!lhs.isPositive && !rhs.isPositive) {
        return Number(Number::computePosAddDigits(lhs, rhs), false);
    } else if (lhs.isPositive && rhs.isPositive) {
        return Number(Number::computePosAddDigits(lhs, rhs), true);
    } else {
        //one positive, one negative - turn into (original positive) - (positive of original negative)
        Number tempL = lhs;
        Number tempR = rhs;
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
        return Number(0);
    } else if (lhs.isZero()) {
        return Number(rhs);
    } else if (rhs.isZero()) {
        return Number(lhs);
    }
    if (!rhs.isPositive) {
        Number r = rhs;
        r.isPositive = true;
        return lhs + r;
    } else if (!lhs.isPositive && rhs.isPositive) {
        Number l = lhs;
        l.isPositive = true;
        Number temp(l + rhs);
        temp.isPositive = false;
        return temp;
    }
    //return the difference, negative if rhs > rhs. By here, can't be -
    return Number(lhs.findDiff(rhs), lhs > rhs);
}

bool operator==(const Number &lhs, const Number &rhs) {
    if (lhs.isPositive != rhs.isPositive) {
        return false;
    }
    if (lhs.decDigits != rhs.decDigits) {
        return false;
    }
    return lhs.digits == rhs.digits;
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

int Number::toInt() {
    int index = 0;
    int res = 0;
    std::vector<char> digits = this->digits;
    while (index < digits.size()) {
        res += ((int) digits[index] + Number::ASCII_INT_CONV) * (int) pow(10, index);
        ++index;
    }
    res = this->isPositive ? res : -res;
    return res;
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
        return std::vector<char>(0); //if equal, no difference
    }
    std::vector<char> resDig;
    std::vector<char> bigDig = this->absIsBigger(other) ? this->digits : other.digits;
    std::vector<char> smallDig = this->absIsBigger(other) ? other.digits : this->digits;
    int smallLength = smallDig.size();
    int bigLength = bigDig.size();
    int borrow = 0;
    int index = 0;

    //subtract smaller number from larger
    for (index; index < smallLength; ++index) {
        int diff = Number::subChars(bigDig[index], smallDig[index]) - borrow;
        if (diff < 0) {
            diff += 10;
            borrow = 1;
        }
        resDig.push_back((char) (diff + Number::ASCII_INT_CONV));
    }
    //push on leftover bigger numbers, with borrow subtracted
    for (index; index < bigLength; ++index) {
        int diff = (int) bigDig[index] - Number::ASCII_INT_CONV - borrow;
        if (diff < 0) {
            diff += 10;
            borrow = 1;;
        } else {
            borrow = 0;
        }
        resDig.push_back((char) (diff + Number::ASCII_INT_CONV));
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

char Number::intToChar(int i) {
    return (char) (i + Number::ASCII_INT_CONV);
}

bool Number::absIsBigger(const Number &other) const {
    std::vector<char> lDig = this->digits;
    std::vector<char> rDig = other.digits;
    int lLength = lDig.size();
    int rLength = rDig.size();
    if (lLength != rLength) {
        return lLength > rLength;
    }
    //compare digits most significant to least - by here, have same length
    for (int i = lLength - 1; i >= 0; --i) {
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
    int length = lLength < rLength ? lLength : rLength;
    for (int i = 0; i < length; ++i) {
        int l = Number::charToInt(lDig[i]);
        int r = Number::charToInt(rDig[i]);
        if (l != r) {
            return l > r;
        }
    }
    //here, have same decimal digits up to one ends - more decimals = bigger
    return lLength > rLength;
}