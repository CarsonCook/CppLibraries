#pragma once

#include "Nodes/Node.h"
#include "LinkedList.h"

template<class T>
class SinglyLinkedList : public LinkedList<T, Node<T>> {
public:
    virtual ~SinglyLinkedList() {}

    SinglyLinkedList() : LL::LinkedList() {}

    SinglyLinkedList &operator=(const SinglyLinkedList &other) {
        if (util::isSamePointer(this, &other)) {
            return *this;
        }
        LL::setCommonListValues(other.length, other.start, other.tail);
    }

private:
    typedef LinkedList<T, Node<T>> LL;

    void putEnd(Node<T> *newNode) override {
        LL::tail->setNext(newNode);
        LL::tail = newNode;
        LL::tail->setNext(LL::sentinel);
    }

    void putBegin(Node<T> *newNode) override {
        newNode->setNext(LL::start);
        LL::start = newNode;
    }

    void put(Node<T> *nodeBefore, Node<T> *newNode) override {
        if (nodeBefore->isPointingSameNode(LL::start)) {
            LL::setStartNextPointers(newNode);
        } else if (nodeBefore->isPointingSameNode(LL::tail)) {
            putEnd(newNode);
        } else {
            LL::setMidNextPointers(nodeBefore, newNode);
        }
    }

    void removeEnd() override {
        Node<T> *beforeTail = nodeBeforeTail();
        beforeTail->setNext(LL::sentinel);
        auto deleteNode = LL::tail;
        LL::tail = beforeTail;
        delete deleteNode;
    }

    Node<T> *nodeBeforeTail() const {
        auto i = LL::begin();
        while (!LL::atTail(i + 1)) {
            ++i;
        }
        return &(*i);
    }

    void removeBegin() override {
        auto deleteNode = LL::start;
        LL::start = LL::start->next();
        delete deleteNode;
    }

    void remove(Node<T> *nodeBefore) override {
        if (nodeBefore->isPointingSameNode(LL::tail)) {
            removeEnd();
        } else if (nodeBefore->isPointingSameNode(LL::start)) {
            auto deleteNode = LL::start->next();
            LL::start->setNext(deleteNode->next());
            delete deleteNode;
        } else {
            auto deleteNode = nodeBefore->next();
            nodeBefore->setNext(deleteNode->next());
            delete deleteNode;
        }
    }
};