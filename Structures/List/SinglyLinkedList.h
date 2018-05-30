#pragma once

#include "Node.h"
#include "LinkedList.h"

class InsertNullNode : std::exception {
    const char *what() const noexcept override {
        return "Tried to insert a null Node!";
    }
};

template<class T>
class SinglyLinkedList : public LinkedList<T> {
public:
    virtual ~SinglyLinkedList() {}

    SinglyLinkedList() : LinkedList<T>::LinkedList() {}

    void insertEnd(const SimpleNode<T> &newNode) override {
        if (LinkedList<T>::start == nullptr) {
            LinkedList<T>::start = new SimpleNode<T>(newNode);
            LinkedList<T>::end = new SimpleNode<T>(newNode);
        } else {
            LinkedList<T>::end->setNext(newNode);
            SimpleNode<T> temp = LinkedList<T>::end->next();
            LinkedList<T>::end = new SimpleNode<T>(temp);
        }
    }

    void insertBegin(const SimpleNode<T> &newNode) override {}

    void insert(const SimpleNode<T> &nodeBefore, const SimpleNode<T> &newNode) override {}

    SinglyLinkedList &operator=(const SinglyLinkedList &other) {
        if (util::isSamePointer(this, &other)) {
            return *this;
        }
        (*this).length = other.length;
        (*this).start = other.start;
        (*this).end = other.end;
    }
};