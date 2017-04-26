#ifndef FileIO_hh
#define FileIO_hh

#include "FileIOExceptions.hh"
#include <fstream>
#include <vector>

using namespace std;

typedef vector<string> svec;

class FileInput
{
public:
    ///constructors and destructors
    FileInput(const char *filePath);
    FileInput(const FileInput &other);
    ~FileInput(); //make sure file is closed, delete file path

    ///read from file functions
    string fileToString();
    svec fileToStringVector();
    void printFile();

    FileInput copyFileInput();

    ///operators
    bool operator == (const FileInput &Ref);

private:
    const char *mFilePath;
    ifstream mFile;
};

class FileOutput
{
public:
    ///constructors and destructors
    FileOutput(const char *filePath); //will create file if it does not exist
    FileOutput(const FileOutput &other);
    ~FileOutput();

    ///write to file functions
    void writeString(string output);
    void writeFile(const char *filePath);
    void writeFile(FileInput &inFile);

    FileOutput copyFileOutput();

    ///operators
    bool operator == (const FileOutput &Ref);

private:
    const char *mFilePath;
    ofstream mFile;
};

#endif // FileIO_hh
