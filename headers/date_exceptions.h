//
// Created by Carson on 17/08/2017.
//

#ifndef CPPLIBRARIES_DATE_EXCEPTIONS_H
#define CPPLIBRARIES_DATE_EXCEPTIONS_H

#include <exception>

class BadDateInputException : public std::exception
{
public:
    const char* what() const throw()
    {
        return "A bad day, month, year or day type value was input";
    }
};

class BadDayTypeException : public BadDateInputException
{
public:
    const char* what() const throw()
    {
        return "A day type that doesn't correspond to a day of the week (1-7) or \"no day type select\" (-1) was input";
    }
};

class BadYearException : public BadDateInputException
{
public:
    const char* what() const throw()
    {
        return "A negative year value was input";
    }
};

class BadMonthException : public BadDateInputException
{
public:
    const char* what() const throw()
    {
        return "A value that doesn't ocrrespond to a month (1-12) was input";
    }
};

class BadDayException : public BadDateInputException
{
public:
    const char* what() const throw()
    {
        return "A day that doesn't correspond to the month and year input (1-28/29/30/31) was input";
    }
};

#endif //CPPLIBRARIES_DATE_EXCEPTIONS_H
