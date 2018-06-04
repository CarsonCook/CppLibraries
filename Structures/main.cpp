#include <iostream>
#include "List/Node.h"
#include "List/SinglyLinkedList.h"
#include<algorithm>
#include <vector>
#include <fstream>

using namespace std;

ofstream testOutput;

void simpleNodeTestSuite() {
    testOutput << "*************" << "TESTING SIMPLE NODE" << "*************" << endl;
    Node<int> n1(5);
    testOutput << "should be 5: " << n1.getData() << endl;
    testOutput << "should be 0: " << n1.hasNext() << endl;
    bool err = false;
    try {
        Node<int> e = *(n1.next());
    } catch (const NoNextPointer &e) {
        testOutput << e.what() << endl;
        err = true;
    }
    testOutput << "should be 1: " << err << endl;
    Node<int> n2(6);
    n1.setNext(&n2);
    testOutput << "should be 1: " << n1.hasNext() << endl;
    testOutput << "should be 6: " << n2.getData() << endl;
    testOutput << "should be 6: " << n1.next()->getData() << endl;
    n2.setData(8);
    testOutput << "should be 8: " << n2.getData() << endl;
    Node<int> n3(9);
    n2.setNext(&n3);
    testOutput << "should be 5 8 9: " << n1.getData() << " " << n1.next()->getData() << " "
               << n1.next()->next()->getData()
               << endl;
    testOutput << "*************" << "END" << "*************" << endl;
}

void singlyLinkedListTestSuite() {
    testOutput << "*************" << "TESTING SINGLY LINKED LIST" << "*************" << endl;
    SinglyLinkedList<int> s;
    testOutput << "should be 0: " << s.size() << endl;
    Node<int> node(4);
    s.insertEnd(node);
    node.setData(2);
    testOutput << "should be 4: " << s.listStart().getData() << endl;
    auto n = s.listStart();
    n.setData(1);
    testOutput << "should be 4: " << s.listStart().getData() << endl;
    testOutput << "should be 4: " << s.listEnd().getData() << endl;
    s.insertEnd(Node<int>(5));
    s.insertEnd(Node<int>(6));
    testOutput << "should see 4 5 6: ";
    for (SinglyLinkedList<int>::iterator i = s.begin(); i != s.end(); ++i) {
        testOutput << (*i).getData() << " ";
    }
    testOutput << endl;
    testOutput << "should see 4 5 6: ";
    for (const auto &v : s) {
        testOutput << v.getData() << " ";
    }
    testOutput << endl;
    SinglyLinkedList<int> s2;
    testOutput << "should see nothing: ";
    for (SinglyLinkedList<int>::iterator i = s2.begin(); i != s2.end(); ++i) {
        testOutput << (*i).getData() << " ";
    }
    testOutput << endl;
    testOutput << "should see nothing: ";
    for (const auto &v : s2) {
        testOutput << v.getData() << endl;
    }
    testOutput << endl;
    testOutput << "should be 1: " << s.isValueInList(4) << endl;
    testOutput << "should be 0: " << s.isValueInList(2) << endl;
    testOutput << "should get 5: ";
    n = s.findValueNode(5);
    testOutput << n.getData() << endl;
    testOutput << "should see error: ";
    try {
        s.findValueNode(2);
        testOutput << endl;
    } catch (const NoValueFoundListException &e) {
        testOutput << e.what() << endl;
    }
    testOutput << "should see data addresses and 4 5 6 on different lines:" << endl;
    testOutput << s << endl;
    s.sort();
    testOutput << "should see 4 5 6: ";
    for (const auto &v : s) {
        testOutput << v.getData() << " ";
    }
    testOutput << endl;
    SinglyLinkedList<int> list;
    list.insertEnd(Node<int>(5));
    list.insertEnd(Node<int>(3));
    list.insertEnd(Node<int>(7));
    list.insertEnd(Node<int>(4));
    list.sort();
    testOutput << "should see 3 4 5 6: ";
    for (const auto &v : list) {
        testOutput << v.getData() << " ";
    }
    testOutput << endl;
    list = SinglyLinkedList<int>();
    list.insertEnd(Node<int>(5));
    list.insertEnd(Node<int>(3));
    list.sort();
    testOutput << "should see 3 5: ";
    for (const auto &v : list) {
        testOutput << v.getData() << " ";
    }
    testOutput << endl;
    list = SinglyLinkedList<int>();
    list.insertEnd(Node<int>(3));
    list.insertEnd(Node<int>(5));
    testOutput << "should see 3 5: ";
    list.sort();
    for (const auto &v : list) {
        testOutput << v.getData() << " ";
    }
    testOutput << endl;
    list = SinglyLinkedList<int>();
    list.insertEnd(Node<int>(5));
    list.insertEnd(Node<int>(3));
    list.insertEnd(Node<int>(7));
    list.insertEnd(Node<int>(4));
    list.sort([](int a, int b) {
        return a > b;
    });
    testOutput << "should see 3 4 5 7: ";
    for (const auto &v : list) {
        testOutput << v.getData() << " ";
    }
    testOutput << endl;
    testOutput << "*************" << "END" << "*************" << endl;
}

int main() {
    testOutput.open("C:/Users/cookc/Desktop/Code/CppLibraries/Structures/testOutput.txt");
    if (!testOutput.is_open()) {
        cerr << "file couldn't open" << endl;
        return -1;
    }
    //simpleNodeTestSuite(testOutput);
    singlyLinkedListTestSuite();
    testOutput.close();
    return 0;
}