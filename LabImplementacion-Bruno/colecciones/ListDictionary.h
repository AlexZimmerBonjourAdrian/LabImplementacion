#include "../interfaces/IDictionary.h"

class ListDictionary : public IDictionary{
	
	private:
		ListNodeDictionary * head;
		
	public:
		ListDictionary(ListNodeDictionary *);
		void add(IKey *,ICollectible *);
		bool member(IKey *);
		void remove(IKey *);
		ICollectible * find(IKey *);
		bool isEmpty();
		int getSize();
		IIterator * getIterator();
		~ListDictionary();
	
};
