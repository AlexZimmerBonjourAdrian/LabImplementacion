#include "ListDIterator.h"
#ifndef LISTDITERATOR_CPP
#define LISTDITERATOR_CPP

using namespace std;

ListDIterator::ListDIterator(ListNodeDictionary* n, bool disposeHeadOnDelete):
        head(n), current(n), disposeHeadOnDelete(disposeHeadOnDelete) {
}

ICollectible *ListDIterator::getCurrent()
{
    if(current == NULL)
        throw "No hay elemento: se llego al fin de la coleccion";
    return current->getElem();
}



bool ListDIterator::hasCurrent()
{
    return current != NULL;
}

void ListDIterator::next()
{
    if(current != NULL)
        current = current->getNext();
}

ListDIterator::~ListDIterator()
{
    if(disposeHeadOnDelete){
        ListNodeDictionary *n = head;
        while(n != NULL){
            ListNodeDictionary *deleteMe = n;
            n = n->getNext();
            delete deleteMe;
        }
    }
        
}
#endif

