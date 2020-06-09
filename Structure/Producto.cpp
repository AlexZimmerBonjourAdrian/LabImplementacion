#include <iostream>
#include "Producto.h"

Producto::Producto(int Codigo, string Descripcion, float Precio)
{
    this->codigo = Codigo;
    this->descripcion = Descripcion;
    this->precio = Precio;
}
int Producto::getCodigo()
{
return this->codigo; 
}

void Producto::setCodigo(int Codigo)
{
 this->codigo = Codigo;
}

void Producto::setDescripcion(string Descripcion)
{
 this->Descripcion = Descripcion;
}

string Producto::getDescripcion()
{
    return this->Descripcion;
}


void Producto::setPrecio()
{
    this->Precio = Precio;
}

float Producto::getPrecio()
{
    return this->Precio;
}

DtProducto * Producto::getData()
{
    return DtProducto::DtProducto(this->Codigo,this->Descripcion,this->Precio,this->Cantidad)
}

virtual ~Producto(){
}

