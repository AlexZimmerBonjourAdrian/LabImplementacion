#include<iostream>
#include "Empleado.h"
#ifndef EMPLEADO_CPP
#define EMPLEADO_CPP
using namespace std;

Empleado::Empleado(int id,string nombre){
	this->id=id;
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
