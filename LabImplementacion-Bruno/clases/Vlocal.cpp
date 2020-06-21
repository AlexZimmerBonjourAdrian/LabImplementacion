

#include "Vlocal.h"
#ifndef VLOCAL_CPP
#define VLOCAL_CPP
#include "../colecciones/IntKey.cpp"
Vlocal::Vlocal(ICollection * cantidades,DtFecha * fecha, Mozo* mozo) : Venta(cantidades, fecha){
	this->mozo=mozo;
}

DtEmpleado* Vlocal::getEmpleado() const {


	return new DtMozo(this->mozo->getId(),this->mozo->getNombre(),this->mozo->getDTMesa());
}

Mozo * Vlocal::getMozo(){
	return this->mozo;
}

Vlocal::~Vlocal(){
	
}
#endif
