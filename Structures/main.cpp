#include "List/LinkedListTestSuite.h"

int main() {
    testOutput.open("C:/Users/cookc/Desktop/Code/CppLibraries/Structures/testOutput.txt");
    if (!testOutput.is_open()) {
        cerr << "file couldn't open" << endl;
        return -1;
    }
    simpleNodeTestSuite();
    singlyLinkedListTestSuite();
    doubleNodeTestSuite();
    doublyLinkedListTestSuite();
    testOutput.close();
    return 0;
}