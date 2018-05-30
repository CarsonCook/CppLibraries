#pragma once

#include <exception>

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
        nextNode = copyNode.nextNode; //allow nullptr (end of list), next() would throw error
    }

    inline bool hasNext() const {
        return nextNode != nullptr;
    }

    SimpleNode next() const {
        if (noNext()) {
            throw NoNextPointer();
        }
        return *nextNode;
    }

    void setNext(const SimpleNode &newNextNode) {
        nextNode = new SimpleNode(newNextNode);
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