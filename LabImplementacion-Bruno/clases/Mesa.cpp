


#include "../colecciones/IntKey.cpp"
#ifndef MESA_CPP
#define MESA_CPP
#include "Mesa.h"
#include "../clases/Vlocal.cpp"
Mesa::Mesa(int id, IDictionary * historial) : venta(NULL)
{
    this->id=id;
    this->historial=historial;
}

Mesa::~Mesa(){
	delete this->historial;
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

void Mesa::setVenta(Vlocal * venta_){

	
	this->venta=venta_;
	if(venta_!=NULL){
		IKey * k  = new IntKey(venta_->getCodigo());
		this->historial->add(k,venta);	
	}
	
}



#endif

