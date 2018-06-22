cmake_minimum_required(VERSION 3.10)
project(Structures)

set(CMAKE_CXX_STANDARD 11)

add_executable(Structures main.cpp List/Nodes/Node.h List/SinglyLinkedList.h List/LinkedList.h util.cpp List/Nodes/DoubleNode.h List/DoublyLinkedList.h List/LinkedListExceptions.h List/LinkedListTestSuite.h)