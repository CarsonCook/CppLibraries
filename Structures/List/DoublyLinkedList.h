#pragma once

#include "Nodes/DoubleNode.h"
#include "LinkedList.h"

template<class T>
class DoublyLinkedList : public LinkedList<T, DoubleNode<T>> {
public:
    virtual ~DoublyLinkedList() {}

    DoublyLinkedList() : LL::LinkedList() {}

    DoublyLinkedList &operator=(const DoublyLinkedList &other) {
        if (util::isSamePointer(this, &other)) {
            return *this;
        }
        LL::setCommonListValues(other.length, other.start, other.tail);
    }

private:
    typedef LinkedList<T, DoubleNode<T>> LL;

    void putEnd(DoubleNode<T> *newNode) override {
        LL::tail->setNext(newNode);
        newNode->setPrev(LL::tail);
        LL::tail = newNode;
        LL::tail->setNext(LL::sentinel);
    }

    void putBegin(DoubleNode<T> *newNode) override {
        newNode->setNext(LL::start);
        LL::start->setPrev(newNode);
        LL::start = newNode;
    }

    void put(DoubleNode<T> *nodeBefore, DoubleNode<T> *newNode) override {
        if (nodeBefore->isPointingSameNode(LL::start)) {
            newNode->setNext(LL::start->next());
            LL::start->setNext(newNode);
            newNode->setPrev(LL::start);
        } else if (nodeBefore->isPointingSameNode(LL::tail)) {
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
};