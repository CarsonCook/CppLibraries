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
