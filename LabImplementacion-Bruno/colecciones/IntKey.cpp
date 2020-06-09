#include "IntKey.h"

IntKey::IntKey(int id){
	this->id=id;
}

bool IntKey::equals(IKey * id){
	IntKey * key = (IntKey *) id;
	return this->id==key->id;
}

IntKey::~IntKey(){
	
}


