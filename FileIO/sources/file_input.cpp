#include <iostream>
#include <vector>
#include "../headers/file_io.h"
#include "../headers/file_io_exceptions.h"

using namespace std;

/**
Constructors and destructors
*/

FileInput::FileInput(const char *filePath) {
    mFilePath = filePath;
}

FileInput::FileInput(const FileInput &other) {
    mFilePath = other.mFilePath;
    //can't copy file, also doesn't matter if file path is the same
}

FileInput::~FileInput() {
    if (mFile and mFile.is_open()) {
        mFile.close();
    }
    delete mFilePath;
    delete mFile;
}

/**
Functions to read file
*/

string FileInput::fileToString() {
    string sFile;
    mFile.open(mFilePath);
    if (!mFile.is_open()) {
        throw FileNotOpened();
    }
    string oneLine;
    while (getline(mFile, oneLine)) {
        sFile += (oneLine + (char) '\n');
    }
    mFile.close();
    return sFile;
}

svec FileInput::fileToStringVector() {
    svec fileVec;
    mFile.open(mFilePath);
    if (!mFile.is_open()) {
        throw FileNotOpened();
    }
    string oneLine;
    while (getline(mFile, oneLine)) {
        fileVec.push_back(oneLine + (char) '\n');
    }
    mFile.close();
    return fileVec;
}

void FileInput::printFile() {
    try {
        cout << fileToString() << endl;
    }
    catch (FileNotOpened &e) {
        cout << e.what() << endl;
    }
}

FileInput FileInput::copy() {
    return FileInput(*this);
}

bool FileInput::operator==(const FileInput &Ref) {
    return mFilePath ==
           Ref.mFilePath; //don't test mFile because if the paths are the same, the files will act on the same things
}

FileInput operator=(const FileInput &Ref) {
    this->mFilePath = Ref.mFilePath;
    return this;
}