#include "../DtFactura.h"
using namespace std;
DtFactura::DtFactura(float codigo,time hora, string Nombre_Trabajador, DtProducto * productos,float subtotal,float descuento, float total_iva){
this->codigo=codigo;
this->fecha = fecha;
this->nombre_trabajador=Nombre_Trabajador;
this->descuento= descuento;
this->productos= productos;
this->subtotal=subtotal;
this->total_iva = total_iva;
}

int DtFactura::getCodigo()
{
    return this->codigo;
}

time_t DtFactura::getFechaHora()
{
    return this->getFechaHora;
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

DtFactura::gettotal_iva()
{
    return this->total_iva;
}




