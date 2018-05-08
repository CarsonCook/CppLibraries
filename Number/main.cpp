#include <iostream>
#include "Number.h"
#include <climits>

using namespace std;

int main() {
    Number n1(-1);
    cout << n1%4 << endl;
    n1=-5;
    cout << n1%4 << endl;
    cout << n1%-4<<endl;
    return 0;
}