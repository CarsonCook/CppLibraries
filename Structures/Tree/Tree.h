#pragma once

#include "Node/Node.h"

template<class NodeType>
class Tree {
private:
    NodeType root;

public:
    virtual ~Tree() {}

    Tree() = default;

    explicit Tree(const NodeType &node) : root{node} {}

    Tree(const Tree &other) {
        root = other.root;
    }

    Tree &operator=(const Tree &other) {
        if (util::isSamePointer(this, &other)) {
            return *this;
        }
        root = other.root;
    }

    NodeType getRoot() const {
        return root;
    }

    void setRoot(const NodeType &newRoot) {
        root = newRoot;
    }
};