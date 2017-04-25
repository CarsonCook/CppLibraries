#include "Date.hh"
#include "DateExceptions.hh"

#include <string>
#include <sstream>
#include <iostream>

/**
Constructors
*/

Date::Date()
{
    try
    {
        setDay(1);
        setMonth(1);
        setYear(0);
        setDayType(FLAG_NO_DAY_TYPE);
    }
    catch (BadDateInputException e)
    {
        //current implementation has hardcoded values for the setters, so this will never be thrown. However catch and print message in case there are future changes
        std::cout << e.what() << std::endl;
    }
}

Date::Date(int day, int month, int year)
{
    try
    {
        setYear(year);
    }
    catch (BadYearException y)
    {
        std::cout << y.what() << " default year of " << DEFAULT_YEAR << " was used" << std::endl;
        setYear(DEFAULT_YEAR);
    }
    try
    {
        setMonth(month);
    }
    catch (BadMonthException m)
    {
        std::cout << m.what() << " default month of " << DEFAULT_MONTH << " was used" << std::endl;
        setMonth(DEFAULT_MONTH);
    }
    try
    {
        setDay(day);
    }
    catch (BadDayException d)
    {
        std::cout << d.what() << " defualt day of " << DEFAULT_DAY << " was used" << std::endl;
        setDay(DEFAULT_DAY);
    }
    try
    {
        setDayType(FLAG_NO_DAY_TYPE);
    }
    catch (BadDayTypeException t)
    {
        //current implementation means setDayType() here can't throw an error, so just print message in case in future it would
        std::cout << t.what() << std::endl;
    }
}

Date::Date(int day, int month, int year, int dayType)
{
    try
    {
        setYear(year);
    }
    catch (BadYearException y)
    {
        std::cout << y.what() << " default year of " << DEFAULT_YEAR << " was used" << std::endl;
        setYear(DEFAULT_YEAR);
    }
    try
    {
        setMonth(month);
    }
    catch (BadMonthException m)
    {
        std::cout << m.what() << " default month of " << DEFAULT_MONTH << " was used" << std::endl;
        setMonth(DEFAULT_MONTH);
    }
    try
    {
        setDay(day);
    }
    catch (BadDayException d)
    {
        std::cout << d.what() << " default day of " << DEFAULT_DAY << " was used" << std::endl;
        setDay(DEFAULT_DAY);
    }
    try
    {
        setDayType(dayType);
    }
    catch (BadDayTypeException t)
    {
        std::cout << t.what() << " default day type of none " << FLAG_NO_DAY_TYPE << " was used" << std::endl;
        setDay(FLAG_NO_DAY_TYPE);
    }
}

/**
functions for specific use
*/

int Date::daysBetween(Date d)
{
    int days=0;

    //save the days, as they will be manipulated to do the days between calculation
    Date saveThis=*this;
    Date saveD=d;

    //set day types to be the same
    try
    {
        setDayType(1);
        d.setDayType(1);
    }
    catch (BadDayTypeException t)
    {
        //current implementation means setDayType() here can't throw an error, so just print message in case in future it would
        std::cout << t.what() << std::endl;
    }
    if (*this<d)
    {
        while (*this!=d)
        {
            (*this)++;
            days++;
            //set day types to be the same so != operator can be used
            try
            {
                setDayType(1);
                d.setDayType(1);
            }
            catch (BadDayTypeException t)
            {
                //current implementation means setDayType() here can't throw an error, so just print message in case in future it would
                std::cout << t.what() << std::endl;
            }
        }
    }
    else
    {
        while (d!=*this)
        {
            d++;
            days--;
            try
            {
                setDayType(1);
                d.setDayType(1);
            }
            catch (BadDayTypeException t)
            {
                //current implementation means setDayType() here can't throw an error, so just print message in case in future it would
                std::cout << t.what() << std::endl;
            }
        }
    }

    //restore day types
    *this=saveThis;
    d=saveD;
    return days;
}

int Date::daysBetween(int day,int month,int year)
{
    Date d(day,month,year);
    return daysBetween(d);
}

std::string Date::dayTypeToString()
{
    switch(mDayType)
    {
    case 1:
        return "Monday";
    case 2:
        return "Tuesday";
    case 3:
        return "Wednesday";
    case 4:
        return "Thursday";
    case 5:
        return "Friday";
    case 6:
        return "Saturday";
    case 7:
        return "Sunday";
    default:
        throw BadDayTypeException();
    }
}

std::string Date::toString()
{
    std::string sDate="";
    if (mDayType!=FLAG_NO_DAY_TYPE) //day type was specified, include in string
    {
        try
        {
            sDate+=(dayTypeToString()+" ");
        }
        catch (BadDayTypeException e)
        {
            //just notify and continue, don't add to the string
            std::cout << e.what() << std::endl;
        }
    }
    sDate+=(numToString(mDay)+"/"+numToString(mMonth)+"/"+numToString(mYear));
    return sDate;
}

bool Date::isLeapYear()
{
    if (mYear%4==0)
    {
        if (mYear%100==0 and mYear%400!=0)
        {
            return false;
        }
        return true;
    }
    return false;
}

int Date::getDaysInCurrentMonth()
{
    switch(mMonth)
    {
    case 2:
        return (isLeapYear()?29:28);
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

std::string Date::numToString(int num)
{
    std::stringstream ss;
    ss << num;
    std::string sNum;
    ss >> sNum;
    return sNum;
}


/**
Setters and getters for class variables
*/

void Date::setDayType(int dayType)
{
    mDayType=dayType;
}

int Date::getDayType()
{
    return mDayType;
}

void Date::setDay(int day)
{
    mDay=day;
}

int Date::getDay()
{
    return mDay;
}

void Date::setMonth(int month)
{
    mMonth=month;
}

int Date::getMonth()
{
    return mMonth;
}

void Date::setYear(int year)
{
    if (year<0)
    {
        throw BadYearException();
    }
    mYear=year;
}

int Date::getYear()
{
    return mYear;
}
