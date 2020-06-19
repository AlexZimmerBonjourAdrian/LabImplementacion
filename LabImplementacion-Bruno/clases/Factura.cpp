#include "Factura.h"
#ifndef FACTURA_CPP
#define FACTURA_CPP

using namespace std;



Factura::Factura(Venta* venta_, int descuento){
	
	this->codigo=venta_->getCodigo();
	
	this->fecha=venta_->getFecha();
	
	this->productos=venta_->getProductos();
	this->subtotal=venta_->getSubtotal();
	this->descuento=descuento;
	this->montototal=venta_->getMontototal();
	this->venta=venta_;
}

int Factura::getCodigo(){
	return this->codigo;
}

DtFactura * Factura::getDatos(){
	

	DtFactura * df = new DtFactura(this->codigo,this->fecha,this->productos,this->venta->getEmpleado(),this->subtotal,this->descuento,this->montototal);
	return df;
}

Factura::~Factura(){
	
}
#endif
