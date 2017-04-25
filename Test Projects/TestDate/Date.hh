#ifndef Date_hh
#define Date_hh

#include <string>

#define FLAG_NO_DAY_TYPE -1
#define DEFAULT_YEAR 1
#define DEFAULT_MONTH 1
#define DEFAULT_DAY 1

class Date
{
public:
    ///constructors
    Date(); //sets day=1, month=1, year=0
    Date(int day, int month, int year);
    Date(int day, int month, int year, int dayType); //given a day type
    Date(const Date &d); //copy constructor

    ///functions for specific use
    Date copyDate(); //copies the caller instance
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
    //stream operators
    friend std::ostream &operator<<(std::ostream &output,Date &Ref); //essentially uses toString() to output, it just can't call it, so code copied
    friend std::istream &operator>>(std::istream &input,Date &Ref);


    ///getters and setters
    void setYear(int year);
    void setMonth(int month);
    void setDay(int day);
    void setDayType(int dayType);
    int getYear();
    int getMonth();
    int getDay();
    int getDayType();

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
