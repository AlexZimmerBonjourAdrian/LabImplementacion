#ifndef DTFACTURA_H
#define DTFACTURA_H
#include <iostream>
#include <string.h>
//#include "DtProducto.h"
#include "../ICollection/interfaces/ICollectible.h"
#include "../ICollection/interfaces/ICollection.h"
#include "time.h"
using namespace std;
class DtFactura :: public ICollectible
{
private:
    int codigo;
    time_t FechaHora;
    ICollection * productos;
    string nombre_trabajador;
    float subtotal;
    float descuento;
    float total_iva;
public:
DtFactura(float codigo,time_t FechaHora,ICollection * producto ,float subtotal, float descuento,float total_iva);
int getCodigo();
time_t getFechaHora();
 ICollection * getProductos();
 string getNombre_Trabajador();
 float getSubtotal();
 float getDescuento();
 float gettotal_iva();
 
 
     
 
    
    virtual ~DtFactura();
};
#endif

