#include <iostream>
#include "../Datatypes/DtDireccion.h"
#ifndef DTDIRECCION_CPP
#define DTDIRECCION_CPP

using namespace std;

DtDireccion::DtDireccion(string calle, int nro){
	this->calle=calle;
	this->nro=nro;
	
}

string DtDireccion::getCalle(){
	return this->calle;
}

int DtDireccion::getNro(){
	return this->nro;
}

DtDireccion::~DtDireccion(){
	
}

#endif
