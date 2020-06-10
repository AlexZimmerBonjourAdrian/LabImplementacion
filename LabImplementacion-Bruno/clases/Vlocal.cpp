#include "Vlocal.h"
#ifndef VLOCAL_CPP
#define VLOCAL_CPP
#include "Mesa.cpp"
#include "../colecciones/IntKey.cpp"
Vlocal::Vlocal(int codigo, ICollection * cantidades, IDictionary * mesas) : Venta(codigo,cantidades){
	this->mesas=mesas;
}

void Vlocal::asignarMesas(ICollection * mesas){
	IIterator * it = mesas->getIterator();
	while(it->hasCurrent()){
		Mesa * m = (Mesa*) it->getCurrent();
		IKey * key = new IntKey(m->getid());
		this->mesas->add(key,m);
	}
	
}

Vlocal::~Vlocal(){
	
}
#endif
