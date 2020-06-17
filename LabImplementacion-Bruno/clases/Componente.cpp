#include "Componente.h"
#include<iostream>
#ifndef COMPONENTE_CPP
#define COMPONENTE_CPP


using namespace std;

Componente::Componente(int cantidad, Comun * producto){
	this->cantidad=cantidad;
	this->producto=producto;
}

bool Componente::coincide(Comun * producto){
	return (this->producto==producto);
}

int Componente::getCantidad(){
	return this->cantidad;
}

Comun * Componente::getProducto(){
	return this->producto;
}

Componente::~Componente(){
	
}

#endif
