#include "Producto.h"
#include "../ICollection/interfaces/ICollectible.h"
#include <iostream>
class Venta :: ICollectible
{
private:
    int codigo;
public:
    Venta(int codigo);
    void setCodigo(int codigo);
    int getCodigo();
    agregarPod(Producto p,int cantProd);
    borrarProd(Producto p);
    int getCantidad(Producto p,int cantProd);
    quitarCantProd(Producto p);
    virtual ~Venta();
};


