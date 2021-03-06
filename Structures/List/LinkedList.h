#pragma once

#include <ostream>
#include "Nodes/Node.h"
#include "LinkedListExceptions.h"

template<class T, class NodeType>
class LinkedList {
protected:
    int length;
    NodeType *start = nullptr;
    NodeType *tail = nullptr;
    NodeType *sentinel = new NodeType();

public:
    typedef bool (*LLComp)(T currentlyEarlier, T currentlyLater);

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
            NodeType node = *i;
            if (node.next() == list.sentinel) {
                os << "This: " << &node << " data: " << node.getData() << " next: SENTINEL" << std::endl;
            } else {
                os << node << std::endl;
            }
        }
        return os;
    }

    void sort() {
        //sort data small to large by default
        sort([](T compareVal, T refVal) {
            return compareVal > refVal;
        });
    }

    void sort(LLComp isLeftArgEarlier) {
        //bubble sort fine - need to iterate through list to get middle nodes
        //that are needed for faster search algorithms
        if (isListSortable()) {
            for (LinkedList<T, NodeType>::iterator i = begin(); i != end(); ++i) {
                bool madeSwap = false;
                for (LinkedList::iterator j = i + 1; j != end(); ++j) {
                    if (isLeftArgEarlier((*i).getData(), (*j).getData())) {
                        swapNodeData(&(*i), &(*j));
                        madeSwap = true;
                    }
                }
                if (!madeSwap) {
                    return;
                }
            }
        }
    }

    void insertStart(NodeType newNode) {
        putBegin(&newNode);
        ++length;
    }

    void insert(NodeType *nodeBefore, NodeType newNode) {
        if (isNotInList(nodeBefore)) {
            throw InsertNodeAfterNodeNotInList();
        }
        put(nodeBefore, &newNode);
        ++length;
    }

    void insertEnd(NodeType newNode) {
        if (isListEmpty()) {
            initList(&newNode);
        } else {
            putEnd(&newNode);
        }
        ++length;
    }

    void deleteStart() {
        if (isListEmpty()) {
            throw RemoveNodeEmptyList();
        }
        removeBegin();
        --length;
    }

    void deleteMid(NodeType *nodeBefore) {
        if (isListEmpty()) {
            throw RemoveNodeEmptyList();
        }
        if (isLastNode(nodeBefore)) {
            throw RemoveNodeAfterLast();
        }
        if (isNotInList(nodeBefore)) {
            throw RemoveNodeNotInList();
        }
        remove(nodeBefore);
        --length;
    }

    void deleteEnd() {
        if (isListEmpty()) {
            throw RemoveNodeEmptyList();
        }
        removeEnd();
        --length;
    }

    void clearList() {
        while (!isListEmpty()) {
            deleteEnd();
        }
    }

    virtual NodeType findNodeWithValue(T value) {
        for (auto node : *this) {
            if (node.getData() == value) {
                return node;
            }
        }
        throw NoValueFoundListException();
    }

    bool isValueInList(T value) {
        try {
            auto garbage = findNodeWithValue(value);
            return true;
        } catch (const NoValueFoundListException &e) {
            return false;
        };
    }

private:
    void initList(NodeType *newNode) {
        start = newNode;
        tail = newNode;
    }

    void swapNodeData(NodeType *node1, NodeType *node2) {
        T temp = node1->getData();
        node1->setData(node2->getData());
        node2->setData(temp);
    }

    virtual void putBegin(NodeType *newNode)=0;

    virtual void put(NodeType *nodeBefore, NodeType *newNode)=0;

    virtual void putEnd(NodeType *newNode)=0;

    virtual void removeBegin()=0;

    virtual void remove(NodeType *nodeBefore)=0;

    virtual void removeEnd()=0;

    bool isListSortable() const {
        return size() > 1;
    }

    bool isNotInList(const NodeType *nodeInQuestion) {
        for (const NodeType &eachNode : *this) {
            if (*nodeInQuestion == eachNode) {
                return false;
            }
        }
        return true;
    }

    bool isLastNode(const NodeType *nodeInQuestion) {
        return *tail == *nodeInQuestion;
    }

public:
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

        bool operator==(const iterator &other) const {
            return ptr == other.ptr;
        }

        bool operator!=(const iterator &other) const {
            return ptr != other.ptr;
        }
    };

    virtual iterator begin() const {
        if (isListEmpty()) {
            return iterator(sentinel);
        }
        return iterator(start);
    }

    iterator end() const {
        return iterator(sentinel); //sentinel so that in loop end condition being i!=it.end(), still get tail node
    }

protected:
    void takeNodeOut(NodeType *nodeBefore) {
        auto deleteNode = nodeBefore->next();
        nodeBefore->setNext(deleteNode->next());
        delete deleteNode;
    }

    void setStartNextPointers(NodeType *newNode) {
        newNode->setNext(start->next());
        start->setNext(newNode);
    }

    void setMidNextPointers(NodeType *nodeBefore, NodeType *newNode) {
        NodeType *newNodeNext = nodeBefore->next();
        nodeBefore->setNext(newNode);
        newNode->setNext(newNodeNext);
    }

    void setCommonListValues(const int len, NodeType *st, NodeType *tl) {
        length = len;
        start = st;
        tail = tl;
    }

    bool atTail(iterator it) const {
        return *it == *tail;
    }
};
