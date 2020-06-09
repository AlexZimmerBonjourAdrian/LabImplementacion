#include "IIterator.cpp"


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
