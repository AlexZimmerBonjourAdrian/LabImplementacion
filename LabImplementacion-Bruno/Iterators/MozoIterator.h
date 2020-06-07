#include "IIterator.cpp"

class MozoIterator{
	
	private:
		IIterator * it;
	
	public:
		MozoIterator(IIterator*);
		void next();
		ICollectible * getCurrent();
		bool hasCurrent();
		~MozoIterator();
};
