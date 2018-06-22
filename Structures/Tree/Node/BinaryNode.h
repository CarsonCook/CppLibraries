#pragma once

#include "Node.h"

template<class T>
class BinaryNode : public Node<T> {
private:
    BinaryNode *left = nullptr;
    BinaryNode *right = nullptr;

public:
    virtual ~BinaryNode() = default;

    explicit BinaryNode(const T &newData) : Node<T>::Node(newData) {}


};