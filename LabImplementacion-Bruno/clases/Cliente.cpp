#include<iostream>
#include "Cliente.h"
#ifndef CLIENTE_CPP
#define CLIENTE_CPP

using namespace std;

Cliente::Cliente(string telefono, string nombre, DtDireccion * direccion){
	this->telefono=telefono;
	this->nombre=nombre;
	this->direccion=direccion;
}

string Cliente::getNombre(){
	return this->nombre;
}

Cliente::~Cliente(){
	
}
#endif
