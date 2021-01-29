#include "Comun.h"
#include "../Datatypes/DtComun.cpp"
#ifndef COMUN_CPP
#define COMUN_CPP

Comun::Comun(int codigo, string descripcion, float precio) : Producto(codigo,descripcion,precio){
	this->setTipo("Comun");
}


DtProducto * Comun::getDatos() const{
	return  new DtComun(this->getCodigo(),this->getDescripcion(), this->getPrecio(),0,this->getTipo());

}


void Comun::borrar(Producto *p){
	
}

Comun::~Comun(){
	
}

#endif
