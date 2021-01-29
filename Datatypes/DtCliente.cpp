#include "DtCliente.h"
#include<iostream>
#ifndef DTCLIENTE_CPP
#define DTCLIENTE_CPP

using namespace std;

DtCliente::DtCliente(int telefono, string nombre,DtDireccion * dir){
	this->telefono=telefono;
	this->nombre = nombre;
	this->dir=dir;
}

int DtCliente::getTelefono(){
	return this->telefono;
}
string DtCliente::getNombre(){
	return this->nombre;
}
DtDireccion * DtCliente::getDireccion(){
	return this->dir;
}

DtCliente::~DtCliente(){
	
}

#endif
