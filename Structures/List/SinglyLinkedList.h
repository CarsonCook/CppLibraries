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

    void putBegin(const Node<T> &newNode) override {

    }

    void put(const Node<T> &nodeBefore, const Node<T> &newNode) override {

    }

    void removeEnd() override {

    }

    void removeBegin() override {

    }

    void remove(const Node<T> &nodeBefore) override {

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