#include <iostream>
#include "Number.h"
#include <climits>

using namespace std;

int main() {;
    Number n1(5);
    n1/=5;
    std::cout << n1 << std::endl;
    n1=10;
    cout << (n1 / 5) << endl;
    return 0;
}