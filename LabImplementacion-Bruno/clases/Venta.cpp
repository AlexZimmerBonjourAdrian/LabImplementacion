#include "Venta.h"
#include "CantidadProd.cpp"
#include "../colecciones/List.cpp"
#ifndef VENTA_CPP
#define VENTA_CPP

int Venta::maximo = 1;

Venta::Venta(ICollection * cantidades, DtFecha * fecha,string estado) : codigo(maximo++){
	this->cantidades=cantidades;
	this->estado=estado;
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
			cout << "BORRE" << endl;
			this->cantidades->remove(cant);
			delete cant;
			
		}
		it->next();
	}
	delete it;
}

bool Venta::tieneMenu(){
	IIterator * it = cantidades->getIterator();
	while(it->hasCurrent()){
		CantidadProd * cant = (CantidadProd *) it->getCurrent();
		if(cant->esMenu()){
			return true;
		}
		it->next();
	}
	delete it;
	return false;
}

string Venta::getEstado(){
	return this->estado;
}

void Venta::setEstado(string estado){
	this->estado=estado;
}

int Venta::getCodigo(){
	return this->codigo;
}

int Venta::getCantidadProd(Producto *p){
	IIterator * it = cantidades->getIterator();
	while(it->hasCurrent()){
		CantidadProd * c = (CantidadProd *) it->getCurrent();
		if(c->coincideProd(p)){
			return c->getCantidad();
		}
		it->next();
	}
	return 0;
}

void Venta::setNuevaCantidad(Producto * p, int cantProd,string op){
	IIterator * it = cantidades->getIterator();
	while(it->hasCurrent()){
		CantidadProd * cant =(CantidadProd *)it->getCurrent();
		if(cant->coincideProd(p)){
			if(op=="suma"){
				cant->sumarCantidad(cantProd);
			
			}
			else{
				cant->restarCantidad(cantProd);
				if(cant->getCantidad()<=0){
					this->cantidades->remove(cant);
					delete cant;
				}
			}
			return;
		}
		it->next();
	}
	throw "(Clase venta)No se encontro el producto en la venta";
}





bool Venta::buscarProd(Producto * p){
	IIterator * it = cantidades->getIterator();
	while(it->hasCurrent()){
		CantidadProd * c = (CantidadProd*) it->getCurrent();
		if(c->coincideProd(p)){
			return true;
		}
		it->next();
	}
	return false;
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
		it->next();
	}
	return total;
}

float Venta::getMontototal(){
	
}

Venta::~Venta(){
	delete this->cantidades;
}



#endif
