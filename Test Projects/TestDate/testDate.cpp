#include <iostream>
#include "Date.hh"

using namespace std;

void testIsBefore();

int main()
{
    testIsBefore();
    return 0;
}

void testIsBefore()
{
    Date first(1,2,1997);
    Date second(1,2,1998);
    cout << first.isBefore(second) << " " << first.isBefore(1,1,1995);
}
