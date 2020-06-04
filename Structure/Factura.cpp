#include "Factura.h"
#include "../Datatypes/DtFecha.h"
#include "../Datatypes/DtFactura.h"
#include <iostream>
/*
#include "../ICollection/interfaces/ICollectible.h"
#include "../ICollection/interfaces/ICollection.h"
*/
Factura::Factura(int codigo, DtFecha fecha,ICollection producto, float subtotal,float descuento,float monototal)
{
    /*
    this->Codigo;
    this->descuento;
    this->monototal;
    this->producto;
    */
    this->Codigo=codigo;

    this->producto=productos;
    this->descuento=descuento;
    this->fecha=fecha;
    this->monototal=monototal;
  
}

Factura::setCodigo(int Codigo)
{
    this->Codigo=Codigo;
}

int Factura::getCodigo()
 {
     return this->Codigo;
 }

 Factura::setDescuento(float Descuento)
 {
     this->descuento=Descuento;
 }

 float Factura::getDescuento()
 {
     return this->descuento;
 }

Factura::setSubtotal(float Subtotal)
{
    this->subtotal= Subtotal;
}

float Factura::getSubtotal()
{
   return this->subtotal;
}

void Factura::setMonototal(float montototal)
{
this->monototal=montototal;
}
float Factura::getMontotal()
{
    return this->montototal;
}

void Factura::setproducto(DtProducto producto)
{
    this->producto=producto;
}

 ICollection * getProducto()
 {
     this->producto;
 }

  DtFactura * Factura::getDatos()
  {
      return DtFactura::DtFactura(this->codigo,this->Fecha,this->producto,this->subtotal,this->descuento,this->total_iva);
  }
 
 Factura::~Factura(){
 }