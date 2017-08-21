#include "../headers/file_io.h"
#include "../headers/file_io_exceptions.h"

FileOutput::FileOutput(const char *filePath) {
    mFilePath = filePath;
}

FileOutput::FileOutput(const FileOutput &other) {
    mFilePath = other.mFilePath;
    //can't copy file, also doesn't matter if file path is the same
}

FileOutput::~FileOutput() {
    if (mFile and mFile.is_open()) {
        mFile.close();
    }
    delete mFilePath;
    delete mFile;
}

void FileOutput::writeString(string output) {
    mFile.open(mFilePath);
    if (!mFile.is_open()) {
        throw FileNotOpened();
    }
    mFile << output;
    mFile.close();
}

void FileOutput::writeFile(const char *filePath) {
    FileInput inFile(filePath);
    mFile.open(mFilePath);
    if (!mFile.is_open()) {
        throw FileNotOpened();
    }
    mFile << inFile.fileToString();
    mFile.close();
}

void FileOutput::writeFile(FileInput &inFile) {
    mFile.open(mFilePath);
    if (!mFile.is_open()) {
        throw FileNotOpened();
    }
    mFile << inFile.fileToString();
    mFile.close();
}

FileOutput FileOutput::copy() {
    return FileOutput(*this);
}

bool FileOutput::operator==(const FileOutput &Ref) {
    return mFilePath ==
           Ref.mFilePath; //don't test mFile because if the paths are the same, the files will act on the same things
}

FileOutput operator=(const FileOutput &Ref) {
    this->mFilePath = Ref.mFilePath;
    return *this;
}