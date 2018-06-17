#pragma once

#include "Nodes/DoubleNode.h"
#include "LinkedList.h"

template<class T>
class DoublyLinkedList : public LinkedList<T, DoubleNode<T>> {
public:
    virtual ~DoublyLinkedList() {}

    DoublyLinkedList() : LL::LinkedList() {}

    DoublyLinkedList &operator=(const DoublyLinkedList<T> &other) {
        if (util::isSamePointer(this, &other)) {
            return *this;
        }
        LL::setCommonListValues(other.length, other.start, other.tail);
    }

private:
    typedef LinkedList<T, DoubleNode<T>> LL;

    void putEnd(DoubleNode<T> *newNode) override {
        LL::tail->setNext(newNode);
        newNode->setPrev(LL::tail);
        LL::tail = newNode;
        LL::tail->setNext(LL::sentinel);
    }

    void putBegin(DoubleNode<T> *newNode) override {
        newNode->setNext(LL::start);
        LL::start->setPrev(newNode);
        LL::start = newNode;
        newNode->setPrev(LL::sentinel);
    }

    void put(DoubleNode<T> *nodeBefore, DoubleNode<T> *newNode) override {
        if (nodeBefore->isPointingSameNode(LL::start)) {
            LL::setStartNextPointers(newNode);
            newNode->setPrev(LL::start);
        } else if (nodeBefore->isPointingSameNode(LL::tail)) {
            putEnd(newNode);
        } else {
            LL::setMidNextPointers(nodeBefore, newNode);
            setMidPrevPointers(nodeBefore, newNode);
        }
    }

    void setMidPrevPointers(DoubleNode<T> *nodeBefore, DoubleNode<T> *newNode) {
        DoubleNode<T> *newNodeNext = newNode->next();
        newNodeNext->setPrev(newNode);
        newNode->setPrev(nodeBefore);
    }

    void removeEnd() override {
        auto deleteNode = LL::tail;
        LL::tail = LL::tail->prev();
        LL::tail->setNext(LL::sentinel);
        delete deleteNode;
    }

    void removeBegin() override {
        auto deleteNode = LL::start;
        LL::start = LL::start->next();
        LL::start->setPrev(LL::sentinel);
        delete deleteNode;
    }

    void remove(DoubleNode<T> *nodeBefore) override {
        if (nodeBefore->isPointingSameNode(LL::tail)) {
            removeEnd();
        } else if (nodeBefore->isPointingSameNode(LL::start)) {
            LL::takeNodeOut(LL::start);
            LL::start->next()->setPrev(LL::start);
        } else {
            LL::takeNodeOut(nodeBefore);
            nodeBefore->next()->setPrev(nodeBefore);
        }
    }

public:
    class backIterator {
    private:
        DoubleNode<T> *ptr;

    public:
        explicit backIterator(DoubleNode<T> *pointer) : ptr{pointer} {}

        backIterator operator--() {
            backIterator copy = *this;
            ptr = ptr->prev();
            return copy;
        }

        backIterator operator-(const int inc) {
            backIterator newIterator = *this;
            for (int i = 0; i < inc; ++i) {
                --newIterator;
            }
            return newIterator;
        }

        const backIterator operator--(int) {
            ptr = ptr->prev();
            return *this;
        }

        DoubleNode<T> &operator*() { return *ptr; }

        bool operator==(const backIterator &other) {
            return ptr == other.ptr;
        }

        bool operator!=(const backIterator &other) {
            return ptr != other.ptr;
        }
    };

    backIterator backBegin() const{
        if (LL::isListEmpty()) {
            return backIterator(LL::sentinel);
        }
        return backIterator(LL::sentinel);
    }

    backIterator backEnd() const {
        return backIterator(LL::tail); //sentinel so that in loop end condition being i!=it.end(), still get tail node
    }
};