#include "Date.hh"

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
