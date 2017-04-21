#ifndef Date_hh
#define Date_hh

#include <string>

#define FLAG_BAD_DAY_TYPE -1

class Date{
public:
    //constructors and dectructors
    Date(int day, int month, int year);
    Date(int day, int month, int year, int dayType); //given a day type

    //functions for specific use
    std::string toString();
    void incrementDate(); //increase day by one, nad handle any chnage in month/year
    bool isBefore(Date d); //true if caller Date before parameter date
    bool isBefore(int day, int month, int year);
    bool isLeapYear();

    //getters and setters
    void setYear(int year);
    void setMonth(int month);
    void setDay(int day);
    void setDayType(int dayType);
    int getYear();
    int getMonth();
    int getDay();
    int getDayType();

private:
    int mYear;
    int mMonth;
    int mDay;
    int mDayType; //monday=1, tuesday=2...
    int getDaysInCurrentMonth();
    std::string numToString(int num);
    std::string dayTypeToString();
};

#endif // Date_hh
