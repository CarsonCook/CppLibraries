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

    Number(const std::vector<char> &dig, const std::vector<char> &dec, bool= true, int= 10);

    Number(const Number &);

    //conversion constructors

    explicit Number(const std::string &, int= 10);

    explicit Number(const std::vector<char> &, bool= true, int= 10);

    Number(int, int= 10);

    Number(long, int= 10);

    Number(long long, int= 10);

    Number(float, int= 10);

    Number(double, int= 10);

    Number(long double, int= 10);

    Number(short, int= 10);

    Number(char, int= 10);

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
    std::vector<char> decDigits; //digits after decimal - most significant is at position 0.
    bool isPositive;
    int base;

    bool isZero() const;

    bool absIsBigger(const Number &) const;

    static Number absAdd(const Number &, const Number &);

    std::vector<char> computePosAddDigits(const Number &) const; //helper to add 2 positive number's digits

    std::vector<char> computePosAddDecimalDigits(const Number &, int *carry) const;

    static int addChars(char, char); //helper to convert 2 chars to ints, add, then convert to char

    static int subChars(char, char);

    static int charToInt(char);

    static char intToChar(long long);

    std::vector<char> findDigDiff(const Number &) const; //helper to find the absolute difference between this and param

    std::vector<char> subtractDec(const Number &, int *borrow) const; //subtracts other's decimals from this

    const static int ASCII_INT_CONV = (int) '0'; //in case not ASCII machine
};

class BadNumberStringException : public std::exception {
public:
    explicit BadNumberStringException(int c, const std::string &s);

    const char *what() const noexcept override;

private:
    std::string str;
    int pos;
};

//TODO convert to other bases, functionality for other bases
//TODO override [] for powers of base to access individual numbers
//TODO implement bit operators