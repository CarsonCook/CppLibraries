#include "Date.hh"
#include "DateExceptions.hh"

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
    try
    {
        int curMonthDays;
        try
        {
            curMonthDays=getDaysInCurrentMonth();
        }
        catch (BadMonthException e)
        {
            std::cout << e.what() << " incrementation was stopped" << std::endl;
            return *this;
        }
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
    }
    catch (BadDateInputException e)
    {
        //current implementation already has checks for proper values, but in case implementation changes in the future have a catch and a notifying message
        std::cout << e.what() << std::endl;
    }
    return *this;
}

Date Date::operator ++ ()
{
    return (*this)++; //pre and post are the same
}

Date Date::operator -- (int)
{
    try
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
                int curMonthDays;
                try
                {
                    curMonthDays=getDaysInCurrentMonth();
                }
                catch (BadMonthException e)
                {
                    std::cout << e.what() << " decrementation was stopped" << std::endl;
                    return *this;
                }
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
    }
    catch (BadDateInputException e)
    {
        //current implementation already has checks for proper values, but in case implementation changes in the future have a catch and a notifying message
        std::cout << e.what() << std::endl;
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
    try
    {
        Ref.setYear(year);
    }
    catch (BadYearException y)
    {
        std::cout << y.what() << " default year of " << DEFAULT_YEAR << " was used" << std::endl;
        Ref.setYear(DEFAULT_YEAR);
    }
    try
    {
        Ref.setMonth(month);
    }
    catch (BadMonthException m)
    {
        std::cout << m.what() << " default month of " << DEFAULT_MONTH << " was used" << std::endl;
        Ref.setMonth(DEFAULT_MONTH);
    }
    try
    {
        Ref.setDay(day);
    }
    catch (BadDayException d)
    {
        std::cout << d.what() << " default day of " << DEFAULT_DAY << " was used" << std::endl;
        Ref.setDay(DEFAULT_DAY);
    }
    try
    {
        Ref.setDayType(type);
    }
    catch (BadDayTypeException t)
    {
        std::cout << t.what() << " default day type of none " << FLAG_NO_DAY_TYPE << " was used" << std::endl;
        Ref.setDay(FLAG_NO_DAY_TYPE);
    }
    return input;
}












