#include "Repartidor.h"
#include<iostream>
#include "../colecciones/IntKey.cpp"
#ifndef REPARTIDOR_CPP
#define REPARTIDOR_CPP

using namespace std;

Repartidor::Repartidor(string nombre,string medio_de_transporte,IDictionary * ventas) : Empleado(nombre){
	this->medio_de_transporte=medio_de_transporte;
	this->ventas=ventas;
}

string Repartidor::getMedio(){
	return this->medio_de_transporte;
}

DtEmpleado * Repartidor::getDatos() const{
	return new DtRepartidor(this->getId(),this->getNombre(),this->medio_de_transporte);
}

IDictionary * Repartidor::getVentas(){
	return this->ventas;
}

void Repartidor::agregarVenta(Venta * v){
	IKey * k = new IntKey(v->getCodigo());
	this->ventas->add(k,v);
}

Repartidor::~Repartidor(){
	delete this->ventas;
}

#endif
