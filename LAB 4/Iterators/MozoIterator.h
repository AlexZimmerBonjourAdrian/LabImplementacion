#include "../clases/Mozo.cpp"

class MozoIterator{
	
	private:
		IIterator * it;
	
	public:
		MozoIterator(IIterator*);
		void next();
		Mozo * getCurrent();
		bool hasCurrent();
		~MozoIterator();
};
