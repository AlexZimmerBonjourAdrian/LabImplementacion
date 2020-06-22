#include "DtVenta.h"
#include<iostream>
#ifndef DTVENTA_CPP
#define DTVENTA_CPP

using namespace std;

DtVenta::DtVenta(int codigo,ICollection * productos,DtFecha* fecha,string estado){
	this->codigo = codigo;
	this->productos=productos;
	this->fecha = fecha;
	this->estado=estado;
}

int DtVenta::getCodigo(){
	return this->codigo;
}
ICollection * DtVenta::getProductos(){
	return this->productos;
}

DtFecha * DtVenta::getFecha(){
	return this->fecha;
}
string DtVenta::getEstado(){
	return this->estado;
}

DtVenta::~DtVenta(){
	
}

#endif
