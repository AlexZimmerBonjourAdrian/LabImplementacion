#include "Mozo.h"
#include <iostream>
//#include "Mesa.h"
#include "../colecciones/IntKey.cpp"
#ifndef MOZO_CPP
#define MOZO_CPP
Mozo::Mozo(int idmozo, IDictionary * mesas)
{
    this->idmozo=idmozo;
    this->mesas=mesas;
}
void Mozo::setIdMozo(int idmozo)
{
    this->idmozo= idmozo;
}
int Mozo::getidmozo()
{
    return this->idmozo;
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
