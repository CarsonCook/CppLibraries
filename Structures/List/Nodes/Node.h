#pragma once

#include <exception>
#include "../../util.cpp"

template<class T>
class Node {
private:
    T data;
    void *nextNode = nullptr;
public:
    virtual ~Node() {}

    explicit Node(const T &newData) : data{newData} {};

    Node() = default;

    Node(const Node &copyNode) {
        data = copyNode.getData();
        nextNode = copyNode.nextNode;
    }

    Node &operator=(const Node &other) {
        if (util::isSamePointer(this, &other)) {
            return *this;
        }
        (*this).data = other.data;
        (*this).nextNode = other.nextNode;
        return *this;
    }

    bool operator==(const Node &other) {
        return data == other.data && nextNode == other.nextNode;
    }

    bool operator!=(const Node &other) {
        return !(*this == other);
    }

    friend std::ostream &operator<<(std::ostream &os, const Node<T> &node) {
        os << "This: " << &node << " data: " << node.getData() << " next: ";
        Node<T> *possibleNext = node.next();
        if (node.hasNext()) {
            os << possibleNext;
        } else {
            os << "NULL";
        }
        return os;
    }

    bool isPointingSameNode(const Node<T> *other) {
        return *this == *other;
    }

    inline bool hasNext() const {
        return nextNode != nullptr;
    }

    virtual Node *next() const {
        return (Node *) nextNode;
    }

    void setNext(Node *newNextNode) {
        nextNode = newNextNode;
    }

    T getData() const {
        return data;
    }

    void setData(const T &newData) {
        data = newData;
    }
};