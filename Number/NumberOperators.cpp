//
// Created by cookc on 2018-05-06.
//

#include <algorithm>
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

Number::operator std::string() const {
    std::string res;
    if (!isPositive) {
        res += '-';
    }
    for (int i = digits.size() - 1; i >= 0; --i) {
        res += digits[i];
    }
    if (!decDigits.empty()) {
        res += '.';
        for (auto c : decDigits) {
            res += c;
        }
    }
    return res;
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
    std::vector<char> decimals = num.decDigits;
    if (!decimals.empty()) {
        os << '.';
        for (auto c : decimals) {
            os << c;
        }
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
        Number num = Number::absAdd(lhs, rhs);
        num.isPositive = false;
        return num;
    } else if (lhs.isPositive && rhs.isPositive) {
        return Number::absAdd(lhs, rhs);
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
    //return the difference, negative if rhs > rhs. By here, rhs can't be -
    Number res, big, small;
    res.isPositive = lhs > rhs;
    if (res.isPositive) {
        big = lhs;
        small = rhs;
    } else {
        big = rhs;
        small = lhs;
    }
    auto *borrow = new int(0);
    res.decDigits = big.subtractDec(small, borrow);
    res.digits = Number(Number(big.findDigDiff(small + *borrow))).digits;
    delete borrow;
    return res;
}

Number operator*(const Number &lhs, const Number &rhs) {
    //if either zero, return 0
    if (lhs.isZero() || rhs.isZero()) {
        return Number{0};
    }
    //if either one, return the other
    if (lhs == 1) {
        return Number{rhs};
    }
    if (rhs == 1) {
        return Number{lhs};
    }

    std::vector<char> leftDec = lhs.decDigits;
    std::vector<char> rightDec = rhs.decDigits;
    bool leftEmpty = leftDec.empty();
    bool rightEmpty = rightDec.empty();
    if (leftEmpty && rightEmpty) {
        Number res{0};
        Number left{lhs};
        left.isPositive = true;
        for (Number i{1}; i <= left; ++i) {
            res += rhs;
        }
        res.isPositive = rhs.isPositive == lhs.isPositive;
        return res;
    } else {
        //treat as whole numbers, then chop into decimal and digits - number of decimal places is total between 2 originals
        Number left = lhs;
        Number right = rhs;
        if (!leftEmpty) {
            //make left whole
            for (const auto v : left.decDigits) {
                left.digits.insert(left.digits.begin(), v);
            }
            left.decDigits.clear();
            //clear extra zeros from left side of digits
            while (left.digits.size() > 1 && left.digits[left.digits.size() - 1] == '0') {
                left.digits.pop_back();
            }
        }
        if (!rightEmpty) {
            //make right whole
            for (const auto v : right.decDigits) {
                right.digits.insert(right.digits.begin(), v);
            }
            right.decDigits.clear();
            //clear extra zeros from left side of digits
            while (right.digits.size() > 1 && right.digits[right.digits.size() - 1] == '0') {
                right.digits.pop_back();
            }
        }
        Number res = left * right;
        int splitPos = leftDec.size() + rightDec.size();
        if (splitPos > 0) {
            res.decDigits = std::vector<char>(res.digits.begin(), res.digits.begin() + splitPos);
            std::reverse(res.decDigits.begin(), res.decDigits.end()); //decimal most significant digit is at 0
            res.digits = std::vector<char>(res.digits.begin() + splitPos, res.digits.end());
        }
        //trim extra zeros at right side of decimal
        while (!res.decDigits.empty() && res.decDigits[res.decDigits.size() - 1] == '0') {
            res.decDigits.pop_back();
        }
        return res;
    }
}

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
    Number quot{0};
    Number dividend{lhs};
    Number divisor{rhs};
    dividend.isPositive = true;
    divisor.isPositive = true;
    while (dividend >= divisor) {
        dividend -= divisor;
        ++quot;
    }

    //decimals
    Number extra = dividend * 10;
    while (extra != 0) {
        Number into{0};
        int count = 0;
        while (into <= extra) {
            into += divisor;
            ++count;
        }
        //went one over
        --count;
        into -= divisor;

        quot.decDigits.push_back(Number::intToChar(count));
        if (quot.decDigits.size() >= Number::MAX_PRECISION) {
            break;
        }
        extra -= into;
        extra *= 10; //move onto next decimal place
    }

    quot.isPositive = (lhs.isPositive == rhs.isPositive);
    return quot;
}

Number operator%(const Number &lhs, const Number &rhs) {
    //special cases
    if (rhs.isZero()) {
        return Number{0};
    }
    if (rhs == 1) {
        return 0;
    }
    if (lhs.isZero()) {
        return 0;
    }
    Number dividend{lhs};
    Number divisor{rhs};
    dividend.isPositive = true;
    divisor.isPositive = true;
    while (dividend >= divisor) {
        dividend -= divisor;
    }
    dividend.isPositive = rhs.isPositive || lhs.isPositive;
    return dividend;
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
    return !(lhs >= rhs);
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
    auto *temp = new Number{*this % other};
    this->isPositive = temp->isPositive;
    this->digits = temp->digits;
    this->decDigits = temp->decDigits;
    return *this;
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

//================================
//      OTHER OPERATORS
//================================

int Number::operator[](Number index) const {
    //force only integers and powers of base and not zero
    bool indexOne = index == 1 || index == -1;
    if (!index.decDigits.empty() || (!indexOne && index % base != 0) || index.isZero()) {
        throw BadSubscriptAccess(*this, index, base, "illegal subscript number");
    }

    //get index of vector to access - 1 is special case where no work done
    int i{1};
    Number match{index};
    match.isPositive = true; //match absolute value
    if (!indexOne) {
        Number val(base);
        while (val != match) {
            val *= val;
            ++i;
        }
    }

    //positives for digits, negatives for decimals
    --i; //vectors index at 0
    if (index.isPositive) {
        int length = digits.size();
        if (i >= length) {
            throw BadSubscriptAccess(*this, index, base, "subscript too big");
        }
        return Number::charToInt(digits[length - 1 - i]);
    } else {
        if (i >= decDigits.size()) {
            throw BadSubscriptAccess(*this, index, base, "subscript too big");
        }
        return Number::charToInt(decDigits[i]);
    }
}