#include "FileIO.hh"

FileOutput::FileOutput(const char *filePath)
{
    mFilePath=filePath;
}

FileOutput::~FileOutput()
{
    if (mFile and mFile.is_open())
    {
        mFile.close();
    }
    delete mFilePath;
}

void FileOutput::writeString(string output)
{
    mFile.open(mFilePath);
    mFile << output;
    mFile.close();
}

void FileOutput::writeFile(const char *filePath)
{
    FileInput inFile(filePath);
    mFile.open(mFilePath);
    mFile << inFile.fileToString();
    mFile.close();
}

void FileOutput::writeFile(FileInput &inFile)
{
    mFile.open(mFilePath);
    mFile << inFile.fileToString();
    mFile.close();
}
