#include<iostream>
#include "Empleado.h"
#ifndef EMPLEADO_CPP
#define EMPLEADO_CPP
using namespace std;

int Empleado::maximo=1;

Empleado::Empleado(string nombre) : id(maximo++){
	this->nombre=nombre;
}

int Empleado::getId(){
	return this->id;
}

string Empleado::getNombre(){
	return this->nombre;
}

Empleado::~Empleado(){
}

#endif
