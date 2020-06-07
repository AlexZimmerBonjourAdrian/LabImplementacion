#include "MozoIterator.h"
#include "../clases/Mozo.cpp"
MozoIterator::MozoIterator(IIterator* it){
	this->it=it;
}

void MozoIterator::next(){
	it->next();
}

ICollectible * MozoIterator::getCurrent(){
	return (Mozo*) it->getCurrent();
}

bool MozoIterator::hasCurrent(){
	return it->hasCurrent();
}

MozoIterator::~MozoIterator(){
	it->~IIterator();
}
