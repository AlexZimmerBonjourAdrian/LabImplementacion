#include "../interfaces/IDictionary.cpp"
#include "ListNodeDictionary.cpp"
#ifndef LISTDICTIONARY_H
#define LISTDICTIONARY_H
class ListDictionary : public IDictionary{
	
	private:
		ListNodeDictionary * head;
		int size;
		
	public:
		ListDictionary();
		void add(IKey *,ICollectible *);
		bool member(IKey *) const;
		void remove(IKey *);
		ICollectible * find(IKey *) const;
		bool isEmpty() const;
		int getSize() const;
		IIterator * getIterator();
		virtual ~ListDictionary();
	
};

#endif
