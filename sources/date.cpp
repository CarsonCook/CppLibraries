#include "../headers/date.h"
#include "../headers/date_exceptions.h"

#include <iostream>
#include <sstream>

/**
Constructors
*/

Date::Date(int day, int month, int year) {
    try {
        setYear(year);
    }
    catch (BadYearException y) {
        std::cout << y.what() << " default year of " << DEFAULT_YEAR << " was used" << std::endl;
        setYear(DEFAULT_YEAR);
    }
    try {
        setMonth(month);
    }
    catch (BadMonthException m) {
        std::cout << m.what() << " default month of " << DEFAULT_MONTH << " was used" << std::endl;
        setMonth(DEFAULT_MONTH);
    }
    try {
        setDay(day);
    }
    catch (BadDayException d) {
        std::cout << d.what() << " defualt day of " << DEFAULT_DAY << " was used" << std::endl;
        setDay(DEFAULT_DAY);
    }
    try {
        setDayType(DayOfWeek::NOT_SET);
    }
    catch (BadDayTypeException t) {
        //current implementation means setDayType() here can't throw an error, so just print message in case in future it would
        std::cout << t.what() << std::endl;
    }
}

Date::Date(int day, int month, int year, DayOfWeek dayOfWeek) {
    try {
        setYear(year);
    }
    catch (BadYearException y) {
        std::cout << y.what() << " default year of " << DEFAULT_YEAR << " was used" << std::endl;
        setYear(DEFAULT_YEAR);
    }
    try {
        setMonth(month);
    }
    catch (BadMonthException m) {
        std::cout << m.what() << " default month of " << DEFAULT_MONTH << " was used" << std::endl;
        setMonth(DEFAULT_MONTH);
    }
    try {
        setDay(day);
    }
    catch (BadDayException d) {
        std::cout << d.what() << " default day of " << DEFAULT_DAY << " was used" << std::endl;
        setDay(DEFAULT_DAY);
    }
    try {
        setDayType(dayOfWeek);
    }
    catch (BadDayTypeException t) {
        std::cout << t.what() << " default day type of none was used" << std::endl;
        setDayType(DayOfWeek::NOT_SET);
    }
}

Date::Date(const Date &d) {
    try {
        setYear(d.mYear);
        setMonth(d.mMonth);
        setDay(d.mDay);
        setDayType(d.mDayOfWeek);
    }
    catch (BadDateInputException e) {
        //if values got put into other date, they should be good. Just in case put in a notification
        std::cout << e.what() << std::endl;
    }
}

/**
functions for specific use
*/

Date Date::copyDate() {
    return Date(*this);
}

int Date::daysBetween(Date d) {
    int days = 0;

    //save the days, as they will be manipulated to do the days between calculation
    Date saveThis = *this;
    Date saveD = d;

    //set day types to be the same
    try {
        setDayType(DayOfWeek::MONDAY);
        d.setDayType(DayOfWeek::MONDAY);
    }
    catch (BadDayTypeException t) {
        //current implementation means setDayType() here can't throw an error, so just print message in case in future it would
        std::cout << t.what() << std::endl;
    }
    if (*this < d) {
        while (*this != d) {
            (*this)++;
            days++;
            //set day types to be the same so != operator can be used
            try {
                setDayType(DayOfWeek::MONDAY);
                d.setDayType(DayOfWeek::MONDAY);
            }
            catch (BadDayTypeException t) {
                //current implementation means setDayType() here can't throw an error, so just print message in case in future it would
                std::cout << t.what() << std::endl;
            }
        }
    } else {
        while (d != *this) {
            d++;
            days--;
            try {
                setDayType(DayOfWeek::MONDAY);
                d.setDayType(DayOfWeek::MONDAY);
            }
            catch (BadDayTypeException t) {
                //current implementation means setDayType() here can't throw an error, so just print message in case in future it would
                std::cout << t.what() << std::endl;
            }
        }
    }

    //restore day types
    *this = saveThis;
    d = saveD;
    return days;
}

int Date::daysBetween(int day, int month, int year) {
    Date d(day, month, year);
    return daysBetween(d);
}

std::string Date::dayTypeToString() {
    switch (mDayOfWeek) {
        case DayOfWeek::MONDAY:
            return "Monday";
        case DayOfWeek::TUESDAY:
            return "Tuesday";
        case DayOfWeek::WEDNESDAY:
            return "Wednesday";
        case DayOfWeek::THURSDAY:
            return "Thursday";
        case DayOfWeek::FRIDAY:
            return "Friday";
        case DayOfWeek::SATURDAY:
            return "Saturday";
        case DayOfWeek::SUNDAY:
            return "Sunday";
        default:
            throw BadDayTypeException();
    }
}

std::string Date::toString() {
    std::string sDate = "";
    if (mDayOfWeek != DayOfWeek::NOT_SET) //day type was specified, include in string
    {
        try {
            sDate += (dayTypeToString() + " ");
        }
        catch (BadDayTypeException e) {
            //just notify and continue, don't add to the string
            std::cout << e.what() << std::endl;
        }
    }
    sDate += (numToString(mDay) + "/" + numToString(mMonth) + "/" + numToString(mYear));
    return sDate;
}

bool Date::isLeapYear() {
    if (mYear % 4 == 0) {
        if (mYear % 100 == 0 && mYear % 400 != 0) {
            return false;
        }
        return true;
    }
    return false;
}

int Date::getDaysInCurrentMonth() {
    switch (mMonth) {
        case 2:
            return (isLeapYear() ? 29 : 28);
        case 4:
        case 6:
        case 9:
        case 11:
            return 30;
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            return 31;
        default:
            throw BadMonthException();
    }
}

std::string Date::numToString(int num) {
    std::stringstream ss;
    ss << num;
    std::string sNum;
    ss >> sNum;
    return sNum;
}


/**
Setters and getters for class variables
*/

void Date::setDayType(DayOfWeek dayOfWeek) {
    mDayOfWeek = dayOfWeek;
}

DayOfWeek Date::getDayType() {
    return mDayOfWeek;
}

void Date::setDay(int day) {
    mDay = day;
}

int Date::getDay() {
    return mDay;
}

void Date::setMonth(int month) {
    mMonth = month;
}

int Date::getMonth() {
    return mMonth;
}

void Date::setYear(int year) {
    if (year < 0) {
        throw BadYearException();
    }
    mYear = year;
}

int Date::getYear() {
    return mYear;
}
