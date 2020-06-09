#include "CantidadProd.h"
#ifndef CANTIDADPROD_CPP
#define CANTIDADPROD_CPP

CantidadProd::CantidadProd(int cantidad, Producto * p){
	if(p==NULL){
		throw "Se esperaba un producto";
	}
	this->cantidad = cantidad;
	this->producto=p;
}

bool CantidadProd::coincideProd(Producto * p){
	return this->producto==p;
}

void CantidadProd::sumarCantidad(int cantProd){
	this->cantidad+=cantProd;
}

Producto * CantidadProd::getProducto(){
	return this->producto;
}

int CantidadProd::getCantidadRestada(int cantProd){
	return this->cantidad-cantProd;
}

CantidadProd::~CantidadProd(){
	
}


#endif
