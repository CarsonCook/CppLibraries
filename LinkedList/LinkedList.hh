#ifndef LinkedList_hh
#define LinkedList_hh

#include <iostream>

class NodeData //used to pack data into a Node, pack info into an object that inherits NodeData
{
public:
    virtual void printData()=0; //print the packed data
};

class Node
{
public:
    Node(Node* next, NodeData* data);

    Node* getNext();
    NodeData* getData();

    virtual void printNode();
private:
    Node* mNext; //every linked list has a next pointer
    NodeData* mData;
};

class List
{
public:
    //constructors and destructors
    List();
    List(Node* start);
    List(List* oldList);

    //getters and setters
    Node* getStart();
    int getListSize();

    virtual List* clone();
    virtual void printList();
private:
    Node* mStart;
    int mListSize;
};

#endif // LinkedList_hh

//iterator through list
//multiple types of lists inherit Node and List to implement types
//doubly, singly, circular, stack, queue, dequeue
//array versions? - ArrList, ArrNode or something
//clone function for Node
