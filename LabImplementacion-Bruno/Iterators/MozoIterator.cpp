#include "MozoIterator.h"

MozoIterator::MozoIterator(IIterator* it){
	this->it=it;
}

void MozoIterator::next(){
	it->next();
}

Mozo * MozoIterator::getCurrent(){
	return (Mozo*) it->getCurrent();
}

bool MozoIterator::hasCurrent(){
	return it->hasCurrent();
}

MozoIterator::~MozoIterator(){
	it->~IIterator();
}
