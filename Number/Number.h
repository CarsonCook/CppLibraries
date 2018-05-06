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
    Number();

    Number(const std::vector<char> &, bool);

    Number(const std::vector<char> &);

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

    friend Number operator-(const Number &, const Number &);

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

    friend bool operator>(const Number &, const Number &);

    bool operator>=(const Number &);

    bool operator<=(const Number &);

    friend bool operator==(const Number &, const Number &);

    bool operator!=(const Number &);

    friend std::ostream &operator<<(std::ostream &, const Number &); //remove friend when define print()
    friend std::ostream &operator>>(std::istream &, const Number &);

    //conversions
    int toInt(); //if float/double, cut off decimal values

private:
    std::vector<char> digits; //char to save memory - int larger than needed. Least significant stored at position 0.
    std::vector<char> decDigits; //digits after decimal
    bool isPositive;
    int base;

    bool isZero() const;

    bool absIsBigger(const Number &) const;

    std::vector<char> computePosAddDigits(const Number &) const; //helper to add 2 positive number's digits

    static int addChars(char, char); //helper to convert 2 chars to ints, add, then convert to char

    static int subChars(char, char);

    static int charToInt(char);

    static char intToChar(int);

    std::vector<char> findDiff(const Number &) const; //helper to find the absolute difference between this and param

    const static int ASCII_INT_CONV = (int) '0'; //in case not ASCII machine
};


