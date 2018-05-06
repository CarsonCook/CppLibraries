#include <iostream>
#include "Number.h"
#include <climits>

using namespace std;

int main() {
    Number n1(1);
    Number n2(0);
    Number res = n1 - n2;
    cout <<  res << endl;
    return 0;
}