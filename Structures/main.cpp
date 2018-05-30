#include <iostream>
#include "List/Node.h"
#include "List/SinglyLinkedList.h"

using namespace std;

void simpleNodeTestSuite() {
    cout << "*************" << "TESTING SIMPLE NODE" << "*************" << endl;
    SimpleNode<int> n1(5);
    cout << "should be 5: " << n1.getData() << endl;
    cout << "should be 0: " << n1.hasNext() << endl;
    bool err = false;
    try {
        SimpleNode<int> e = n1.next();
    } catch (const NoNextPointer &e) {
        cout << e.what() << endl;
        err = true;
    }
    cout << "should be 1: " << err << endl;
    SimpleNode<int> n2(6);
    n1.setNext(n2);
    cout << "should be 1: " << n1.hasNext() << endl;
    cout << "should be 6: " << n2.getData() << endl;
    cout << "should be 6: " << n1.next().getData() << endl;
    n2.setData(8);
    cout << "should be 8: " << n2.getData() << endl;
    cout << "*************" << "END" << "*************" << endl;
}

void singlyLinkedListTestSuite() {
    cout << "*************" << "TESTING SINGLY LINKED LIST" << "*************" << endl;
    SinglyLinkedList<int> s;
    cout << "should be 0: " << s.size() << endl;
    s.insertEnd(SimpleNode<int>(4));
    cout << "*************" << "END" << "*************" << endl;
}

int main() {
    //simpleNodeTestSuite();
    singlyLinkedListTestSuite();
    return 0;
}