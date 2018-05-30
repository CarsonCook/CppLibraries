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
        SimpleNode<int> e = *(n1.next());
    } catch (const NoNextPointer &e) {
        cout << e.what() << endl;
        err = true;
    }
    cout << "should be 1: " << err << endl;
    SimpleNode<int> n2(6);
    n1.setNext(&n2);
    cout << "should be 1: " << n1.hasNext() << endl;
    cout << "should be 6: " << n2.getData() << endl;
    cout << "should be 6: " << n1.next()->getData() << endl;
    n2.setData(8);
    cout << "should be 8: " << n2.getData() << endl;
    SimpleNode<int> n3(9);
    n2.setNext(&n3);
    cout << "should be 5 8 9: " << n1.getData() << " " << n1.next()->getData() << " " << n1.next()->next()->getData() << endl;
    cout << "*************" << "END" << "*************" << endl;
}

void singlyLinkedListTestSuite() {
    cout << "*************" << "TESTING SINGLY LINKED LIST" << "*************" << endl;
    SinglyLinkedList<int> s;
    cout << "should be 0: " << s.size() << endl;
    s.insertEnd(SimpleNode<int>(4));
    auto n = s.listStart();
    n.setData(1);
    cout << "should be 4: " << s.listStart().getData() << endl;
    cout << "should be 4: " << s.listEnd().getData() << endl;
    s.insertEnd(SimpleNode<int>(5));
    s.insertEnd(SimpleNode<int>(6));
    /*for (SinglyLinkedList<int>::iterator i = s.begin(); i != s.end(); ++i) {
        cout << (*i).getData() << endl;
    }*/
    n = s.listStart();
    cout << n.getData() << endl;
    n = *(n.next());
    cout << n.getData() << endl;
    n = *(n.next());
    cout << n.getData() << endl;
    cout << "*************" << "END" << "*************" << endl;
}

int main() {
    //simpleNodeTestSuite();
    singlyLinkedListTestSuite();
    return 0;
}