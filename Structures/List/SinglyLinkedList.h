#pragma once

#include "Node.h"
#include "LinkedList.h"

template<class T>
class SinglyLinkedList : public LinkedList<T> {
public:
    virtual ~SinglyLinkedList() {}

    SinglyLinkedList() : LinkedList<T>::LinkedList() {}

    SinglyLinkedList &operator=(const SinglyLinkedList &other) {
        //TODO dry, same as parent minus type
        if (util::isSamePointer(this, &other)) {
            return *this;
        }
        (*this).length = other.length;
        (*this).start = other.start;
        (*this).tail = other.tail;
    }

private:
    void putEnd(SimpleNode<T> *newNode) override {
        if (util::isNullPointer(LinkedList<T>::start)) {//TODO clean ,islistempty, make arg pointer
            SimpleNode<T> *temp = new SimpleNode<T>(*newNode);
            LinkedList<T>::start = temp;
            LinkedList<T>::tail = temp;
            LinkedList<T>::tail->setNext(LinkedList<T>::sentinel);
        } else {
            LinkedList<T>::tail->setNext(newNode);
            LinkedList<T>::tail = LinkedList<T>::tail->next();
            LinkedList<T>::tail->setNext(LinkedList<T>::sentinel);
        }
    }

    void putBegin(const SimpleNode<T> &newNode) override {

    }

    void put(const SimpleNode<T> &nodeBefore, const SimpleNode<T> &newNode) override {

    }

    void removeEnd() override {

    }

    void removeBegin() override {

    }

    void remove(const SimpleNode<T> &nodeBefore) override {

    }
};