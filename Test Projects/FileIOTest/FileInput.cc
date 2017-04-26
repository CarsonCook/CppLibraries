#include "FileIO.hh"
#include <iostream>

using namespace std;

/**
Constructors and destructors
*/

FileInput::FileInput(const char *filePath)
{
    mFilePath=filePath;
}

FileInput::~FileInput()
{
    if (mFile and mFile.is_open())
    {
        mFile.close();
    }
    delete mFilePath;
}

/**
Functions to read file
*/

string FileInput::fileToString()
{
    string sFile;
    mFile.open(mFilePath);
    string oneLine;
    while (getline(mFile,oneLine))
    {
        sFile+=(oneLine+'\n');
    }
    mFile.close();
    return sFile;
}













