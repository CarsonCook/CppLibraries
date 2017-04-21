#include <iostream>
#include "Date.hh"

using namespace std;

void testIsBefore();

int main()
{

    return 0;
}

void testIsBefore()
{
    Date first(1,2,1997);
    Date second(1,2,1998);
    cout << first.isBefore(second);
}
