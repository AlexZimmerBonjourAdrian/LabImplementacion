#include "DtProducto.h"
#include <iostream>

#ifndef DTPRODUCTO_CPP
#define DTPRODUCTO_CPP

DtProducto::DtProducto(int codigo, string Descripcion, float precio, int cantidad,string tipo)
{
    this->Codigo = codigo;
    this->Descripcion = Descripcion;
    this->Precio = precio;
    this->Cantidad = cantidad;
    this->tipo=tipo;
}

int DtProducto::getCodigo()
{
    return this->Codigo;
}

string DtProducto::getTipo(){
	return this->tipo;
}

string DtProducto::getDescripcion()
{
    return this->Descripcion;
}

float DtProducto::getPrecio()
{
    return this->Precio;
}

void DtProducto::setCantidad(int cantidad){
	this->Cantidad=cantidad;
}

int DtProducto::getCantidad()
{
    return this->Cantidad;
}
DtProducto::~DtProducto(){
}
#endif
