#pragma once

#include "Nodes/Node.h"
#include "LinkedList.h"

template<class T>
class SinglyLinkedList : public LinkedList<T, Node<T>> {
public:
    virtual ~SinglyLinkedList() {}

    SinglyLinkedList() : LL::LinkedList() {}

    SinglyLinkedList(const SinglyLinkedList &other) : LL::LinkedList(other) {}

    SinglyLinkedList &operator=(const SinglyLinkedList &other) {
        if (util::isSamePointer(this, &other)) {
            return *this;
        }
        LL::setCommonListValues(other.length, other.start, other.tail);
    }

private:
    typedef Node<T> DataNode;
    typedef LinkedList<T, DataNode> LL;

    void putBegin(DataNode *newNode) override {
        newNode->setNext(LL::start);
        LL::start = newNode;
    }

    void put(DataNode *nodeBefore, DataNode *newNode) override {
        if (nodeBefore->isPointingSameNode(LL::start)) {
            LL::setStartNextPointers(newNode);
        } else if (nodeBefore->isPointingSameNode(LL::tail)) {
            putEnd(newNode);
        } else {
            LL::setMidNextPointers(nodeBefore, newNode);
        }
    }

    void putEnd(DataNode *newNode) override {
        LL::tail->setNext(newNode);
        LL::tail = newNode;
        LL::tail->setNext(LL::sentinel);
    }

    void removeBegin() override {
        auto deleteNode = LL::start;
        LL::start = LL::start->next();
        delete deleteNode;
    }

    void remove(DataNode *nodeBefore) override {
        if (nodeBefore->isPointingSameNode(LL::tail)) {
            removeEnd();
        } else if (nodeBefore->isPointingSameNode(LL::start)) {
            LL::takeNodeOut(LL::start);
        } else {
            LL::takeNodeOut(nodeBefore);
        }
    }

    void removeEnd() override {
        DataNode *beforeTail = nodeBeforeTail();
        beforeTail->setNext(LL::sentinel);
        auto deleteNode = LL::tail;
        LL::tail = beforeTail;
        delete deleteNode;
    }

    DataNode *nodeBeforeTail() const {
        auto i = LL::begin();
        while (!LL::atTail(i + 1)) {
            ++i;
        }
        return &(*i);
    }
};