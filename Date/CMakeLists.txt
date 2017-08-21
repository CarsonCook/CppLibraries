cmake_minimum_required(VERSION 3.8)
project(Date)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp headers/date_exceptions.h headers/date.h sources/date.cpp sources/date_operators.cpp)
add_executable(Date ${SOURCE_FILES})