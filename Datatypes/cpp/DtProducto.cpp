#include "../DtProducto.h"
#include <iostream>
#include "string.h"
DtProducto::DtProducto(){

}

DtProducto::DtProducto(int codigo, string Descripcion, float precio, int cantidad)
{
    this->Codigo = codigo;
    this->Description = Descripcion;
    this->Precio = precio;
    this->Cantidad = cantidad;
}

int DtProducto::getCodigo()
{
    return this->Codigo;
}

string DtProducto::getDescripcion()
{
    return this->Description;
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

