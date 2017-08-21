cmake_minimum_required(VERSION 3.8)
project(FileIO)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES headers/file_io.h headers/file_io_exceptions.h sources/file_input.cpp sources/file_output.cpp tester.cpp)
add_executable(FileIO ${SOURCE_FILES})