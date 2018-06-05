#pragma

#include <ostream>
#include "Node.h"

template<class T>
class DoubleNode : public Node<T> {
private:
    DoubleNode<T> *prevNode = nullptr;

public:
    virtual ~DoubleNode() {}

    explicit DoubleNode(const T &newData) : Node<T>(newData) {}

    DoubleNode(const DoubleNode<T> &otherNode) : Node<T>(otherNode) {
        prevNode = otherNode.prevNode;
    }

    DoubleNode<T> &operator=(const DoubleNode<T> &other) {
        if (util::isSamePointer(this, &other)) {
            return *this;
        }
        prevNode = other.prevNode;
        setData(other.getData());
        setNext(other.next());
    }

    bool operator==(const DoubleNode<T> &other) {
        return prevNode == other.prevNode && Node<T>::getData() == other.getData() && Node<T>::next() == other.next();
    }

    bool operator!=(const DoubleNode<T> &other) {
        return !(*this == other);
    }

    friend std::ostream &operator<<(std::ostream &os, const DoubleNode<T> &node) {
        os << "This: " << &node << " data: " << node.getData() << " next: ";
        try {
            os << node.next();
        } catch (const NoNextPointer &e) {
            os << "NULL";
        }
        os << " prev: ";
        try {
            os << node.prev();
        } catch (const NoNextPointer &e) {
            os << "NULL";
        }
        return os;
    }

    DoubleNode *prev() const {
        return prevNode;
    }

    void setPrev(DoubleNode<T> *prev) {
        prevNode = prev;
    }
};