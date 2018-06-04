#pragma once

#include "Node.h"
#include "LinkedList.h"

template<class T>
class SinglyLinkedList : public LinkedList<T> {
public:
    virtual ~SinglyLinkedList() {}

    SinglyLinkedList() : LinkedList<T>::LinkedList() {}

    SinglyLinkedList &operator=(const SinglyLinkedList &other) {
        if (util::isSamePointer(this, &other)) {
            return *this;
        }
        LinkedList<T>::setCommonListValues(other.length, other.start, other.tail);
    }

private:
    void putEnd(Node<T> *newNode) override {
        if (LinkedList<T>::isListEmpty()) {
            initList(newNode);
        } else {
            incrementTail(newNode);
        }
        LinkedList<T>::tail->setNext(LinkedList<T>::sentinel);
    }

    void putBegin(Node<T> *newNode) override {
        newNode->setNext(LinkedList<T>::start);
        LinkedList<T>::start = newNode;
    }

    void put(Node<T> *nodeBefore, Node<T> *newNode) override {
        if (nodeBefore->isPointingSameNode(LinkedList<T>::start)) {
            putBegin(newNode);
        } else if (nodeBefore->isPointingSameNode(LinkedList<T>::tail)) {
            putEnd(newNode);
        } else {
            Node<T> *newNodeNext = nodeBefore->next();
            nodeBefore->setNext(newNode);
            newNode->setNext(newNodeNext);
        }
    }

    void removeEnd() override {
        Node<T> *beforeTail = nodeBeforeTail();
        beforeTail->setNext(LinkedList<T>::sentinel);
        auto deleteNode = LinkedList<T>::tail;
        LinkedList<T>::tail = beforeTail;
        delete deleteNode;
    }

    Node<T> *nodeBeforeTail() const {
        auto i = LinkedList<T>::begin();
        while (!LinkedList<T>::atTail(i + 1)) {
            ++i;
        }
        return &(*i);
    }

    void removeBegin() override {
        auto deleteNode = LinkedList<T>::start;
        LinkedList<T>::start = LinkedList<T>::start->next();
        delete deleteNode;
    }

    void remove(Node<T> *nodeBefore) override {
        if (nodeBefore->isPointingSameNode(LinkedList<T>::tail)) {
            removeEnd();
        } else if (nodeBefore->isPointingSameNode(LinkedList<T>::start)) {
            removeBegin();
        } else {
            auto deleteNode = nodeBefore->next();
            nodeBefore->setNext(deleteNode->next());
        }
    }

    void initList(Node<T> *newNode) {
        LinkedList<T>::start = newNode;
        LinkedList<T>::tail = newNode;
    }

    void incrementTail(Node<T> *newNode) {
        LinkedList<T>::tail->setNext(newNode);
        LinkedList<T>::tail = LinkedList<T>::tail->next();
    }
};