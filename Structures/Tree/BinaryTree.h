#pragma once

#include "Tree.h"
#include "Node/BinaryNode.h"

template<class T>
class BinaryTree : public Tree<T, BinaryNode> {
private:
    BinaryNode left, right;

public:
    BinaryTree() : Tree() {};

    BinaryTree(const BinaryNode &root) : Tree(root) {};

    BinaryTree(const BinaryTree &other) = default;

    virtual ~BinaryTree() : ~Tree() {}

    BinaryNode findValue(T data) const override;

    BinaryNode *findNode(const BinaryNode &node) override{
        return nodeSearch(getRootRef(), node);
    }

    bool isInTree(T data) const override {
        return searchTree(getRoot(), data);
    }

    void insertNode(const BinaryNode &newNode) override;

    void clearTree() override;

private:
    virtual void printBreadthFirst() const override;

    virtual void printDepthFirst() const override;

    virtual void removeNode(BinaryNode *deleteNode) override;

    bool searchTree(const BinaryNode &cur, const T &compData) const override {
        T curData = cur.getData();
        if (curData == compData) {
            return true;
        } else if (curData > compData) {
            return searchTree(*cur.getRight(), compData);
        } else {
            return searchTree(*cur.getLeft(), compData);
        }
    }

    BinaryNode *nodeSearch(BinaryNode &cur, const BinaryNode &comp) {
        if (&cur == &comp) {
            return &cur;
        } else if (cur.getData() > comp.getData()) {
            return nodeSearch(*cur.getRight(), comp);
        } else {
            return nodeSearch(*cur.getLeft(), comp);
        }
    }
};