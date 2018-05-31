#pragma once

#include "Node.h"
#include "LinkedList.h"

template<class T>
class SinglyLinkedList : public LinkedList<T> {
public:
    virtual ~SinglyLinkedList() {}

    SinglyLinkedList() : LinkedList<T>::LinkedList() {}

    void insertEnd(SimpleNode<T> newNode) override {
        if (LinkedList<T>::start == nullptr) {//TODO clean
            SimpleNode<T> *temp = new SimpleNode<T>(newNode);
            LinkedList<T>::start = temp;
            LinkedList<T>::tail = temp;
            LinkedList<T>::tail->setNext(LinkedList<T>::sentinel);
        } else {
            LinkedList<T>::tail->setNext(&newNode);
            LinkedList<T>::tail = LinkedList<T>::tail->next();
            LinkedList<T>::tail->setNext(LinkedList<T>::sentinel);
        }
        ++LinkedList<T>::length;
    }

    void insertBegin(const SimpleNode<T> &newNode) override {

    }

    void insert(const SimpleNode<T> &nodeBefore, const SimpleNode<T> &newNode) override {

    }

    SinglyLinkedList &operator=(const SinglyLinkedList &other) {
        //TODO dry, same as parent minus type
        if (util::isSamePointer(this, &other)) {
            return *this;
        }
        (*this).length = other.length;
        (*this).start = other.start;
        (*this).tail = other.tail;
    }

    void deleteEnd() override {

    }

    void deleteBegin() override {

    }

    void deleteMid(const SimpleNode<T> &nodeBefore) override {

    }
};