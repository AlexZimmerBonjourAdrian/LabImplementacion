#ifndef DTFACTURA_H
#define DTFACTURA_H
#include <iostream>
#include <string.h>
#include "DtProducto.h"
using namespace std;
class DtFactura
{
private:
    int codigo;
    date fecha;
     time hora;
    DtProducto * productos;
    string nombre_trabajador;
    float subtotal;
    float descuento;
    float total_iva;
public:
DtFactura(float codigo,date fecha, time hora, float subtotal, float descuento,float total_iva);
 int getCodigo();
 DtProducto * getProductos();
 
 string getNombre_Trabajador();
 float getSubtotal();
 float getDescuento();
 float gettotal_iva();
 
     
 
    
    virtual ~DtFactura();
};
#endif

