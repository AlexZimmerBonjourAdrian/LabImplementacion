#include "Repartidor.h"
#include<iostream>
#include "../colecciones/IntKey.cpp"
#ifndef REPARTIDOR_CPP
#define REPARTIDOR_CPP

using namespace std;

Repartidor::Repartidor(int id,string nombre,string medio_de_transporte,IDictionary * ventas) : Empleado(id,nombre){
	this->medio_de_transporte=medio_de_transporte;
	this->ventas=ventas;
}

string Repartidor::getMedio(){
	return this->medio_de_transporte;
}

IDictionary * Repartidor::getVentas(){
	return this->ventas;
}

Repartidor::~Repartidor(){
	IIterator * it = ventas->getIterator();
	while(it->hasCurrent()){
		Repartidor * r = (Repartidor *) it->getCurrent();
		IKey * k = new IntKey(r->getId());
		ventas->remove(k);
		it->next();
	}
	if(ventas!=NULL)delete ventas;
}

#endif
