
#include "Mozo.h"
#include <iostream>
//#include "Mesa.h"
#include "../colecciones/IntKey.cpp"

#ifndef MOZO_CPP
#define MOZO_CPP



Mozo::Mozo(int idmozo, string nombre, IDictionary * mesas) : Empleado(idmozo,nombre){

    this->mesas=mesas;
}

IDictionary * Mozo::getMesa()
{
 return this->mesas;
}

void Mozo::agregarMesa(Mesa * mesa){
	
	this->mesas->add(new IntKey(mesa->getid()),mesa);
}

Mozo::~Mozo()
{

}

#endif
