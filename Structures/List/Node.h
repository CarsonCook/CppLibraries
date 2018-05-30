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
    virtual ~SimpleNode() = default;

    explicit SimpleNode(const T &newData) : data{newData} {};

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

private:
    bool noNext() const {
        return nextNode == nullptr;
    }
};