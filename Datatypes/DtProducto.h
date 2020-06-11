#ifndef DTPRODUCTO_H
#define DTPRODUCTO_H
#include "string.h"

#include "../interfaces/ICollectible.h"
using namespace std;
class DtProducto : public ICollectible
{
private:
 int codigo;
 string Descripcion;
 float Precio;
 int Cantidad
public:
    DtProducto(int Codigo, string Descripcion, float Precio, int Cantidad);
    int getCodigo();
    string getDescripcion();
    float getPrecio();
    int getCantidad();
    virtual ~DtProducto();
};
#endif
