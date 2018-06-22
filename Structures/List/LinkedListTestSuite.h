#pragma once

#include <iostream>
#include "Nodes/Node.h"
#include "SinglyLinkedList.h"
#include "Nodes/DoubleNode.h"
#include "DoublyLinkedList.h"
#include "LinkedListExceptions.h"
#include "Nodes/DoubleNode.h"
#include "DoublyLinkedList.h"
#include "SinglyLinkedList.h"
#include <algorithm>
#include <vector>
#include <fstream>

using namespace std;

ofstream testOutput;

void simpleNodeTestSuite() {
    testOutput << "*************" << "TESTING SIMPLE NODE" << "*************" << endl;
    Node<int> n1(5);
    testOutput << "should be 5: " << n1.getData() << endl;
    testOutput << "should be 0: " << n1.hasNext() << endl;
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
    n = s.findNodeWithValue(5);
    testOutput << n.getData() << endl;

    testOutput << "should see error: ";
    try {
        s.findNodeWithValue(2);
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
    testOutput << "should see 3 4 5 7: ";
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

    list.insertStart(Node<int>(1));
    testOutput << "Should see 1 3 4 5 7: ";
    for (const auto &v : list) {
        testOutput << v.getData() << " ";
    }
    testOutput << endl;

    Node<int> start = list.listStart();
    list.insert(&start, Node<int>(0));
    testOutput << "Should see 1 0 3 4 5 7: ";
    for (const auto &v : list) {
        testOutput << v.getData() << " ";
    }
    testOutput << endl;

    Node<int> end = list.listEnd();
    list.insert(&end, Node<int>(8));
    testOutput << "Should see 1 0 3 4 5 7 8: ";
    for (const auto &v : list) {
        testOutput << v.getData() << " ";
    }
    testOutput << endl;

    list.insert(list.listStart().next(), Node<int>(2));
    testOutput << "Should see 1 0 2 3 4 5 7 8: ";
    for (const auto &v : list) {
        testOutput << v.getData() << " ";
    }
    testOutput << endl;

    list.deleteEnd();
    testOutput << "Should see 1 0 2 3 4 5 7: ";
    for (const auto &v : list) {
        testOutput << v.getData() << " ";
    }
    testOutput << endl;

    list.deleteStart();
    testOutput << "Should see 0 2 3 4 5 7: ";
    for (const auto &v : list) {
        testOutput << v.getData() << " ";
    }
    testOutput << endl;

    list.deleteMid(list.listStart().next());
    testOutput << "Should see 0 2 4 5 7: ";
    for (const auto &v : list) {
        testOutput << v.getData() << " ";
    }
    testOutput << endl;

    testOutput << "*************" << "END" << "*************" << endl;
}

void doubleNodeTestSuite() {
    DoubleNode<int> n1 = DoubleNode<int>(1);
    DoubleNode<int> n2 = DoubleNode<int>(2);
    DoubleNode<int> n3 = DoubleNode<int>(3);
    n1.setNext(&n2);
    n2.setNext(&n3);
    n2.setPrev(&n1);
    n3.setPrev(&n2);
    testOutput << "This: <address> data: <val> next: <address> prev: <address> 3 times, linking addresses" << endl;
    testOutput << n1 << endl;
    testOutput << n2 << endl;
    testOutput << n3 << endl;

}

void doublyLinkedListTestSuite() {
    auto *list = new DoublyLinkedList<int>();
    testOutput << "Should be 0: " << (*list).size() << endl;
    DoubleNode<int> n(1);
    (*list).insertEnd(n);
    testOutput << "Should be 1: " << (*list).size() << endl;
    testOutput << "Should be 1: " << (*list).listStart().getData() << endl;
    DoubleNode<int> n2(2);
    (*list).insertEnd(n2);
    testOutput << "Should be 2: " << (*list).listStart().next()->getData() << endl;
    testOutput << "Should be 1: " << (*list).listStart().next()->prev()->getData() << endl;
    DoubleNode<int> n3(3);
    (*list).insertStart(n3);
    testOutput << "Should be 3: " << (*list).listStart().getData() << endl;
    DoubleNode<int> n4(4);
    DoubleNode<int> *randomNode = (*list).listStart().next();
    (*list).insert(randomNode, n4);
    testOutput << "Should see 3 1 4 2: ";
    for (const auto &v : (*list)) {
        testOutput << v.getData() << " ";
    }
    testOutput << endl;
    (*list).deleteEnd();
    testOutput << "Should see 3 1 4: ";
    for (const auto &v : (*list)) {
        testOutput << v.getData() << " ";
    }
    testOutput << endl;
    (*list).deleteStart();

    testOutput << "Should see 1 4: ";
    for (const auto &v : (*list)) {
        testOutput << v.getData() << " ";
    }
    testOutput << endl;

    DoubleNode<int> n6(6);
    (*list).insertEnd(n6);
    DoubleNode<int> node = (*list).listStart();
    (*list).deleteMid(&node);
    testOutput << "Should see 1 6: ";
    for (const auto &v : (*list)) {
        testOutput << v.getData() << " ";
    }
    testOutput << endl;

    DoubleNode<int> n7(7);
    (*list).insertEnd(n4);
    (*list).insertEnd(n7);
    auto node2 = (*list).listStart().next();
    (*list).deleteMid(node2);
    testOutput << "Should see 1 6 7: ";
    for (const auto &v : (*list)) {
        testOutput << v.getData() << " ";
    }
    testOutput << endl;

    testOutput << "Should see 7 6 1: ";
    for (DoublyLinkedList<int>::backIterator i = (*list).backEnd(); i != (*list).backBegin(); --i) {
        testOutput << (*i).getData() << " ";
    }
    testOutput << endl;

    testOutput << "Should see This: <address> data: <val> prev: <address> next: <address> for whole list" << endl;
    testOutput << (*list) << endl;

    testOutput << "Should see error: ";
    DoubleNode<int> notIn(123);
    try {
        (*list).insert(&notIn, n4);
    } catch (const InsertNodeAfterNodeNotInList &e) {
        testOutput << e.what() << endl;
    }

    testOutput << "Should see error: ";
    DoublyLinkedList<int> emptyList;
    try {
        emptyList.deleteStart();
    } catch (const RemoveNodeEmptyList &e) {
        testOutput << e.what() << endl;
    }
    testOutput << "Should see error: ";
    try {
        emptyList.deleteEnd();
    } catch (const RemoveNodeEmptyList &e) {
        testOutput << e.what() << endl;
    }
    testOutput << "Should see error: ";
    try {
        emptyList.deleteMid(&n4);
    } catch (const RemoveNodeEmptyList &e) {
        testOutput << e.what() << endl;
    }
    testOutput << "Should see error: ";
    try {
        (*list).deleteMid(&notIn);
    } catch (const RemoveNodeNotInList &e) {
        testOutput << e.what() << endl;
    }
    testOutput << "Should see error: ";
    try {
        auto ender = (*list).listEnd();
        (*list).deleteMid(&ender);
    } catch (const RemoveNodeAfterLast &e) {
        testOutput << e.what() << endl;
    }

    DoublyLinkedList<int> copy(*list);
    testOutput << "Should see " << endl << (*list) << "again:" << endl;
    testOutput << copy << endl;

    testOutput << "Should see 0 1: " << (*list).isListEmpty();
    (*list).clearList();
    testOutput << " " << (*list).isListEmpty() << endl;

    testOutput << "~~~~~~~~~~~~~~~~END~~~~~~~~~~~~~~~~" << endl;
    delete list;
}