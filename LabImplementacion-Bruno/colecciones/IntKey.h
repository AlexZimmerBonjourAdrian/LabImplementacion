#include "../interfaces/IKey.cpp"

class IntKey : public IKey {
	private:
		int id;
		
	public:
		IntKey(int);
		bool equals(IKey * id);
		virtual ~IntKey();
};

