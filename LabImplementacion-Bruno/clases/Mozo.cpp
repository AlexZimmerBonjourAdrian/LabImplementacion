
#include "Mozo.h"
#include <iostream>
//#include "Mesa.h"
#include "../colecciones/IntKey.cpp"

#ifndef MOZO_CPP
#define MOZO_CPP



Mozo::Mozo(string nombre, IDictionary * mesas) : Empleado(nombre){

    this->mesas=mesas;
}

IDictionary * Mozo::getMesa()
{
 return this->mesas;
}

void Mozo::borrarMesas(Vlocal * venta){
	IIterator * it = this->mesas->getIterator();
	while(it->hasCurrent()){
		Mesa * m = (Mesa*) it->getCurrent();

		if(m->coincide(venta)){
			it->next();
			m->setVenta(NULL);
			IKey * k = new IntKey(m->getid());
			this->mesas->remove(k);
			delete k;
		}
		else{
			it->next();
		}
	}
}


bool Mozo::check_mesa(Mesa * m){
	
	IKey * k = new IntKey(m->getid());
	bool ck;
	if(this->mesas->member(k)){
		ck=true;
	}
	else{
		ck=false;
	}
	delete k;
	return ck;
}

void Mozo::agregarMesa(Mesa * mesa){
	
	this->mesas->add(new IntKey(mesa->getid()),mesa);
}

Mozo::~Mozo()
{

}

#endif
