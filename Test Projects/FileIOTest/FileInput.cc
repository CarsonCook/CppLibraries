#include "FileIO.hh"
#include "FileIOExceptions.hh"
#include <iostream>
#include <vector>

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
    if (!mFile.is_open())
    {
        throw FileNotOpened();
    }
    string oneLine;
    while(getline(mFile,oneLine))
    {
        sFile+=(oneLine+'\n');
    }
    mFile.close();
    return sFile;
}

svec FileInput::fileToStringVector()
{
    svec fileVec;
    mFile.open(mFilePath);
    if (!mFile.is_open())
    {
        throw FileNotOpened();
    }
    string oneLine;
    while(getline(mFile,oneLine))
    {
        fileVec.push_back(oneLine+'\n');
    }
    mFile.close();
    return fileVec;
}

void FileInput::printFile()
{
    try
    {
        cout << fileToString() << endl;
    }
    catch (FileNotOpened e)
    {
        cout << e.what() << endl;
    }
}













