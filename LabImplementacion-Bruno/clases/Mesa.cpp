

#include "Mesa.h"

#ifndef MESA_CPP
#define MESA_CPP

Mesa::Mesa(int id, IDictionary * historial)
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

int Mesa::getid()
{
    return id;
}

Vlocal * Mesa::getVenta(){
	return this->venta;
}

void Mesa::setVenta(Vlocal * venta){
	if(venta==NULL){
		throw "(Clase Mesa) La venta no puede ser nula";
	}
	
	this->venta=venta;
}


#endif

