#include "../Structure/Producto.h"
#include <iostream>



Producto::Producto(int Codigo, string Descripcion, float Precio, int cantidad)
{
    this->codigo = Codigo;
    this->descripcion = Descripcion;
    this->precio = Precio;
    //Ojo esto no esta deacuerdo al Modelo de Dominio es solo para testear
    this->cantidad=cantidad;
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

DtProducto *Producto::getDatos()
{

    DtProducto * DtPrData = new DtProducto(this->Codigo,this->Descripcion,this->Precio,this->cantidad);
    return DtPrData;
}



virtual ~Producto(){
}

