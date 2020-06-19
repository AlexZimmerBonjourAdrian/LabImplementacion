
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
		cout << "HOLA" << endl;
		Mesa * m = (Mesa*) it->getCurrent();
		cout << m->getid() << endl;
		system("PAUSE");
		if(m->coincide(venta)){
			it->next();
			IKey * k = new IntKey(m->getid());
			this->mesas->remove(k);
			delete k;
		}
		else{
			it->next();
		}
	}
}

void Mozo::agregarMesa(Mesa * mesa){
	
	this->mesas->add(new IntKey(mesa->getid()),mesa);
}

Mozo::~Mozo()
{

}

#endif
