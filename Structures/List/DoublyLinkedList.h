#pragma once

#include "Nodes/DoubleNode.h"
#include "LinkedList.h"

template<class T>
class DoublyLinkedList : public LinkedList<T, DoubleNode<T>> {

public:
    virtual ~DoublyLinkedList() {}

    DoublyLinkedList() : LL::LinkedList() {}

    explicit DoublyLinkedList(const DoublyLinkedList<int> &other) : LL::LinkedList(other) {}

    DoublyLinkedList &operator=(const DoublyLinkedList<T> &other) {
        if (util::isSamePointer(this, &other)) {
            return *this;
        }
        LL::setCommonListValues(other.length, other.start, other.tail);
    }

    friend std::ostream &operator<<(std::ostream &os, const DoublyLinkedList<T> &list) {
        for (typename LL::iterator i = list.begin(); i != list.end(); ++i) {
            DoubleNode<T> node = *i;
            if (node.next() == list.sentinel) {
                os << "This: " << &node << " data: " << node.getData() << " next: SENTINEL" << " prev: " << node.prev()
                   << std::endl;
            } else if (node.prev() == list.sentinel) {
                os << "This: " << &node << " data: " << node.getData() << " next: " << node.next() << " prev: SENTINEL"
                   << std::endl;
            } else {
                os << node << std::endl;
            }
        }
        return os;
    }

private:
    typedef DoubleNode<T> DataNode;
    typedef LinkedList<T, DataNode> LL;

    void putBegin(DataNode *newNode) override {
        newNode->setNext(LL::start);
        LL::start->setPrev(newNode);
        LL::start = newNode;
        newNode->setPrev(LL::sentinel);
    }

    void put(DataNode *nodeBefore, DataNode *newNode) override {
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

    void setMidPrevPointers(DataNode *nodeBefore, DataNode *newNode) {
        DataNode *newNodeNext = newNode->next();
        newNodeNext->setPrev(newNode);
        newNode->setPrev(nodeBefore);
    }

    void putEnd(DataNode *newNode) override {
        LL::tail->setNext(newNode);
        newNode->setPrev(LL::tail);
        LL::tail = newNode;
        LL::tail->setNext(LL::sentinel);
    }

    void removeBegin() override {
        auto deleteNode = LL::start;
        LL::start = LL::start->next();
        LL::start->setPrev(LL::sentinel);
        delete deleteNode;
    }

    void remove(DataNode *nodeBefore) override {
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

    void removeEnd() override {
        auto deleteNode = LL::tail;
        LL::tail = LL::tail->prev();
        LL::tail->setNext(LL::sentinel);
        delete deleteNode;
    }

public:
    class backIterator {
    private:
        DataNode *ptr;

    public:
        explicit backIterator(DataNode *pointer) : ptr{pointer} {}

        backIterator operator--() {
            backIterator copy = *this;
            ptr = ptr->prev();
            return copy;
        }

        const backIterator operator--(int) {
            ptr = ptr->prev();
            return *this;
        }

        backIterator operator-(const int inc) {
            backIterator newIterator = *this;
            for (int i = 0; i < inc; ++i) {
                --newIterator;
            }
            return newIterator;
        }

        DataNode &operator*() { return *ptr; }

        bool operator==(const backIterator &other) {
            return ptr == other.ptr;
        }

        bool operator!=(const backIterator &other) {
            return ptr != other.ptr;
        }
    };

    backIterator backBegin() const {
        if (LL::isListEmpty()) {
            return backIterator(LL::sentinel);
        }
        return backIterator(LL::sentinel);
    }

    backIterator backEnd() const {
        return backIterator(LL::tail); //sentinel so that in loop end condition being i!=it.end(), still get tail node
    }
};