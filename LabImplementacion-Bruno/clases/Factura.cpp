#include "Factura.h"
#ifndef FACTURA_CPP
#define FACTURA_CPP

using namespace std;

int Factura::maximo = 1;

Factura::Factura(DtFecha * fecha,ICollection * productos,float subtotal,float descuento,float montototal) : codigo(maximo++){
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
