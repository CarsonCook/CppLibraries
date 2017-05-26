#ifndef SinglyLinkedList_hh
#define SinglyLinkedList_hh

#include "LinkedList.hh"

class SinglyList : public List
{
public:
    //constructors and destructors
    SinglyList();
    SinglyList(Node* start);
    SinglyList(SinglyList* oldList);

    //list operations
    void deleteNode(int position);
    void deleteNode(Node* node);

    void insertEnd(Node* newNode);
    Node* insertFront(Node* newNode); //must keep track of front of list, so return the new front
    void insertMiddle(int position); //logic to not allow insertion at front (position 0)

    void printList();
};


#endif // SinglyLinkedList_hh
