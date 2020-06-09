#include "IntKey.h"
#ifndef INTKEY_CPP
#define INTKEY_CPP

IntKey::IntKey(int id){
	this->id=id;
}

bool IntKey::equals(IKey * id) const{
	IntKey * key = (IntKey *) id;
	return this->id==key->id;
}

int IntKey::getId(){
	return this->id;
}

IntKey::~IntKey(){
	
}

#endif
