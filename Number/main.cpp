#include <iostream>
#include "Number.h"
#include <climits>

using namespace std;

int main() {
    Number n1("12");
    Number n2("1.11");
    cout << (n1-n2) << endl;
    return 0;
}