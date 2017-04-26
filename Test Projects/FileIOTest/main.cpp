#include "FileIO.hh"

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    FileOutput outFile("out.txt");
    FileInput inFile("in.txt");
    FileInput inFile2("in.txt");
    cout << (inFile==inFile2);
    return 0;
}
