#pragma once

#include "Node/Node.h"
#include "TreeExceptions.h"

template<class T, class NodeType>
class Tree {
private:
    NodeType root;
    bool isEmpty = true;

public:
    virtual ~Tree() {}

    Tree() = default;

    explicit Tree(const NodeType &node) : root{node}, isEmpty{false} {}

    Tree(const Tree &other) {
        root = other.root;
        isEmpty = other.isEmpty;
    }

    Tree &operator=(const Tree &other) {
        if (util::isSamePointer(this, &other)) {
            return *this;
        }
        root = other.root;
        isEmpty = other.isEmpty;
    }

    NodeType getRoot() const {
        return root;
    }

    void setRoot(const NodeType &newRoot) {
        root = newRoot;
        isEmpty = false;
    }

    void printTree(const bool breadthFirst = false) const {
        if (breadthFirst) {
            printBreadthFirst();
        } else {
            printDepthFirst();
        }
    }

    virtual NodeType findValue(T data) const =0;

    virtual NodeType *findNode(const NodeType *node) const =0;

    virtual bool isInTree(T data) const =0;

    virtual bool isInTree(NodeType findNode) const =0;

    virtual void insertNode(NodeType newNode)=0;

    void deleteNode(NodeType *deleteNode) {
        if (isEmpty) {
            throw RemoveNodeEmptyTree();
        }
        try {
            removeNode(deleteNode);
        } catch (const FindNodeNotInTree &e) {
            throw RemoveNodeNotInTree();
        }
    }

    virtual void clearTree()=0;

private:
    bool isRoot(NodeType testNode) const {
        return testNode == root;
    }

    virtual void printBreadthFirst() const =0;

    virtual void printDepthFirst() const =0;

    virtual void removeNode(NodeType *deleteNode)=0;
};