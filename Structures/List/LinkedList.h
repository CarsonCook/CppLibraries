#pragma once

#include "Node.h"

class NoValueFoundListException : std::exception {
public:
    const char *what() const noexcept override {
        return "Tried to find a value that isn't in the list!";
    }
};

template<class T>
class LinkedList {
protected:
    int length;
    SimpleNode<T> *start = nullptr;
    SimpleNode<T> *tail = nullptr;
    SimpleNode<T> *sentinel = new SimpleNode<T>(); //TODO find way to have default value, so no empty constructor

public:
    virtual ~LinkedList() = default; //TODO delete stuff

    LinkedList() : length{0} {}

    LinkedList(const LinkedList &other) {
        length = other.length;
        start = other.start;
        tail = other.tail;
        sentinel = other.sentinel;
    }

    LinkedList &operator=(const LinkedList &other) {
        if (util::isSamePointer(this, &other)) {
            return *this;
        }
        setCommonValues(other.length, other.start, other.tail);
        (*this).sentinel = other.sentinel;
    }

    //TODO sort

    void insertEnd(SimpleNode<T> newNode) {
        putEnd(&newNode);
        ++length;
    }

private:
    virtual void putEnd(SimpleNode<T> *newNode)=0;

    virtual void putBegin(const SimpleNode<T> &newNode)=0;

    virtual void put(const SimpleNode<T> &nodeBefore, const SimpleNode<T> &newNode)=0;

    virtual void removeEnd()=0;

    virtual void removeBegin()=0;

    virtual void remove(const SimpleNode<T> &nodeBefore)=0;

public:
    virtual SimpleNode<T> findValueNode(T value) {
        for (auto node : *this) {
            if (node.getData() == value) {
                return node;
            }
        }
        throw NoValueFoundListException();
    }

    bool isValueInList(T value) {
        try {
            auto garbage = findValueNode(value);
            return true;
        } catch (const NoValueFoundListException &e) {
            return false;
        };
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

    bool isListEmpty() const {
        return size() == 0;
    }

    class iterator {
    private:
        SimpleNode<T> *ptr;

    public:
        //TODO - overload for sort
        explicit iterator(SimpleNode<T> *pointer) : ptr{pointer} {}

        iterator operator++() {
            iterator copy = *this;
            ptr = ptr->next();
            return copy;
        }

        const iterator operator++(int) {
            ptr = ptr->next();
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
        if (isListEmpty()) {
            return iterator(sentinel);
        }
        return iterator(start);
    }

    iterator end() {
        return iterator(sentinel); //sentinel so that in loop end condition being i!=it.end(), still get tail node
    }

protected:
    void setCommonValues(const int len, SimpleNode<T> *st, SimpleNode<T> *tl) {
        length = len;
        start = st;
        tail = tl;
    }
};
