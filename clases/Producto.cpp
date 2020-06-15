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
	return  new DtProducto(this->codigo,this->descripcion, this->precio,0,this->tipo);
}

void Producto::setTipo(string tipo){
	this->tipo=tipo;
}

void Producto::setCodigo(int codigo)
{
	this->codigo=codigo;
}

void Producto::setPrecio(int Precio)
{
this->precio=Precio;
}

string Producto::getTipo(){
	return this->tipo;
}

int Producto::getCodigo(){
	return this->codigo;
}

float Producto::getPrecio()
{
	return this->precio;
}



Producto::~Producto(){
	
}


#endif
