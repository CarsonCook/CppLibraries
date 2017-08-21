#include <iostream>
#include "headers/file_io.h"

using namespace std;

int main() {
    FileInput infile("in.txt");
    FileOutput outFile("out.txt");
    outFile.writeString(infile.fileToString());
    return 0;
}