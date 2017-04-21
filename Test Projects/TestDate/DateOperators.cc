#include "Date.hh"

bool Date::operator == (const Date &Ref)
{
    return mDay==Ref.mDay and mMonth==Ref.mMonth and mYear==Ref.mYear and mDayType==Ref.mDayType;
}

bool Date::operator != (const Date &Ref)
{
    return !(*this==Ref);
}
