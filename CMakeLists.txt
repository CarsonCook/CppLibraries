cmake_minimum_required(VERSION 3.8)
project(CppLibraries)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        sources/date.cpp
        sources/date_operators.cpp headers/date.h headers/date_exceptions.h tester.cpp)

add_executable(CppLibraries ${SOURCE_FILES})