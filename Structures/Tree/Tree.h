#pragma once

#include "Node/Node.h"
#include "TreeExceptions.h"

template<class T, class NodeType>
class Tree {
private:
    NodeType root;
    bool isEmpty = true;
    T data;

public:
    virtual ~Tree() {}

    Tree() = default;

    explicit Tree(const NodeType &node) : root{node}, isEmpty{false} {}

    Tree(const Tree &other) = default;

    Tree &operator=(const Tree &other) {
        if (util::isSamePointer(this, &other)) {
            return *this;
        }
        root = other.root;
        isEmpty = other.isEmpty;
    }

    inline NodeType getRoot() const {
        return root;
    }

    inline T getData() const {
        return data;
    }

    inline void setData(const T &d) const {
        data = d;
    }

    inline void setRoot(const NodeType &newRoot) {
        root = newRoot;
        isEmpty = false;
    }

    inline void printTree(const bool breadthFirst = false) const {
        if (breadthFirst) {
            printBreadthFirst();
        } else {
            printDepthFirst();
        }
    }

    virtual NodeType findValue(T data) const =0;

    virtual NodeType *findNode(const NodeType &node) =0;

    virtual bool isInTree(T data) const =0;

    bool isInTree(const NodeType &findNode) const {
        return isInTree(findNode.data);
    }

    virtual void insertNode(const NodeType &newNode)=0;

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
    bool isRoot(const NodeType &testNode) const {
        return testNode == root;
    }

    virtual void printBreadthFirst() const =0;

    virtual void printDepthFirst() const =0;

    virtual void removeNode(NodeType *deleteNode)=0;

    virtual bool searchTree(const BinaryNode &cur, const T &compData) const = 0;

protected:
    NodeType &getRootRef() {
        return &root;
    }
};