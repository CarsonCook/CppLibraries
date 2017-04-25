#include <iostream>
#include "Date.hh"

using namespace std;

Date one(1,2,1997,1);
Date two(1,2,1997);
Date three(1,2,1998);
Date four(1,2,1997,1);

int main()
{
    Date c=one.copyDate();
    cout << one << " " << c << endl;
    return 0;
}
