
#include "../iterators/MozoIterator.cpp"
class ColMozos{
	
	private:
		ICollection *col;
		
	public:
		ColMozos(ICollection*);
		void add(Mozo *);
		void remove(Mozo *);
		bool member(Mozo *);
		bool isEmpty();
		MozoIterator * getIterator();
		virtual ~ColMozos();
};
