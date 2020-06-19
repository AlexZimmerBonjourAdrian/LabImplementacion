

#include "Mesa.h"

#ifndef MESA_CPP
#define MESA_CPP

Mesa::Mesa(int id, IDictionary * historial) : venta(NULL)
{
    this->id=id;
    this->historial=historial;
}

Mesa::~Mesa(){
}

void Mesa::setid(int id)
{
    this->id = id;
}

bool Mesa::coincide(Vlocal* venta){
	return (this->venta==venta);
}

int Mesa::getid()
{
    return id;
}

Vlocal * Mesa::getVenta(){
	return this->venta;
}

void Mesa::setVenta(Vlocal * venta){

	
	this->venta=venta;
}


#endif

