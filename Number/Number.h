//
// Created by cookc on 2018-05-03.
//

#pragma once

#include <string>
#include <vector>
#include <iostream>

class Number {
public:
    ~Number() = default;

    //regular constructors
    Number(const std::vector<char> &, bool);

    //conversion constructors
    Number(const std::string &);

    Number(char *s);

    Number(const Number &);

    explicit Number(int);

    Number(long);

    Number(long long);

    Number(float);

    Number(double);

    Number(long double);

    Number(short);

    //operators
    friend Number operator+(const Number &, const Number &);

    Number operator-(const Number &);

    Number &operator=(const Number &);

    Number &operator++();

    Number &operator++(int);

    Number &operator--();

    Number &operator--(int);

    Number &operator+=(const Number &);

    Number &operator-=(const Number &);

    Number &operator*=(const Number &);

    Number &operator/=(const Number &);

    Number operator*(const Number &);

    Number operator/(const Number &);

    Number operator%(const Number &);

    bool operator<(const Number &);

    bool operator>(const Number &);

    bool operator>=(const Number &);

    bool operator<=(const Number &);

    bool operator==(const Number &);

    bool operator!=(const Number &);

    friend std::ostream &operator<<(std::ostream &, const Number &); //remove friend when define print()
    friend std::ostream &operator>>(std::istream &, const Number &);

    //conversions
    int toInt(); //if float/double, cut off decimal values

private:
    std::vector<char> digits; //char to save memory - int larger than needed. Least significant stored at position 0.
    std::vector<char> decDigits; //digits after decimal
    bool isPositive;

    bool isZero() const;

    static std::vector<char> computePosAddDigits(const Number &, const Number &);

    const static int ASCII_INT_CONV = 48;
};


