#include <iostream>
#include "List/Node.h"
#include "List/SinglyLinkedList.h"
#include<algorithm>

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
    cout << "should be 5 8 9: " << n1.getData() << " " << n1.next()->getData() << " " << n1.next()->next()->getData()
         << endl;
    cout << "*************" << "END" << "*************" << endl;
}

void singlyLinkedListTestSuite() {
    cout << "*************" << "TESTING SINGLY LINKED LIST" << "*************" << endl;
    SinglyLinkedList<int> s;
    cout << "should be 0: " << s.size() << endl;
    SimpleNode<int> node(4);
    s.insertEnd(node);
    node.setData(2);
    cout << "should be 4: " << s.listStart().getData() << endl;
    auto n = s.listStart();
    n.setData(1);
    cout << "should be 4: " << s.listStart().getData() << endl;
    cout << "should be 4: " << s.listEnd().getData() << endl;
    s.insertEnd(SimpleNode<int>(5));
    s.insertEnd(SimpleNode<int>(6));
    cout << "should see 4 5 6: ";
    for (SinglyLinkedList<int>::iterator i = s.begin(); i != s.end(); ++i) {
        cout << (*i).getData() << " ";
    }
    cout << endl;
    cout << "should see 4 5 6: ";
    for (const auto &v : s) {
        cout << v.getData() << " ";
    }
    cout << endl;
    SinglyLinkedList<int> s2;
    cout << "should see nothing: ";
    for (SinglyLinkedList<int>::iterator i = s2.begin(); i != s2.end(); ++i) {
        cout << (*i).getData() << " ";
    }
    cout << endl;
    cout << "should see nothing: ";
    for (const auto &v : s2) {
        cout << v.getData() << endl;
    }
    cout << endl;
    cout << "should be 1: " << s.isValueInList(4) << endl;
    cout << "should be 0: " << s.isValueInList(2) << endl;
    cout << "should get 5: ";
    n = s.findValueNode(5);
    cout << n.getData() << endl;
    cout << "should see error: ";
    try {
        s.findValueNode(2);
        cout << endl;
    } catch (const NoValueFoundListException &e) {
        cout << e.what() << endl;
    }
    cout << "should see 6 5 4: ";
    //TODO SORT
    cout << endl;
    cout << "*************" << "END" << "*************" << endl;
}

int main() {
    //simpleNodeTestSuite();
    singlyLinkedListTestSuite();
    return 0;
}