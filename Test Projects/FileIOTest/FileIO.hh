#ifndef FileIO_hh
#define FileIO_hh

#include <fstream>
#include <vector>

using namespace std;

typedef vector<string> svec;

class FileInput
{
public:
    //constructors and destructors
    FileInput(const char *filePath);
    ~FileInput(); //make sure file is closed, delete file path

    //read from file functions
    string fileToString();
    svec fileToStringVector();
    void printFile();

private:
    const char *mFilePath;
    ifstream mFile;
};

#endif // FileIO_hh
