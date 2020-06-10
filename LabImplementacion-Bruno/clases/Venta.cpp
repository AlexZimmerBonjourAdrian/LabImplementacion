#include "Venta.h"
#include "CantidadProd.cpp"
#ifndef VENTA_CPP
#define VENTA_CPP


Venta::Venta(int codigo, ICollection * cantidades){
	this->codigo=codigo;
	this->cantidades=cantidades;
}
void Venta::agregarProd(Producto * p, int cantProd){
	CantidadProd * prod = new CantidadProd(cantProd,p);
	cantidades->add(prod);
}

void Venta::borrarProd(Producto * p){
	IIterator * it = cantidades->getIterator();
	while(it->hasCurrent()){
		CantidadProd * cant =(CantidadProd *)it->getCurrent();
		if(cant->coincideProd(p)){
			delete cant;
		}
		it->next();
	}
}

int Venta::getNuevaCantidad(Producto * p, int cantProd){
	IIterator * it = cantidades->getIterator();
	while(it->hasCurrent()){
		CantidadProd * cant =(CantidadProd *)it->getCurrent();
		if(cant->coincideProd(p)){
			return cant->getCantidadRestada(cantProd);
		}
		it->next();
	}
	throw "No se encontro el producto en la venta";
}

ICollection * Venta::getCantidades(){
	return this->cantidades;
}

Venta::~Venta(){
	
}



#endif
