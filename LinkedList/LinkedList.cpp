#include "LinkedList.hh"

Node::Node(Node* next, NodeData* data)
{
    mNext=next;
    mData=data;
}

Node* Node::getNext()
{
    return mNext;
}

NodeData* Node::getData()
{
    return mData;
}

void Node::printNode()
{
    std::cout << "Node at memory " << this << " with data:" << std::endl;
    mData->printData();
}

List::List()
{
    mStart=nullptr;
    mListSize=0;
}

List::List(Node* start)
{
    mStart=start;
    Node* cur=start;
    int listSize=0;
    while(cur->getNext())
    {
        listSize++;
        cur=cur->getNext();
    }
    mListSize=listSize;
}

List::List(List* oldList)
{
    mStart=oldList->getStart();
    mListSize=oldList->getListSize();
}

Node* List::getStart()
{
    return mStart;
}

int List::getListSize()
{
    return mListSize;
}

List* List::clone()
{
    return new List(this);
}

void List::printList()
{
    std::cout << "Start of list" << std::endl;
    Node* cur=mStart;
    while (cur->getNext())
    {
        cur->printNode();
        cur=cur->getNext();
    }
    std::cout << "End of list" << std::endl;
}
