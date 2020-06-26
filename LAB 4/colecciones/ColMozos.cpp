#include "ColMozos.h"

ColMozos::ColMozos(ICollection* col){
	this->col=col;
}

void ColMozos::add(Mozo * m){
	col->add(m);
}

void ColMozos::remove(Mozo * m){
	col->remove(m);
}

bool ColMozos::member(Mozo * m){
	return col->member(m);
}

bool ColMozos::isEmpty(){
	return col->isEmpty();
}

MozoIterator * ColMozos::getIterator(){
	
	MozoIterator * mit= new MozoIterator(col->getIterator());
	return mit;
}

ColMozos::~ColMozos(){
	col->~ICollection();
}
