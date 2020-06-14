#include "Producto.h"
#ifndef PRODUCTO_CPP
#define PRODUCTO_CPP
#include<iostream>
Producto::Producto(int codigo, string descripcion,float precio){
	this->codigo=codigo;
	this->descripcion=descripcion;
	this->precio=precio;
}

DtProducto * Producto::getDatos(){
	return  new DtProducto(this->codigo,this->descripcion, this->precio,0);
}

int Producto::getCodigo(){
	return this->codigo;
}

Producto::~Producto(){
	
}


#endif
