#include "DtMozo.h"
#ifndef DTMOZO_CPP
#define DTMOZO_CPP
#include<iostream>

using namespace std;

DtMozo::DtMozo(int codigo, string nombre,ICollection * mesas) : DtEmpleado(codigo,nombre){
	this->mesas=mesas;
}

ICollection * DtMozo::getMesas(){
	return this->mesas;
}

DtMozo::~DtMozo(){
	
}
#endif
