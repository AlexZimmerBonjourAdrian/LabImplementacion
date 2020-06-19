#include "Comun.h"


Comun::Comun(int codigo, string descripcion, float precio) : Producto(codigo,descripcion,precio){
	this->setTipo("Comun");
}


Comun::~Comun(){
	
}

