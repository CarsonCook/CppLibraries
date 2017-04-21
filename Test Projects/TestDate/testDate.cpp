#include <iostream>
#include "Date.hh"

using namespace std;

void testIsBefore();
void testOperators();

int main()
{
    //testIsBefore();
    testOperators();
    return 0;
}

void testIsBefore()
{
    Date first(1,2,1997);
    Date second(1,2,1998);
    cout << first.isBefore(second) << " " << first.isBefore(1,1,1995);
}

void testOperators()
{
    Date one(1,2,1997);
    Date two(1,2,1997);
    Date three(1,2,1998);
    Date four(1,2,1997,1);
    cout << (one!=two) << " " << (one!=three) << " " << (one!=four) << endl;
}
