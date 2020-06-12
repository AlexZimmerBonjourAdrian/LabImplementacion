#include "Factura.h"
#ifndef FACTURA_CPP
#define FACTURA_CPP

using namespace std;

Factura::Factura(int codigo,string fecha,ICollection * productos,float subtotal,float descuento,float montototal){
	this->codigo=codigo;
	this->fecha=fecha;
	this->productos;
	this->productos=productos;
	this->subtotal=subtotal;
	this->descuento=descuento;
	this->montototal=montototal;
}

DtFactura * Factura::getDatos(){
	return new DtFactura(this->codigo,this->fecha,this->productos,this->venta->getEmpleado(),this->subtotal,this->descuento,this->montototal);
}

Factura::~Factura(){
	
}
#endif
