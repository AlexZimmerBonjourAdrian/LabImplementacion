#include "string.h"
#include "../ICollection/interfaces/ICollectible.h"
using namespace std;
class DtProducto :: public ICollectible
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

