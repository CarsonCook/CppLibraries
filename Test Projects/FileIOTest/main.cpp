#include "FileIO.hh"

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    FileOutput outFile("out.txt");
    FileInput inFile("in.txt");
    outFile.writeFile(inFile);
    return 0;
}
