#include "../interfaces/IKey.cpp"
#ifndef INTKEY_H
#define INTKEY_H
class IntKey : public IKey {
	private:
		int id;
		
	public:
		IntKey(int);
		bool equals(IKey * id) const;
		int getId();
		virtual ~IntKey();
};
#endif
