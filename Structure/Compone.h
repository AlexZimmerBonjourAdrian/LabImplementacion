#include "Menu.h"
class Compone
{
private:
    int cantidad
public:
    Compone(int cantidad);
    Menu getProducto(Producto p);
    void coincide(Producto p);
    void borrarInstancia();
    virtual ~Compone();
};


