/**
 Created by Carson on 17/08/2017.
*/

#ifndef CPPLIBRARIES_DATE_H
#define CPPLIBRARIES_DATE_H

#include <string>

//default start date in Jan 1, 1970 - start of timestamp
#define DEFAULT_YEAR 1970
#define DEFAULT_MONTH 1
#define DEFAULT_DAY 1

enum class DayOfWeek {
    MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY, SUNDAY, NOT_SET
};

class Date {
public:
    ///constructors
    Date(int day, int month, int year);

    Date(int day, int month, int year, DayOfWeek dayType); //given a day type
    Date(const Date &d); //copy constructor
    Date(Date &&other) noexcept; //move constructor
    ~Date();

    ///functions for specific use
    Date copy(); //copies the caller instance
    std::string toString();

    bool isLeapYear();

    int daysBetween(Date d); //number of days between caller and parameter date. Negative if param is after caller.
    int daysBetween(int day, int month, int year);

    ///operators
    //comparison operators
    bool operator==(const Date &Ref);

    bool operator!=(const Date &Ref);

    bool operator<(const Date &Ref); //the same as isBefore - true if left is before right
    bool operator<=(const Date &Ref);

    bool operator>(const Date &Ref); //opposite of isBefore
    bool operator>=(const Date &Ref);

    //operators that change values
    Date operator++(int); //post-increment, replaces incrementDate()
    Date operator++(); //pre-increment
    Date operator--(int); //post-decrement, incrementDate() but in opposite direction
    Date operator--(); //pre-decrement
    Date operator+=(int n);

    Date operator-=(int n);

    Date &operator=(const Date &Ref); //copy assignment
    Date &operator=(Date &&Ref) noexcept; //move assignment

    //stream operators
    friend std::ostream &operator<<(std::ostream &output,
                                    Date &Ref); //essentially uses toString() to output, it just can't call it, so code copied
    friend std::istream &operator>>(std::istream &input, Date &Ref);

    ///getters and setters
    void setYear(int year);

    void setMonth(int month);

    void setDay(int day);

    void setDayType(DayOfWeek dayType);

    int getYear();

    int getMonth();

    int getDay();

    DayOfWeek getDayType();

private:
    ///class attributes
    int mYear;
    int mMonth;
    int mDay;
    DayOfWeek mDayOfWeek;

    ///methods used internally for other calculations
    static DayOfWeek intToDayOfWeek(int num);

    static int dayOfWeekToInt(DayOfWeek dayOfWeek);

    int getDaysInCurrentMonth();

    std::string numToString(int num);

    std::string dayTypeToString();
};

#endif
