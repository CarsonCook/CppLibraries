#include "FileIO.hh"

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    FileInput inFile("in.txt");
    inFile.printFile();
    return 0;
}
