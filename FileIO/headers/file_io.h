#ifndef FILEIO_FILE_IO_H
#define FILEIO_FILE_IO_H

#include <fstream>
#include <vector>

using namespace std;

typedef vector<string> svec;

class FileInput {
public:
    ///constructors and destructors
    explicit FileInput(const char *filePath);
    FileInput(const FileInput &other);
    ~FileInput(); //make sure file is closed, delete file path

    ///read from file functions
    string fileToString();

    svec fileToStringVector();
    void printFile();
    FileInput copy();

    ///operators
    bool operator==(const FileInput &Ref);
    FileInput& operator=(const FileInput &Ref);

private:
    const char *mFilePath;
    ifstream mFile;
};

class FileOutput {
public:
    ///constructors and destructors
    FileOutput(const char *filePath); //will create file if it does not exist
    FileOutput(const FileOutput &other);
    ~FileOutput();

    ///write to file functions
    void writeString(string output);
    void writeFile(const char *filePath);
    void writeFile(FileInput &inFile);
    FileOutput copy();

    ///operators
    bool operator==(const FileOutput &Ref);
    FileOutput& operator=(const FileOutput &Ref);

private:
    const char *mFilePath;
    ofstream mFile;
};

#endif
