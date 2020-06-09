#include "../colecciones/IntKey.h"
#include "../interfaces/ICollectible.h"
class ListNodeDictionary{
	private:
		IntKey * key;
		ListNodeDictionary * next;
		ICollectible * elem;
	
	public:
		ListNodeDictionary(IntKey *, ListNodeDictionary *, ICollectible *);
    	ICollectible *getElem() const;
	    void setElem(ICollectible *elem);
	    ListNodeDictionary * getNext() const;
	    void setNext(ListNodeDictionary *next);
};
