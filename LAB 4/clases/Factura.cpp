#include "Factura.h"
#ifndef FACTURA_CPP
#define FACTURA_CPP

using namespace std;



Factura::Factura(Venta* venta_, int descuento){
	float subtotal_=venta_->getSubtotal();
	this->codigo=venta_->getCodigo();
	this->fecha=venta_->getFecha();
	this->productos=venta_->getProductos();
	this->subtotal=subtotal_;
	this->descuento=descuento;
	float monto=subtotal_-((subtotal_*descuento)/100);
	this->montototal=monto;
	this->montototal_iva=monto*1.22;
	this->venta=venta_;
	
}


DtFactura * Factura::getDatos(){
	
	DtFactura * df = new DtFactura(this->codigo,this->fecha,this->productos,this->venta->getEmpleado(),this->subtotal,this->descuento,this->montototal,this->montototal_iva);
	return df;
}

int Factura::getCodigo(){
	return this->codigo;
}





DtFecha * Factura::getFecha(){
	return this->fecha;
}

Factura::~Factura(){
	IIterator * it = this->productos->getIterator();
	while(it->hasCurrent()){
		DtProducto * dp = (DtProducto*)it->getCurrent();
		it->next();
		this->productos->remove(dp);
		delete dp;
	}
	delete this->productos;
	delete it;
}
#endif
