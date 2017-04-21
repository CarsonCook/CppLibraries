#include "Date.hh"

bool Date::operator == (const Date &Ref) const
{
    return mDay==Ref.mDay and mMonth==Ref.mMonth and mYear==Ref.mYear and mDayType==Ref.mDayType;
}
