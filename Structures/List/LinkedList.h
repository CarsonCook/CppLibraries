#pragma once

#include "Nodes/Node.h"

//TODO empty list testing and general edge cases (e.g. delete function where nodeBefore is last node)
//TODO throw exception for edge cases like nodeBefore being tail node

class NoValueFoundListException : public std::exception {
public:
    const char *what() const noexcept override {
        return "Tried to find a value that isn't in the list!";
    }
};

template<class T, class NodeType>
class LinkedList {
protected:
    int length;
    NodeType *start = nullptr;
    NodeType *tail = nullptr;
    NodeType *sentinel = new NodeType(); //TODO find way to have default value, so no empty constructor

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
            for (LinkedList<T, NodeType>::iterator i = begin(); i != end(); ++i) {
                for (LinkedList::iterator j = i + 1; j != end(); ++j) {
                    if (shouldSwap((*i).getData(), (*j).getData())) {
                        swapNodeData(&(*i), &(*j));
                    }
                }
            }
        }
    }

    void insertEnd(NodeType newNode) {
        if (isListEmpty()) {
            initList(&newNode);
        } else {
            putEnd(&newNode);
        }
        ++length;
    }

    void insertStart(NodeType newNode) {
        putBegin(&newNode);
        ++length;
    }

    void insert(NodeType *nodeBefore, NodeType newNode) {
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

    void deleteMid(NodeType *nodeBefore) {
        remove(nodeBefore);
        --length;
    }

private:
    void swapNodeData(NodeType *node1, NodeType *node2) {
        T temp = node1->getData();
        node1->setData(node2->getData());
        node2->setData(temp);
    }

    virtual void putEnd(NodeType *newNode)=0;

    virtual void putBegin(NodeType *newNode)=0;

    virtual void put(NodeType *nodeBefore, NodeType *newNode)=0;

    virtual void removeEnd()=0;

    virtual void removeBegin()=0;

    virtual void remove(NodeType *nodeBefore)=0;

    bool isListSortable() const {
        return size() > 1;
    }

    void initList(NodeType *newNode) {
        start = newNode;
        tail = newNode;
    }

public:
    virtual NodeType findValueNode(T value) {
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

    NodeType listStart() const {
        return *start;
    }

    NodeType listEnd() {
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
        NodeType *ptr;

    public:
        explicit iterator(NodeType *pointer) : ptr{pointer} {}

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

        NodeType &operator*() { return *ptr; }

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
    void setCommonListValues(const int len, NodeType *st, NodeType *tl) {
        length = len;
        start = st;
        tail = tl;
    }

    void setStartNextPointers(NodeType *newNode){
        newNode->setNext(start->next());
        start->setNext(newNode);
    }

    void setMidNextPointers(NodeType *nodeBefore, NodeType *newNode){
        NodeType *newNodeNext = nodeBefore->next();
        nodeBefore->setNext(newNode);
        newNode->setNext(newNodeNext);
    }
};
