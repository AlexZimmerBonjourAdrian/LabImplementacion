#include "DtFactura.h"


DtFactura::DtFactura(int codigo, string fecha, ICollection * productos, string nombre_trabajador,float subtotal,float descuento, float total_iva){
	this->codigo=codigo;
	this->fecha = fecha;
	this->nombre_trabajador=nombre_trabajador;
	this->descuento= descuento;
	this->productos= productos;
	this->subtotal=subtotal;
	this->total_iva = total_iva;
}

int DtFactura::getCodigo()
{
    return this->codigo;
}

string DtFactura::getFechaHora()
{
    return this->fecha;
}
ICollection * DtFactura::getProductos()
{
    return this->productos;
}

string DtFactura::getNombre_Trabajador()
{
return this->nombre_trabajador;
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
	
}



