#include<iostream>
#include "Vdomicilio.h"
#ifndef VDOMICILIO_CPP
#define VDOMICILIO_CPP

using namespace std;

Vdomicilio::Vdomicilio( ICollection * cantidades,DtFecha * fecha,DtDireccion * direccion,string nombre_rec,string telefono_rec, Repartidor * repartidor, Cliente* cliente) : Venta(cantidades, fecha){
	this->direccion=direccion;
	this->nombre_rec=nombre_rec;
	this->telefono_rec=telefono_rec;
	this->repartidor=repartidor;
	this->cliente=cliente;
}

DtDireccion * Vdomicilio::getDireccion(){
	return this->direccion;
}

string Vdomicilio::getNombre(){
	return this->nombre_rec;
}

string Vdomicilio::getEmpleado() const {
	return this->repartidor->getNombre();
}

Vdomicilio::~Vdomicilio(){
	
}
#endif

