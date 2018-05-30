#pragma once

#include "Node.h"

class ListIterator {
public:

};

template<class T>
class LinkedList {
protected:
    int length;
    SimpleNode<T> *start = nullptr;
    SimpleNode<T> *end = nullptr;

public:
    virtual ~LinkedList() = default;

    LinkedList() : length{0} {}

    LinkedList(const LinkedList &other) {
        length = other.length;
        start = other.start;
        end = other.end;
    }

    LinkedList &operator=(const LinkedList &other) {
        if (util::isSamePointer(this, &other)) {
            return *this;
        }
        (*this).length = other.length;
        (*this).start = other.start;
        (*this).end = other.end;
    }

    virtual void insertEnd(const SimpleNode<T> &newNode)=0;

    virtual void insertBegin(const SimpleNode<T> &newNode)=0;

    virtual void insert(const SimpleNode<T> &nodeBefore, const SimpleNode<T> &newNode)=0;

    SimpleNode<T> findValueNode(T value) {
        //TODO implement, throw exception if not found
    }

    bool isValueInList(T value) {
        //TODO implement
    }

    int size() const {
        return length;
    }
};
