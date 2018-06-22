#pragma once

#include <iostream>
#include "Node.h"

template<class T>
class BinaryNode : public Node<T> {
private:
    BinaryNode *left = nullptr;
    BinaryNode *right = nullptr;

public:
    virtual ~BinaryNode() = default;

    BinaryNode() = default;

    explicit BinaryNode(const T &newData) : Node<T>::Node(newData) {}

    BinaryNode(const T &newData, BinaryNode *leftChild, BinaryNode *rightChild) : left{leftChild}, right{rightChild},
                                                                                  Node<T>::Node(newData) {}

    BinaryNode(const BinaryNode &other) : Node<T>::Node(other) {
        left = other.left;
        right = other.right;
    }

    BinaryNode &operator=(const BinaryNode &other) {
        if (util::isSamePointer(this, &other)) {
            return *this;
        }
        left = other.left;
        right = other.right;
    }

    void setLeft(BinaryNode *newLeft) {
        left = newLeft;
    }

    void setRight(BinaryNode *newRight) {
        right = newRight;
    }

    BinaryNode *getLeft() const {
        return left;
    }

    BinaryNode *getRight() const {
        return right;
    }

    bool hasLeft() const {
        return left != nullptr;
    }

    bool hasRight() const {
        return right != nullptr;
    }

private:
    void printNode(std::ostream &os) const override {
        os << "This: " << this << " Data: " << Node<T>::getData() << " Left: ";
        if (hasLeft()) {
            os << left;
        } else {
            os << "NULL";
        }
        os << " Right: ";
        if (hasRight()) {
            os << right;
        } else {
            os << "NULL";
        }
    }
};