
#include "Mozo.h"
#include <iostream>
//#include "Mesa.h"
#include "../colecciones/IntKey.cpp"
#include "../Datatypes/DtMozo.cpp"
#ifndef MOZO_CPP
#define MOZO_CPP



Mozo::Mozo(string nombre, IDictionary * mesas) : Empleado(nombre){

    this->mesas=mesas;
}

ICollection * Mozo::getDTMesa() const
{
	ICollection * mes = new List();
	IIterator * it = this->mesas->getIterator();
	while(it->hasCurrent()){
		Mesa * m = (Mesa*) it->getCurrent();
		DtMesa * dm = new DtMesa(m->getid());
		mes->add(dm); 
		it->next();
	}
	delete it;
	return mes;
}
IDictionary * Mozo::getMesa(){
	return this->mesas;

}


int Mozo::cantMesas(){
	IIterator * it = mesas->getIterator();
	int cantmesas = 0;
	while(it->hasCurrent()){
		cantmesas++;
		it->next();
	}
	delete it;
	return cantmesas;
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
	delete it;
}


DtEmpleado * Mozo::getDatos() const{
	return new DtMozo(this->getId(),this->getNombre(),this->getDTMesa());
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

Mozo::~Mozo(){
	delete this->mesas;
}

#endif
