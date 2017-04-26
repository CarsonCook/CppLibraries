#ifndef FileIOExceptions_hh
#define FileIOExceptions_hh

#include "FileIO.hh"
#include <exception>

class FileNotOpened : public std::exception
{
public:
    virtual const char* what() throw()
    {
        return "File could not be opened - doesn't exist or is corrupted";
    }
};

#endif // FileIOExceptions_hh
