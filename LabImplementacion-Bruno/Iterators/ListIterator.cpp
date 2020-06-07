#include "ListIterator.h"

using namespace std;

ListIterator::ListIterator(ListNode* n, bool disposeHeadOnDelete):
        head(n), current(n), disposeHeadOnDelete(disposeHeadOnDelete) {
}

ICollectible *ListIterator::getCurrent()
{
    if(current == NULL)
        cout << "No hay elemento: se llegó al fin de la colección" << endl;
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


