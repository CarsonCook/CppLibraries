#include "Date.hh"

#include <string>
#include <sstream>

Date::Date(int day, int month, int year)
{
    Date(day,month,year,FLAG_BAD_DAY_TYPE);
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

std::string Date::dayTypeToString()
{
    switch(dayType)
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
    if (dayType!=FLAG_BAD_DAY_TYPE) //day type was specified, include in string
    {
        sDate+=(dayTypeToString()+" ");
    }
    sDate+=(numToString(day)+"/"+numToString(month)+"/"+numToString(year));
    return sDate;
}

void Date::incrementDate()
{
    if (day==getDaysInCurrentMonth()) //new month
    {
        setDay(1);
        if (month==12) //new year
        {
            setMonth(1);
            setYear(year+1);
        }
        else
        {
            setMonth(month+1);
        }
    }
    else
    {
        setDay(day+1);
    }
    if (dayType==7) //end of week is sunday
    {
        setDayType(1);
    }
    else
    {
        setDayType(dayType+1);
    }
}

bool Date::isLeapYear()
{
    if (year%4==0)
    {
        if (year%100==0 and year%400!=0)
        {
            return false;
        }
        return true;
    }
    return false;
}

int Date::getDaysInCurrentMonth()
{
    switch(month)
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
    this->dayType=dayType;
}

int Date::getDayType()
{
    return this->dayType;
}

void Date::setDay(int day)
{
    this->day=day;
}

int Date::getDay()
{
    return this->day;
}

void Date::setMonth(int month)
{
    this->month=month;
}

int Date::getMonth()
{
    return this->month;
}

void Date::setYear(int year)
{
    this->year=year;
}

int Date::getYear()
{
    return this->year;
}
