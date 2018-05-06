//
// Created by cookc on 2018-05-03.
//

#include "Number.h"
#include <cmath>

Number::Number(const std::vector<char> &dig, bool isPos) : isPositive(isPos), digits(dig) {
}

Number::Number(int in) {
    if (in == 0) {
        this->digits.push_back('0');
    } else {
        this->isPositive = in >= 0;
        int cur = in >= 0 ? in : -in;
        while (cur != 0) {
            this->digits.push_back((char) ((cur % 10) + Number::ASCII_INT_CONV));//convert to ascii rep. of number
            cur = cur / 10;
        }
    }
}

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
            add = (int) lhsDig[index] - Number::ASCII_INT_CONV + (int) rhsDig[index] -
                  Number::ASCII_INT_CONV;
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
    //nothing to do if adding 0
    if (!lhs.isPositive && !rhs.isPositive) {
        return Number(Number::computePosAddDigits(lhs, rhs), false);
    } else if (lhs.isPositive && rhs.isPositive) {
        return Number(Number::computePosAddDigits(lhs, rhs), true);
    } else {
        //figure out if res is pos or neg
    }
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
    return this->digits.empty() && this->digits[0] == 0;
}