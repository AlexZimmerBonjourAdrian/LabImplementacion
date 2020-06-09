#include "ListNodeDictionary.h"
#ifndef LISTNODEDICTIONARY_CPP
#define	LISTNODEDICTIONARY_CPP


using namespace std;

ListNodeDictionary::ListNodeDictionary(IntKey * k, ListNodeDictionary* next, ICollectible* elem):
        next(next) {
    if(elem == NULL)
        throw "elem is NULL";
    this->elem = elem;
    
}

ICollectible *ListNodeDictionary::getElem() const
{
    return elem;
}

void ListNodeDictionary::setElem(ICollectible* elem)
{
    if(elem == NULL)
       	cout << "elem is NULL" << endl;
    this->elem = elem;
}

ListNodeDictionary *ListNodeDictionary::getNext() const
{
    return next;
}

void ListNodeDictionary::setNext(ListNodeDictionary* next)
{
    this->next = next;
}
#endif
