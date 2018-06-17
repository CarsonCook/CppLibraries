#pragma once

#include "Nodes/DoubleNode.h"
#include "LinkedList.h"

template<class T>
class DoublyLinkedList : public LinkedList<T, DoubleNode<T>> {
public:
    virtual ~DoublyLinkedList() {}

    DoublyLinkedList() : LinkedList<T, DoubleNode<T>>::LinkedList() {}

    DoublyLinkedList &operator=(const DoublyLinkedList &other) {
        if (util::isSamePointer(this, &other)) {
            return *this;
        }
        LinkedList<T, DoubleNode<T>>::setCommonListValues(other.length, other.start, other.tail);
    }

private:
    void putEnd(DoubleNode<T> *newNode) override {
        LinkedList<T, DoubleNode<T>>::tail->setNext(newNode);
        newNode->setPrev(LinkedList<T, DoubleNode<T>>::tail);
        LinkedList<T, DoubleNode<T>>::tail = newNode;
    }

    void putBegin(DoubleNode<T> *newNode) override {

    }

    void put(DoubleNode<T> *nodeBefore, DoubleNode<T> *newNode) override {

    }

    void removeEnd() override {

    }

    void removeBegin() override {

    }

    void remove(DoubleNode<T> *nodeBefore) override {

    }

    void incrementTail(DoubleNode<T> *newNode) override {

    }
};