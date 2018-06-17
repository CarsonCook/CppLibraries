#pragma once

#include "Nodes/Node.h"
#include "LinkedList.h"

template<class T, class NodeType>
class SinglyLinkedList : public LinkedList<T, NodeType> {
public:
    virtual ~SinglyLinkedList() {}

    SinglyLinkedList() : LinkedList<T, NodeType>::LinkedList() {}

    SinglyLinkedList &operator=(const SinglyLinkedList &other) {
        if (util::isSamePointer(this, &other)) {
            return *this;
        }
        LinkedList<T, NodeType>::setCommonListValues(other.length, other.start, other.tail);
    }

private:
    void putEnd(Node<T> *newNode) override {
        if (LinkedList<T, NodeType>::isListEmpty()) {
            initList(newNode);
        } else {
            incrementTail(newNode);
        }
        LinkedList<T, NodeType>::tail->setNext(LinkedList<T, NodeType>::sentinel);
    }

    void putBegin(Node<T> *newNode) override {
        newNode->setNext(LinkedList<T, NodeType>::start);
        LinkedList<T, NodeType>::start = newNode;
    }

    void put(Node<T> *nodeBefore, Node<T> *newNode) override {
        if (nodeBefore->isPointingSameNode(LinkedList<T, NodeType>::start)) {
            putBegin(newNode);
        } else if (nodeBefore->isPointingSameNode(LinkedList<T, NodeType>::tail)) {
            putEnd(newNode);
        } else {
            Node<T> *newNodeNext = nodeBefore->next();
            nodeBefore->setNext(newNode);
            newNode->setNext(newNodeNext);
        }
    }

    void removeEnd() override {
        Node<T> *beforeTail = nodeBeforeTail();
        beforeTail->setNext(LinkedList<T, NodeType>::sentinel);
        auto deleteNode = LinkedList<T, NodeType>::tail;
        LinkedList<T, NodeType>::tail = beforeTail;
        delete deleteNode;
    }

    Node<T> *nodeBeforeTail() const {
        auto i = LinkedList<T, NodeType>::begin();
        while (!LinkedList<T, NodeType>::atTail(i + 1)) {
            ++i;
        }
        return &(*i);
    }

    void removeBegin() override {
        auto deleteNode = LinkedList<T, NodeType>::start;
        LinkedList<T, NodeType>::start = LinkedList<T, NodeType>::start->next();
        delete deleteNode;
    }

    void remove(Node<T> *nodeBefore) override {
        if (nodeBefore->isPointingSameNode(LinkedList<T, NodeType>::tail)) {
            removeEnd();
        } else if (nodeBefore->isPointingSameNode(LinkedList<T, NodeType>::start)) {
            removeBegin();
        } else {
            auto deleteNode = nodeBefore->next();
            nodeBefore->setNext(deleteNode->next());
        }
    }

    void initList(Node<T> *newNode) {
        LinkedList<T, NodeType>::start = newNode;
        LinkedList<T, NodeType>::tail = newNode;
    }

    void incrementTail(Node<T> *newNode) {
        LinkedList<T, NodeType>::tail->setNext(newNode);
        LinkedList<T, NodeType>::tail = LinkedList<T, NodeType>::tail->next();
    }
};