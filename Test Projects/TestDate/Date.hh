#ifndef Date_hh
#define Date_hh

#include <string>

#define FLAG_NO_DAY_TYPE -1

class Date{
public:
    ///constructors and dectructors
    Date(int day, int month, int year);
    Date(int day, int month, int year, int dayType); //given a day type

    ///functions for specific use
    std::string toString();
    bool isLeapYear();
    int daysBetween(Date d); //number of days between caller and parameter date. Negative if param is after caller.
    int daysBetween(int day, int month, int year);

    ///operators
    //comparisor operators
    bool operator == (const Date &Ref);
    bool operator != (const Date &Ref);
    bool operator < (const Date &Ref); //the same as isBefore - true if left is before right
    bool operator <= (const Date &Ref);
    bool operator > (const Date &Ref); //opposite of isBefore
    bool operator >= (const Date &Ref);
    //operators that change values
    Date operator ++ (int); //post-increment, replaces incrementDate()
    Date operator ++ (); //pre-increment
    Date operator -- (int); //post-decrement, incrementDate() but in opposite direciton
    Date operator -- (); //pre-decrement
    Date operator += (int n);
    Date operator -= (int n);


    ///getters and setters
    void setYear(int year);
    void setMonth(int month);
    void setDay(int day);
    void setDayType(int dayType);
    int getYear();
    int getMonth();
    int getDay();
    int getDayType();

    ///functions replaced by operator
    void incrementDate(); //increase day by one, andd handle any change in month/year
    bool isBefore(Date d); //true if caller Date before parameter date
    bool isBefore(int day, int month, int year);

private:
    ///class attributes
    int mYear;
    int mMonth;
    int mDay;
    int mDayType; //monday=1, tuesday=2...

    ///methods used internally for other calculations
    int getDaysInCurrentMonth();
    std::string numToString(int num);
    std::string dayTypeToString();
};

#endif // Date_hh
