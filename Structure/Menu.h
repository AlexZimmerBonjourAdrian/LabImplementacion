#ifndef MENU_H
#define MENU_H
#include "../Datatypes/DtSub.h"
#include "Producto.h"
class Menu
{
private:
   
public:
    Menu();
     void agregarProds(DtSub dp);
    void sacarDelista(producto p);
    bool vacio()
    virtual ~Menu();
};


