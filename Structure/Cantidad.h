#ifndef Cantidad_H
#define Cantidad_H
#include "Venta.h"
class Cantidad
{
private:
     int cantidad 
public:
   void Cantidad();
    bool existeProd(Producto p);
    int modificarCantidad(int CantProd);
    borrarInstancia();
    Producto getproducto();
    int getCant(int cantProd);
    virtual ~Cantidad();
};





