#include "Mozo.h"
#include <iostream>
//#include "Mesa.h"

#ifndef MOZO_CPP
#define MOZO_CPP
Mozo::Mozo(int idmozo, ICollection * mesas)
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

ICollection * Mozo::getMesa()
{
 return this->mesas;
}

void Mozo::agregarMesa(Mesa * mesa){
	this->mesas->add(mesa);
}

Mozo::~Mozo()
{

}

#endif
