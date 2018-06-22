#pragma once

#include <iosfwd>
#include "../../util.cpp"

template<class T>
class Node {
private:
    T data;

public:
    virtual ~Node() = default;

    explicit Node(const T &newData) : data{newData} {}

    Node(const Node &other) {
        data = other.data;
    }

    Node &operator=(const Node &other) {
        if (util::isSamePointer(this, &other)) {
            return *this;
        }
        data = other.data;
    }

    friend std::ostream &operator<<(std::ostream &os, const Node &node) const {
        node.printNode();
    }

    T getData() const {
        return data;
    }

    void setData(const T &newData) {
        data = newData;
    }

private:
    virtual void printNode() const =0;
};