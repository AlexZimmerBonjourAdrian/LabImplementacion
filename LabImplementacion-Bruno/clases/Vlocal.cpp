#include "Vlocal.h"
#ifndef VLOCAL_CPP
#define VLOCAL_CPP
#include "Mesa.cpp"
#include "../colecciones/IntKey.cpp"
Vlocal::Vlocal(int codigo, ICollection * cantidades, IDictionary * mesas, Mozo* mozo) : Venta(codigo,cantidades){
	this->mesas=mesas;
	this->mozo=mozo;
}

void Vlocal::asignarMesas(ICollection * mesas){
	IIterator * it = mesas->getIterator();
	while(it->hasCurrent()){
		Mesa * m = (Mesa*) it->getCurrent();
		IKey * key = new IntKey(m->getid());
		this->mesas->add(key,m);
	}
	
}

string Vlocal::getEmpleado() const {
	return this->mozo->getNombre();
}

Vlocal::~Vlocal(){
	
}
#endif
