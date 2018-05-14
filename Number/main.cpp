#include <iostream>
#include "Number.h"
#include <climits>
#include <chrono>

using namespace std;

int main() {
    chrono::time_point<chrono::system_clock>p1,p2,p3;
    p1=chrono::system_clock::now();
    Number n(10.6);
    for (int i=0; i<50; ++i){
        n*1;
    }
    p2=chrono::system_clock::now();
    int a{4};
    for (int i=0; i<50; ++i){
        a*1;
    }
    p3=chrono::system_clock::now();
    cout << (p2-p1).count() << endl;
    cout << (p3-p2).count() << endl;
    return 0;
}