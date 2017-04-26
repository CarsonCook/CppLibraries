#include "FileIO.hh"

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    FileOutput out1("out.txt");
    FileOutput out2=out1.copyFileOutput();
    out2.writeString("hey");
    return 0;
}
