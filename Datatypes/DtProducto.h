#include "string.h"
class DtProducto
{
private:
 int Codigo;
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

