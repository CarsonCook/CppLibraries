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
    SimpleNode<T> *tail = nullptr;

public:
    virtual ~LinkedList() = default;

    LinkedList() : length{0} {}

    LinkedList(const LinkedList &other) {
        length = other.length;
        start = other.start;
        tail = other.tail;
    }

    LinkedList &operator=(const LinkedList &other) {
        if (util::isSamePointer(this, &other)) {
            return *this;
        }
        (*this).length = other.length;
        (*this).start = other.start;
        (*this).tail = other.tail;
    }

    virtual void insertEnd(SimpleNode<T> newNode)=0;

    virtual void insertBegin(const SimpleNode<T> &newNode)=0;

    virtual void insert(const SimpleNode<T> &nodeBefore, const SimpleNode<T> &newNode)=0;

    virtual void deleteEnd()=0;

    virtual void deleteBegin()=0;

    virtual void deleteMid(const SimpleNode<T> &nodeBefore)=0;

    SimpleNode<T> findValueNode(T value) {
        //TODO implement, throw exception if not found
    }

    bool isValueInList(T value) {
        //TODO implement
    }

    SimpleNode<T> listStart() const {
        return *start;
    }

    SimpleNode<T> listEnd() {
        return *tail;
    }

    int size() const {
        return length;
    }

    class iterator {
    private:
        SimpleNode<T> *ptr;

    public:
        explicit iterator(SimpleNode<T> *pointer) : ptr{pointer} {}

        iterator operator++() {
            iterator copy = *this;
            ptr++;
            return copy;
        }

        const iterator operator++(int) {
            ptr++;
            return *this;
        }

        SimpleNode<T> &operator*() { return *ptr; }

        bool operator==(const iterator &other) {
            return ptr == other.ptr;
        }

        bool operator!=(const iterator &other) {
            return ptr != other.ptr;
        }
    };

    iterator begin() {
        return iterator(start);
    }

    iterator end() {
        return iterator(tail);
    }
};
