#pragma once

#include "Node.h"

class NoValueFoundListException : public std::exception {
public:
    const char *what() const noexcept override {
        return "Tried to find a value that isn't in the list!";
    }
};

template<class T>
class LinkedList {
protected:
    int length;
    Node<T> *start = nullptr;
    Node<T> *tail = nullptr;
    Node<T> *sentinel = new Node<T>(); //TODO find way to have default value, so no empty constructor

public:
    typedef bool (*LLComp)(T movingVal, T referenceVal);

    virtual ~LinkedList() {
        delete sentinel;
    }

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
        setCommonListValues(other.length, other.start, other.tail);
        (*this).sentinel = other.sentinel;
    }

    friend std::ostream &operator<<(std::ostream &os, const LinkedList &list) {
        for (LinkedList::iterator i = list.begin(); i != list.end(); ++i) {
            os << *i << std::endl;
        }
        return os;
    }

    void sort() {
        //sort data small to large by default
        sort([](T compareVal, T refVal) {
            return compareVal > refVal;
        });
    }

    void sort(LLComp shouldSwap) {
        //TODO switch from bubble sort
        if (isListSortable()) {
            for (LinkedList<T>::iterator i = begin(); i != end(); ++i) {
                for (LinkedList::iterator j = i + 1; j != end(); ++j) {
                    if (shouldSwap((*i).getData(), (*j).getData())) {
                        swapNodeData(&(*i), &(*j));
                    }
                }
            }
        }
    }

    void insertEnd(Node<T> newNode) {
        putEnd(&newNode);
        ++length;
    }

    void insertStart(Node<T> newNode) {
        putBegin(&newNode);
        ++length;
    }

    void insert(Node<T> *nodeBefore, Node<T> newNode) {
        put(nodeBefore, &newNode);
        ++length;
    }

    void deleteEnd() {
        removeEnd();
        --length;
    }

    void deleteStart() {
        removeBegin();
        --length;
    }

    void deleteMid(Node<T> *nodeBefore) {
        remove(nodeBefore);
        --length;
    }

private:
    void swapNodeData(Node<T> *node1, Node<T> *node2) {
        T temp = node1->getData();
        node1->setData(node2->getData());
        node2->setData(temp);
    }

    virtual void putEnd(Node<T> *newNode)=0;

    virtual void putBegin(Node<T> *newNode)=0;

    virtual void put(Node<T> *nodeBefore, Node<T> *newNode)=0;

    virtual void removeEnd()=0;

    virtual void removeBegin()=0;

    virtual void remove(Node<T> *nodeBefore)=0;

    bool isListSortable() const {
        return size() > 1;
    }

public:
    virtual Node<T> findValueNode(T value) {
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

    Node<T> listStart() const {
        return *start;
    }

    Node<T> listEnd() {
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
        Node<T> *ptr;

    public:
        explicit iterator(Node<T> *pointer) : ptr{pointer} {}

        iterator operator++() {
            iterator copy = *this;
            ptr = ptr->next();
            return copy;
        }

        iterator operator+(const int inc) {
            iterator newIterator = *this;
            for (int i = 0; i < inc; ++i) {
                ++newIterator;
            }
            return newIterator;
        }

        const iterator operator++(int) {
            ptr = ptr->next();
            return *this;
        }

        Node<T> &operator*() { return *ptr; }

        bool operator==(const iterator &other) {
            return ptr == other.ptr;
        }

        bool operator!=(const iterator &other) {
            return ptr != other.ptr;
        }
    };

    bool atTail(iterator it) const {
        return *it == *tail;
    }

    iterator begin() const {
        if (isListEmpty()) {
            return iterator(sentinel);
        }
        return iterator(start);
    }

    iterator end() const {
        return iterator(sentinel); //sentinel so that in loop end condition being i!=it.end(), still get tail node
    }

protected:
    void setCommonListValues(const int len, Node<T> *st, Node<T> *tl) {
        length = len;
        start = st;
        tail = tl;
    }
};
