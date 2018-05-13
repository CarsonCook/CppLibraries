#include <iostream>
#include "Number.h"
#include <climits>

using namespace std;

int main() {
    Number n(1234.987);
    Number i(-100);
    cout << n[i] << endl;
    return 0;
}