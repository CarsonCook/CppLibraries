#include "Date.hh"

#include <string>
#include <sstream>
#include <iostream>

Date::Date(int day, int month, int year)
{
    setDay(day);
    setMonth(month);
    setYear(year);
    setDayType(FLAG_NO_DAY_TYPE);
}

Date::Date(int day, int month, int year, int dayType)
{
    setDay(day);
    setMonth(month);
    setYear(year);
    setDayType(dayType);
}

///True if caller date is before parameter date, else returns false. If equal, still return false.
bool Date::isBefore(Date d)
{
    if (this->getYear()==d.getYear())
    {
        if (this->getMonth()==d.getMonth())
        {
            return this->getDay()<d.getDay(); //year, month the same, see which day came first
        }
        return this->getMonth()<d.getMonth(); //year same, months not, so result is first month
    }
    return this->getYear()<d.getYear(); //if years not equal result is which year came first
}

bool Date::isBefore(int testDay,int testMonth,int testYear)
{
    Date d(testDay,testMonth,testYear);
    return this->isBefore(d);
}

int Date::daysBetween(Date d)
{
    int days=0;

    //save the days, as they will be manipulated to do the days between calculation
    Date saveThis=*this;
    Date saveD=d;

    //set day types to be the same
    setDayType(1);
    d.setDayType(1);

    if (isBefore(d))
    {
        while (*this!=d)
        {
            incrementDate();
            days++;
            //set day types to be the same so != operator can be used
            setDayType(1);
            d.setDayType(1);
        }
    }
    else
    {
        while (d!=*this)
        {
            d.incrementDate();
            days--;
            //set day types to be the same so != operator can be used
            setDayType(1);
            d.setDayType(1);
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
    }
}

std::string Date::toString()
{
    std::string sDate="";
    if (mDayType!=FLAG_NO_DAY_TYPE) //day type was specified, include in string
    {
        sDate+=(dayTypeToString()+" ");
    }
    sDate+=(numToString(mDay)+"/"+numToString(mMonth)+"/"+numToString(mYear));
    return sDate;
}

void Date::incrementDate()
{
    if (mDay==getDaysInCurrentMonth()) //new month
    {
        setDay(1);
        if (mMonth==12) //new year
        {
            setMonth(1);
            setYear(mYear+1);
        }
        else
        {
            setMonth(mMonth+1);
        }
    }
    else
    {
        setDay(mDay+1);
    }
    if (mDayType==7) //end of week is sunday
    {
        setDayType(1);
    }
    else
    {
        setDayType(mDayType+1);
    }
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
    mYear=year;
}

int Date::getYear()
{
    return mYear;
}
