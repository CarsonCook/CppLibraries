#include <iostream>
#include "Date.hh"

using namespace std;

void testIsBefore();
void testCompareOperators();
void testDaysBetween();
void testChangeOperators();

Date one(1,2,1997,1);
Date two(1,2,1997);
Date three(1,2,1998);
Date four(1,2,1997,1);

int main()
{
    //testIsBefore();
    //estOperators();
    //testChangeOperators();
    //testDaysBetween();
    return 0;
}

void testIsBefore()
{
    cout << three.isBefore(one) << " " << one.isBefore(1,1,1995);
}

void testCompareOperators()
{
    cout << (one>two) << " " << (one>=two) << " " << (one>=three) << " " << (one!=four) << endl;
}

void testDaysBetween()
{
    cout << one.daysBetween(two) << " " << one.daysBetween(1,5,1997) << " " << three.daysBetween(one) << endl;
}

void testChangeOperators()
{
    cout << one << endl;
    one-=2;
    cout << one << endl;
}
