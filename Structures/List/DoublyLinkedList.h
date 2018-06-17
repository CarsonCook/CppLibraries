#pragma once

#include "Nodes/DoubleNode.h"
#include "LinkedList.h"

template<class T>
class DoublyLinkedList : public LinkedList<T, DoubleNode> {
public:
    virtual ~DoublyLinkedList() : LinkedList() {}

    DoublyLinkedList<T> :LinkedList<T, DoubleNode>::LinkedList() {};

    DoublyLinkedList &operator=(const DoublyLinkedList &other) {
        if (util::isSamePointer(this, &other)) {
            return *this;
        }
        LinkedList<T, DoubleNode>::setCommonListValues(other.length, other.start, other.tail);
    }

private:
    void putEnd(Node<T> *newNode) override {
        newNode->setNext(start);
    }

    void putBegin(Node<T> *newNode) override {

    }

    void put(Node<T> *nodeBefore, Node<T> *newNode) override {

    }

    void removeEnd() override {

    }

    void removeBegin() override {

    }

    void remove(Node<T> *nodeBefore) override {

    }
};