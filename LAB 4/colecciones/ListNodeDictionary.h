#include "../colecciones/IntKey.cpp"
#include "../interfaces/ICollectible.h"
#ifndef LISTNODEDICTIONARY_H
#define LISTNODEDICTIONARY_H
class ListNodeDictionary{
	private:
		IntKey * key;
		ListNodeDictionary * next ;
		ICollectible * elem;
	
	public:
		ListNodeDictionary(IntKey *, ICollectible *, ListNodeDictionary * next = NULL);
    	ICollectible *getElem() const;
	    void setElem(ICollectible *elem);
	    ListNodeDictionary * getNext() const;
	    IntKey * getKey();
	    void setNext(ListNodeDictionary *next);
	    ~ListNodeDictionary();
};

#endif
