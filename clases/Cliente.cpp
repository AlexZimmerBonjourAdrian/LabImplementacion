#include<iostream>
#include "Cliente.h"
#ifndef CLIENTE_CPP
#define CLIENTE_CPP

using namespace std;

Cliente::Cliente(int telefono, string nombre, DtDireccion * direccion){
	this->telefono=telefono;
	this->nombre=nombre;
	this->direccion=direccion;
}

string Cliente::getNombre(){
	return this->nombre;
}

int Cliente::getTelefono(){
	return this->telefono;
}

DtDireccion * Cliente::getDireccion(){
	return this->direccion;
}

Cliente::~Cliente(){
	
}
#endif
