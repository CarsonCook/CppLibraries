#pragma once

#include <exception>
#include "../util.cpp"

class NoNextPointer : std::exception {
public:
    const char *what() const noexcept override {
        return "Tried to access a Node that doesn't exist!";
    }
};

template<class T>
class SimpleNode {
private:
    T data;
    SimpleNode *nextNode = nullptr;
public:
    virtual ~SimpleNode() = default; //TODO delete nextNode, data(?)

    explicit SimpleNode(const T &newData) : data{newData} {};

    SimpleNode() = default;

    SimpleNode(const SimpleNode &copyNode) {
        data = copyNode.getData();
        nextNode = copyNode.nextNode; //allow nullptr (tail of list), next() would throw error
    }

    SimpleNode &operator=(const SimpleNode &other) {
        if (util::isSamePointer(this, &other)) {
            return *this;
        }
        (*this).data = other.data;
        (*this).nextNode = other.nextNode;
        return *this;
    }

    inline bool hasNext() const {
        return nextNode != nullptr;
    }

    SimpleNode *next() const {
        if (noNext()) {
            throw NoNextPointer();
        }
        return nextNode;
    }

    void setNext(SimpleNode *newNextNode) {
        nextNode = newNextNode;
    }

    T getData() const {
        return data;
    }

    void setData(const T &newData) {
        data = newData;
    }

    //defined so list can be sorted with std::sort()
    friend SimpleNode<T> operator-(const SimpleNode<T> &lhs, const SimpleNode<T> &rhs) {
        return SimpleNode<T>(lhs.getData() - rhs.getData());
    }

private:
    bool noNext() const {
        return nextNode == nullptr;
    }
};