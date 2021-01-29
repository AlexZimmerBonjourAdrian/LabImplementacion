#include "ListNodeDictionary.h"
#ifndef LISTNODEDICTIONARY_CPP
#define	LISTNODEDICTIONARY_CPP


using namespace std;

ListNodeDictionary::ListNodeDictionary(IntKey * k, ICollectible* elem, ListNodeDictionary* next):
        next(next) {
    if(elem == NULL)
        throw "elem is NULL";
    this->key=k;
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
    return this->next;
}

IntKey * ListNodeDictionary::getKey(){
	return this->key;
}

void ListNodeDictionary::setNext(ListNodeDictionary* next)
{
    this->next = next;
}

ListNodeDictionary::~ListNodeDictionary(){
	delete this->key;

}
#endif
