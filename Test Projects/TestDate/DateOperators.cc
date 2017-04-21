#include "Date.hh"

#include <iostream>

/**
Comparison operators
*/

bool Date::operator == (const Date &Ref)
{
    return mDay==Ref.mDay and mMonth==Ref.mMonth and mYear==Ref.mYear and mDayType==Ref.mDayType;
}

bool Date::operator != (const Date &Ref)
{
    return !(*this==Ref);
}

///True if LHS is before RHS, else false (equal is false)
bool Date::operator < (const Date &Ref)
{
    if (mYear==Ref.mYear)
    {
        if (mMonth==Ref.mMonth)
        {
            return mDay<Ref.mDay; //year, month the same, see which day came first
        }
        return mMonth<Ref.mMonth; //year same, months not, so result is first month
    }
    return mYear<Ref.mYear; //if years not equal result is which year came first
}

bool Date::operator <= (const Date &Ref)
{
    return *this<Ref or *this==Ref;
}

bool Date::operator > (const Date &Ref)
{
    return !(*this<=Ref);
}

bool Date::operator >= (const Date &Ref)
{
    return !(*this<Ref);
}

/**
Operators that change the Date's values
*/

Date Date::operator ++ (int)
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
    else if (mDayType!=FLAG_NO_DAY_TYPE) //don't increment for a day type that was never set
    {
        setDayType(mDayType+1);
    }
    return *this;
}

Date Date::operator ++ ()
{
    return (*this)++; //pre and post are the same
}

Date Date::operator -- (int)
{
    if (mDay==1 and mMonth==1) //go to Dec 31 of previous year
    {
        setYear(mYear-1);
        setMonth(12);
        setDay(31);
    }
    else //don't need to change year
    {
        if (mDay==1) //go to last day of previous month
        {
            setMonth(mMonth-1);
            setDay(getDaysInCurrentMonth()); //day is last of the new month
        }
        else //don't need to change month
        {
            setDay(mDay-1);
        }
    }
    if (mDayType==1) //monday, go to sunday
    {
        setDayType(7);
    }
    else if (mDayType!=FLAG_NO_DAY_TYPE) //don't decrement day type when there is no type
    {
        setDayType(mDayType-1);
    }
    return *this;
}

Date Date::operator -- ()
{
    return (*this)--; //pre and post are the same
}

Date Date::operator += (int n)
{
    for (int i=0; i<n; i++)
    {
        (*this)++;
    }
    return *this;
}

Date Date::operator -= (int n)
{
    for (int i=0; i<n; i++)
    {
        (*this)--;
    }
    return *this;
}

/**
Stream operators
*/

std::ostream &operator<<(std::ostream &output,Date &Ref)
{
    output << Ref.toString();
    return output;
}

std::istream &operator>>(std::istream &input,Date &Ref)
{
    int day, month, year, type;
    input >> day >> month >> year >> type;
    Ref.setDay(day);
    Ref.setMonth(month);
    Ref.setYear(year);
    Ref.setDayType(type);
    return input;
}












