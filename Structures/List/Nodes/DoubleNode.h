#pragma once

#include <ostream>
#include "Node.h"

template<class T>
class DoubleNode : public Node<T> {
private:
    DoubleNode<T> *prevNode = nullptr;

public:
    virtual ~DoubleNode() {}

    explicit DoubleNode(const T &newData) : Node<T>(newData) {}

    explicit DoubleNode() : Node<T>::Node() {}

    DoubleNode(const DoubleNode<T> &otherNode) : Node<T>(otherNode) {
        prevNode = otherNode.prevNode;
    }

    DoubleNode<T> &operator=(const DoubleNode<T> &other) {
        if (util::isSamePointer(this, &other)) {
            return *this;
        }
        prevNode = other.prevNode;
        Node<T>::setData(other.getData());
        Node<T>::setNext(other.next());
    }

    bool operator==(const DoubleNode<T> &other) const {
        return prevNode == other.prevNode && Node<T>::getData() == other.getData() && next() == other.next();
    }

    bool operator!=(const DoubleNode<T> &other) const {
        return !(*this == other);
    }

    friend std::ostream &operator<<(std::ostream &os, const DoubleNode<T> &node) {
        os << "This: " << &node << " data: " << node.getData() << " next: ";
        if (node.hasNext()) {
            os << node.next();
        } else {
            os << "NULL";
        }
        os << " prev: ";
        if (node.hasPrev()) {
            os << node.prev();
        } else {
            os << "NULL";
        }
        return os;
    }

    bool hasPrev() const {
        return prevNode != nullptr;
    }

    DoubleNode<T> *next() const override {
        return (DoubleNode *) Node<T>::next();
    }

    DoubleNode<T> *prev() const {
        return prevNode;
    }

    void setPrev(DoubleNode<T> *prev) {
        prevNode = prev;
    }

    bool isPointingSameNode(const Node<T> *other) override {
        DoubleNode<T> *doubleNodeOther = (DoubleNode *) other;
        return *this == *doubleNodeOther;
    }
};