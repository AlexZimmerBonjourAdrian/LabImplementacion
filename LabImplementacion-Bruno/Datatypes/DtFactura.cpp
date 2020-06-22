#include "DtFactura.h"
#ifndef DTFACTURA_CPP
#define DTFACTURA_CPP

DtFactura::DtFactura(int codigo, DtFecha * fecha, ICollection * productos, DtEmpleado * trabajador,float subtotal,float descuento,float montototal, float total_iva){
	this->codigo=codigo;
	this->fecha = fecha;
	this->trabajador=trabajador;
	this->descuento= descuento;
	this->productos= productos;
	this->subtotal=subtotal;
	this->montototal=montototal;
	this->total_iva = total_iva;
}

float DtFactura::getMonto(){
	return this->montototal;
}



int DtFactura::getCodigo()
{
    return this->codigo;
}

DtFecha * DtFactura::getFecha()
{
    return this->fecha;
}
ICollection * DtFactura::getProductos()
{
    return this->productos;
}

DtEmpleado * DtFactura::getTrabajador()
{
return this->trabajador;
}

float DtFactura::getDescuento()
{
    return this->descuento;
}

float DtFactura::getSubtotal()
{
    return this->subtotal;
}

float DtFactura::gettotal_iva()
{
    return this->total_iva;
}

DtFactura::~DtFactura(){
	delete trabajador;
}


#endif
