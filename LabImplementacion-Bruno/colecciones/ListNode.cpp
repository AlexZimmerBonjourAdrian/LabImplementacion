#include "ListNode.h"
#ifndef LISTNODE_CPP
#define	LISTNODE_CPP


using namespace std;

ListNode::ListNode(ICollectible* elem, ListNode* next):
        next(next) {
    if(elem == NULL)
        cout << "elem is NULL" << endl;
    this->elem = elem;
}

ICollectible *ListNode::getElem() const
{
    return elem;
}

void ListNode::setElem(ICollectible* elem)
{
    if(elem == NULL)
       	cout << "elem is NULL" << endl;
    this->elem = elem;
}

ListNode *ListNode::getNext() const
{
    return next;
}

void ListNode::setNext(ListNode* next)
{
    this->next = next;
}
#endif
