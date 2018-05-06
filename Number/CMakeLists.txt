cmake_minimum_required(VERSION 3.8)
project(Number)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Number.cpp Number.h NumberOperators.cpp)
add_executable(Number ${SOURCE_FILES})