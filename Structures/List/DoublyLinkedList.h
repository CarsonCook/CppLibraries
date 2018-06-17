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
        newNode->setNext(LinkedList<T, DoubleNode<T>>::start);
        LinkedList<T, DoubleNode<T>>::start->setPrev(newNode);
        LinkedList<T, DoubleNode<T>>::start = newNode;
    }

    void put(DoubleNode<T> *nodeBefore, DoubleNode<T> *newNode) override {
        if (nodeBefore->isPointingSameNode(LinkedList<T, DoubleNode<T>>::start)) {
            newNode->setNext(LinkedList<T, DoubleNode<T>>::start->next());
            LinkedList<T, DoubleNode<T>>::start->setNext(newNode);
            newNode->setPrev(LinkedList<T, DoubleNode<T>>::start);
        } else if (nodeBefore->isPointingSameNode(LinkedList<T, DoubleNode<T>>::tail)) {
            putEnd(newNode);
        } else {
            DoubleNode<T> *newNodeNext = nodeBefore->next();
            nodeBefore->setNext(newNode);
            newNode->setNext(newNodeNext);
            newNodeNext->setPrev(newNode);
            newNode->setPrev(nodeBefore);
        }
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