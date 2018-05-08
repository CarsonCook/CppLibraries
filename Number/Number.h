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

    Number(const std::vector<char> &, const std::vector<char> &, bool= true);

    Number(const Number &);

    //conversion constructors

    explicit Number(const std::string &);

    explicit Number(const std::vector<char> &, bool= true);

    Number(int);

    Number(long);

    Number(long long);

    Number(float);

    Number(double);

    Number(long double);

    Number(short);

    Number(char);

    explicit operator long long() const;

    explicit operator bool() const;

    //operators
    friend Number operator+(const Number &, const Number &);

    friend Number operator-(const Number &, const Number &);

    Number &operator=(const Number &);

    Number &operator++();

    const Number operator++(int);

    Number &operator--();

    const Number operator--(int);

    Number &operator+=(const Number &);

    Number &operator-=(const Number &);

    Number &operator*=(const Number &);

    Number &operator/=(const Number &);

    Number &operator%=(const Number &);

    friend Number operator*(const Number &, const Number &);

    friend Number operator/(const Number &, const Number &);

    friend Number operator%(const Number &, const Number &);

    friend bool operator<(const Number &, const Number &);

    friend bool operator>(const Number &, const Number &);

    friend bool operator>=(const Number &, const Number &);

    friend bool operator<=(const Number &, const Number &);

    friend bool operator==(const Number &, const Number &);

    friend bool operator!=(const Number &, const Number &);

    friend std::ostream &operator<<(std::ostream &, const Number &); //remove friend when define print()

    friend std::istream &operator>>(std::istream &, Number &);

private:
    std::vector<char> digits; //char to save memory - int larger than needed. Least significant stored at position 0.
    std::vector<char> decDigits; //digits after decimal
    bool isPositive;
    int base;

    bool isZero() const;

    bool absIsBigger(const Number &) const;

    std::vector<char> computePosAddDigits(const Number &) const; //helper to add 2 positive number's digits

    template<typename T>
    void initFloatingPoint(T f);

    static int addChars(char, char); //helper to convert 2 chars to ints, add, then convert to char

    static int subChars(char, char);

    static int charToInt(char);

    static char intToChar(long long);

    std::vector<char> findDiff(const Number &) const; //helper to find the absolute difference between this and param

    const static int ASCII_INT_CONV = (int) '0'; //in case not ASCII machine
};

//TODO convert to other bases, functionality for other bases
//TODO implement bit operators