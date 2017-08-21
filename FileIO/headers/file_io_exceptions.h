#ifndef FILEIO_FILE_IO_EXCEPTIONS_H
#define FILEIO_FILE_IO_EXCEPTIONS_H

#include <exception>

class FileNotOpened : public std::exception
{
public:
    virtual const char* what() throw()
    {
        return "File could not be opened - doesn't exist or is corrupted";
    }
};

#endif