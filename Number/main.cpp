#include <iostream>
#include "Number.h"

using namespace std;

int main() {
    Number n1(-321);
    Number n2(-123);
    Number res=n1+n2;
    cout << n1 << endl << n2 << endl << res << endl;
    return 0;
}