#include <iostream>
#include "Number.h"
#include <climits>

using namespace std;

int main() {
    Number n1(12);
    Number n2("12.0");
    cout << n1 << " " << n2 << endl;
    cout << (n1<n2) << (n1>n2) << (n1<=n2) << (n1>=n2) << (n1==n2) << (n1!=n2) << endl;
    return 0;
}