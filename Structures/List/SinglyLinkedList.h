#pragma once

#include "Nodes/Node.h"
#include "LinkedList.h"

template<class T>
class SinglyLinkedList : public LinkedList<T, Node<T>> {
public:
    virtual ~SinglyLinkedList() {}

    SinglyLinkedList() : LinkedList<T, Node<T>>::LinkedList() {}

    SinglyLinkedList &operator=(const SinglyLinkedList &other) {
        if (util::isSamePointer(this, &other)) {
            return *this;
        }
        LinkedList<T, Node<T>>::setCommonListValues(other.length, other.start, other.tail);
    }

private:
    void putEnd(Node<T> *newNode) override {
        LinkedList<T, Node<T>>::tail->setNext(newNode);
        LinkedList<T, Node<T>>::tail = newNode;
        LinkedList<T, Node<T>>::tail->setNext(LinkedList<T, Node<T>>::sentinel);
    }

    void putBegin(Node<T> *newNode) override {
        newNode->setNext(LinkedList<T, Node<T>>::start);
        LinkedList<T, Node<T>>::start = newNode;
    }

    void put(Node<T> *nodeBefore, Node<T> *newNode) override {
        if (nodeBefore->isPointingSameNode(LinkedList<T, Node<T>>::start)) {
            newNode->setNext(LinkedList<T, Node<T>>::start->next());
            LinkedList<T, Node<T>>::start->setNext(newNode);
        } else if (nodeBefore->isPointingSameNode(LinkedList<T, Node<T>>::tail)) {
            putEnd(newNode);
        } else {
            Node<T> *newNodeNext = nodeBefore->next();
            nodeBefore->setNext(newNode);
            newNode->setNext(newNodeNext);
        }
    }

    void removeEnd() override {
        Node<T> *beforeTail = nodeBeforeTail();
        beforeTail->setNext(LinkedList<T, Node<T>>::sentinel);
        auto deleteNode = LinkedList<T, Node<T>>::tail;
        LinkedList<T, Node<T>>::tail = beforeTail;
        delete deleteNode;
    }

    Node<T> *nodeBeforeTail() const {
        auto i = LinkedList<T, Node<T>>::begin();
        while (!LinkedList<T, Node<T>>::atTail(i + 1)) {
            ++i;
        }
        return &(*i);
    }

    void removeBegin() override {
        auto deleteNode = LinkedList<T, Node<T>>::start;
        LinkedList<T, Node<T>>::start = LinkedList<T, Node<T>>::start->next();
        delete deleteNode;
    }

    void remove(Node<T> *nodeBefore) override {
        if (nodeBefore->isPointingSameNode(LinkedList<T, Node<T>>::tail)) {
            removeEnd();
        } else if (nodeBefore->isPointingSameNode(LinkedList<T, Node<T>>::start)) {
            removeBegin();
        } else {
            auto deleteNode = nodeBefore->next();
            nodeBefore->setNext(deleteNode->next());
        }
    }
};