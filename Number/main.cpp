#include <iostream>
#include "Number.h"
#include <climits>

using namespace std;

int main() {
    Number n1(99);
    Number n2(1);
    Number res = n1 + n2;
    cout << n1 << endl << res << endl;
    return 0;
}