#include "ListIterator.h"
#ifndef LISTITERATOR_CPP
#define LISTITERATOR_CPP
using namespace std;

ListIterator::ListIterator(ListNode* n, bool disposeHeadOnDelete):
        head(n), current(n), disposeHeadOnDelete(disposeHeadOnDelete) {
}

ICollectible *ListIterator::getCurrent()
{
    if(current == NULL)
        throw "No hay elemento: se llego al fin de la coleccion";
    return current->getElem();
}

bool ListIterator::hasCurrent()
{
    return current != NULL;
}

void ListIterator::next()
{
    if(current != NULL)
        current = current->getNext();
}

ListIterator::~ListIterator()
{
    if(disposeHeadOnDelete){
        ListNode *n = head;
        while(n != NULL){
            ListNode *deleteMe = n;
            n = n->getNext();
            delete deleteMe;
        }
    }
        
}

#endif
