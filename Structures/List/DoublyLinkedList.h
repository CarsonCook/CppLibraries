#pragma once

#include "Nodes/DoubleNode.h"
#include "LinkedList.h"

template<class T>
class DoublyLinkedList : public LinkedList<T, DoubleNode<T>> {
public:
    virtual ~DoublyLinkedList() : LinkedList() {}

    DoublyLinkedList<T> :LinkedList<T, DoubleNode<T>>::LinkedList() {};

    DoublyLinkedList &operator=(const DoublyLinkedList &other) {
        if (util::isSamePointer(this, &other)) {
            return *this;
        }
        LinkedList<T, DoubleNode<T>>::setCommonListValues(other.length, other.start, other.tail);
    }

private:
    void putEnd(DoubleNode<T> *newNode) override {

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
};