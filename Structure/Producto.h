#ifndef PRODUCTO_H
#define PRODUCTO_H
#include "string.h"
#include <iostream>
#include "../Datatypes/DtProducto.h"
#include "../interfaces/ICollectible.h"
#include "../interfaces/ICollection.h"
/*

#include "../ICollection/interfaces/ICollection.h"
*/

using namespace std;

class Producto : public ICollectible
{
private:
   int codigo;
   string descripcion;
   float precio;
   //int cantidad;
public:
    Producto(int codigo, string descripcion, float precio);
    int getCodigo();
    void setCodigo();

    string getDescripcion();
    void setDescripcion();
    ICollection * listarproducto();
    void seleccionarProducto (int CodigoP,int cantidad);
    
    void setPrecio();
    float getPrecio();


   DtProducto * getDatos(); 
   virtual ~Producto();
};
#endif

