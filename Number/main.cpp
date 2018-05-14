#include <iostream>
#include "Number.h"
#include <climits>

using namespace std;

int main() {
    Number n(10.6);
    cout << (n % 2.3) << endl;
    return 0;
}