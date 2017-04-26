#include "FileIO.hh"

#include <iostream>

using namespace std;

int main()
{
    FileInput inFile("in.txt");
    cout << inFile.fileToString();
    return 0;
}
