//
// Created by cookc on 2018-05-06.
//

#include "Number.h"


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
        return Number(lhs.computePosAddDigits(rhs), false);
    } else if (lhs.isPositive && rhs.isPositive) {
        return Number(lhs.computePosAddDigits(rhs), true);
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