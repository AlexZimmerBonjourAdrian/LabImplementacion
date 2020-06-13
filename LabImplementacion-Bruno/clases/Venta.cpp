#include "Venta.h"
#include "CantidadProd.cpp"
#include "../colecciones/List.cpp"
#ifndef VENTA_CPP
#define VENTA_CPP

int Venta::maximo = 1;

Venta::Venta(ICollection * cantidades, DtFecha * fecha) : codigo(maximo++){
	this->cantidades=cantidades;
	this->fecha=fecha;
	
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

int Venta::getCodigo(){
	return this->codigo;
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


DtFecha * Venta::getFecha(){
	return this->fecha;
}

ICollection * Venta::getCantidades(){
	return this->cantidades;
}

ICollection * Venta::getProductos(){
	
	IIterator * it = cantidades->getIterator();
	ICollection * dtprod = new List();
	while(it->hasCurrent()){
		CantidadProd * c = (CantidadProd *) it->getCurrent();
		dtprod->add(c->getDtProducto());
		it->next();
	}
	return dtprod;
}

float Venta::getSubtotal(){
	IIterator * it = cantidades->getIterator();
	int total=0;
	while(it->hasCurrent()){
		CantidadProd * c = (CantidadProd *) it->getCurrent();
		DtProducto * dp = c->getDtProducto();
		total+=c->getCantidad()*dp->getPrecio();
	}
	return total;
}
Venta::~Venta(){
	
}



#endif
