#include <iostream>
#include "string.h"
#include "../Datatypes/DtProducto.h"
#include "../ICollection/interfaces/ICollectible.h"
#include "../ICollection/interfaces/ICollection.h"
using namespace std;

class Producto :: public ICollectible
{
private:
   int codigo;
   string descripcion;
   float precio;
public:
    Producto(int codigo, string descripcion, float precio);
    int getCodigo();
    void setCodigo();

    string getDescripcion();
    void setDescripcion();

    void setPrecio();
    float getPrecio();


   DtProducto * getDatos(); 
   virtual ~Producto();
};


