#include "IIterator.cpp"
#include "../colecciones/ListNodeDictionary.cpp"
#ifndef LISTDITERATOR_H
#define LISTDITERATOR_H

class ListDIterator : public IIterator{
	
	private:
		ListNodeDictionary * head;
		ListNodeDictionary * current;
		bool disposeHeadOnDelete;
		
	public:
		ListDIterator(ListNodeDictionary *head, bool disposeHeadOnDelete = false);
	    ICollectible *getCurrent();
	    bool hasCurrent();
	    void next();
	    virtual ~ListDIterator();
};
#endif
