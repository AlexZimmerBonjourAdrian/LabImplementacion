#include "Comun.h"
#ifndef COMUN_CPP
#define COMUN_CPP

Comun::Comun(int codigo, string descripcion, float precio) : Producto(codigo,descripcion,precio){
	this->setTipo("Comun");
}


Comun::~Comun(){
	
}

#endif
