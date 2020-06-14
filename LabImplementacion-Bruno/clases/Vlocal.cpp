

#include "Vlocal.h"
#ifndef VLOCAL_CPP
#define VLOCAL_CPP
#include "../colecciones/IntKey.cpp"
Vlocal::Vlocal(ICollection * cantidades,DtFecha * fecha, Mozo* mozo) : Venta(cantidades, fecha){
	this->mozo=mozo;
}

string Vlocal::getEmpleado() const {
	return this->mozo->getNombre();
}

Mozo * Vlocal::getMozo(){
	return this->mozo;
}

Vlocal::~Vlocal(){
	
}
#endif
