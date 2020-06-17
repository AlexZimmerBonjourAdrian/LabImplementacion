#include "Producto.h"
#ifndef PRODUCTO_CPP
#define PRODUCTO_CPP
#include<iostream>
Producto::Producto(int codigo, string descripcion,float precio){
	this->codigo=codigo;
	this->descripcion=descripcion;
	this->precio=precio;
}


void Producto::setTipo(string tipo){
	this->tipo=tipo;
}

string Producto::getTipo() const{
	return this->tipo;
}

string Producto::getDescripcion() const{
	return this->descripcion;
}

int Producto::getCodigo() const{
	return this->codigo;
}

int Producto::getPrecio() const{
	return this->precio;
}


Producto::~Producto(){
	
}


#endif
