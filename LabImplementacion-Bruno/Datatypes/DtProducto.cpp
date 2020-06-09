#include "DtProducto.h"
#include <iostream>

#ifndef DTPRODUCTO_CPP
#define DTPRODUCTO_CPP

DtProducto::DtProducto(int codigo, string Descripcion, float precio, int cantidad)
{
    this->Codigo = codigo;
    this->Descripcion = Descripcion;
    this->Precio = precio;
    this->Cantidad = cantidad;
}

int DtProducto::getCodigo()
{
    return this->Codigo;
}

string DtProducto::getDescripcion()
{
    return this->Descripcion;
}

float DtProducto::getPrecio()
{
    return this->Precio;
}

int DtProducto::getCantidad()
{
    return this->Cantidad;
}
DtProducto::~DtProducto(){
}
#endif
