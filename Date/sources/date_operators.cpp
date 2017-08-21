#include <iostream>
#include "../headers/date.h"
#include "../headers/date_exceptions.h"

/**
Comparison operators
*/

bool Date::operator==(const Date &Ref) {
    return mDay == Ref.mDay && mMonth == Ref.mMonth && mYear == Ref.mYear && mDayOfWeek == Ref.mDayOfWeek;
}

bool Date::operator!=(const Date &Ref) {
    return !(*this == Ref);
}

///True if LHS is before RHS, else false (equal is false)
bool Date::operator<(const Date &Ref) {
    if (mYear == Ref.mYear) {
        if (mMonth == Ref.mMonth) {
            return mDay < Ref.mDay; //year, month the same, see which day came first
        }
        return mMonth < Ref.mMonth; //year same, months not, so result is first month
    }
    return mYear < Ref.mYear; //if years not equal result is which year came first
}

bool Date::operator<=(const Date &Ref) {
    return *this < Ref || *this == Ref;
}

bool Date::operator>(const Date &Ref) {
    return !(*this <= Ref);
}

bool Date::operator>=(const Date &Ref) {
    return !(*this < Ref);
}

/**
Operators that change the Date's values
*/

Date Date::operator++(int) {
    try {
        if (mDay == getDaysInCurrentMonth()) //new month
        {
            setDay(1);
            if (mMonth == 12) //new year
            {
                setMonth(1);
                setYear(mYear + 1);
            } else {
                setMonth(mMonth + 1);
            }
        } else {
            setDay(mDay + 1);
        }
        if (mDayOfWeek == DayOfWeek::SUNDAY) //end of week is sunday
        {
            setDayType(DayOfWeek::SUNDAY);
        } else if (mDayOfWeek != DayOfWeek::NOT_SET) //don't increment for a day type that was never set
        {
            setDayType(intToDayOfWeek(dayOfWeekToInt(mDayOfWeek) + 1));
        }
    }
    catch (BadDateInputException &e) {
        //current implementation already has checks for proper values, but in case implementation changes in the future have a catch and a notifying message
        std::cout << e.what() << std::endl;
    }
    return *this;
}

Date Date::operator++() {
    return (*this)++; //pre and post are the same
}

Date Date::operator--(int) {
    try {
        if (mDay == 1 && mMonth == 1) //go to Dec 31 of previous year
        {
            setYear(mYear - 1);
            setMonth(12);
            setDay(31);
        } else //don't need to change year
        {
            if (mDay == 1) //go to last day of previous month
            {
                setMonth(mMonth - 1);
                setDay(getDaysInCurrentMonth()); //day is last of the new month
            } else //don't need to change month
            {
                setDay(mDay - 1);
            }
        }
        if (mDayOfWeek == DayOfWeek::MONDAY) //monday, go to sunday
        {
            setDayType(DayOfWeek::SUNDAY);
        } else if (mDayOfWeek != DayOfWeek::NOT_SET) //don't decrement day type when there is no type
        {
            setDayType(intToDayOfWeek(dayOfWeekToInt(mDayOfWeek) - 1));
        }
    }
    catch (BadDateInputException &e) {
        //current implementation already has checks for proper values, but in case implementation changes in the future have a catch and a notifying message
        std::cout << e.what() << std::endl;
    }
    return *this;
}

Date Date::operator--() {
    return (*this)--; //pre and post are the same
}

Date Date::operator+=(int n) {
    for (int i = 0; i < n; i++) {
        (*this)++;
    }
    return *this;
}

Date Date::operator-=(int n) {
    for (int i = 0; i < n; i++) {
        (*this)--;
    }
    return *this;
}

Date &Date::operator=(const Date &Ref) {
    this->setDay(Ref.mDay);
    this->setDayType(Ref.mDayOfWeek);
    this->setMonth(Ref.mMonth);
    this->setYear(Ref.mYear);
    return *this;
}

Date &Date::operator=(Date &&Ref) noexcept {
    this->setDay(Ref.mDay);
    this->setMonth(Ref.mMonth);
    this->setYear(Ref.mYear);
    this->setDayType(Ref.mDayOfWeek);

    Ref.setDayType(DayOfWeek::NOT_SET);
    Ref.setDay(DEFAULT_DAY);
    Ref.setMonth(DEFAULT_MONTH);
    Ref.setYear(DEFAULT_YEAR);
    return *this;
}

/**
Stream operators
*/

std::ostream &operator<<(std::ostream &output, Date &Ref) {
    output << Ref.toString();
    return output;
}

std::istream &operator>>(std::istream &input, Date &Ref) {
    int day, month, year, dayOfWeekInt;
    input >> day >> month >> year >> dayOfWeekInt;

    DayOfWeek dayOfWeek = Date::intToDayOfWeek(dayOfWeekInt);

    try {
        Ref.setYear(year);
    }
    catch (BadYearException &y) {
        std::cout << y.what() << " default year of " << DEFAULT_YEAR << " was used" << std::endl;
        Ref.setYear(DEFAULT_YEAR);
    }
    try {
        Ref.setMonth(month);
    }
    catch (BadMonthException &m) {
        std::cout << m.what() << " default month of " << DEFAULT_MONTH << " was used" << std::endl;
        Ref.setMonth(DEFAULT_MONTH);
    }
    try {
        Ref.setDay(day);
    }
    catch (BadDayException &d) {
        std::cout << d.what() << " default day of " << DEFAULT_DAY << " was used" << std::endl;
        Ref.setDay(DEFAULT_DAY);
    }
    try {
        Ref.setDayType(dayOfWeek);
    }
    catch (BadDayTypeException &t) {
        std::cout << t.what() << " default day type of none was used" << std::endl;
        Ref.setDayType(DayOfWeek::NOT_SET);
    }
    return input;
}

DayOfWeek Date::intToDayOfWeek(int day) {
    switch (day) {
        case 1:
            return DayOfWeek::MONDAY;
        case 2:
            return DayOfWeek::TUESDAY;
        case 3:
            return DayOfWeek::WEDNESDAY;
        case 4:
            return DayOfWeek::THURSDAY;
        case 5:
            return DayOfWeek::FRIDAY;
        case 6:
            return DayOfWeek::SATURDAY;
        case 7:
            return DayOfWeek::SUNDAY;
        default:
            return DayOfWeek::NOT_SET;
    }
}

int Date::dayOfWeekToInt(DayOfWeek dayOfWeek) {
    switch (dayOfWeek) {
        case DayOfWeek::MONDAY:
            return 1;
        case DayOfWeek::TUESDAY:
            return 2;
        case DayOfWeek::WEDNESDAY:
            return 3;
        case DayOfWeek::THURSDAY:
            return 4;
        case DayOfWeek::FRIDAY:
            return 5;
        case DayOfWeek::SATURDAY:
            return 6;
        case DayOfWeek::SUNDAY:
            return 7;
        default:
            return -1;
    }
}