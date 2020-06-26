#include<iostream>
#include "DtEmpleado.h"


#ifndef DTEMPLEADO_CPP
#define DTEMPLEADO_CPP


using namespace std;

DtEmpleado::DtEmpleado(int codigo,string nombre){
	this->codigo=codigo;
	this->nombre=nombre;
	
}

int DtEmpleado::getId(){
	return this->codigo;
}

string DtEmpleado::getNombre(){
	return this->nombre;
}

DtEmpleado::~DtEmpleado(){
	
}

#endif
