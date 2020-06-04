#include "../Datatypes/DtFactura.h"
#include "../Datatypes/DtFecha.h"
#include "../Datatypes/DtProducto.h"
#include "../ICollection/interfaces/ICollectible.h"
#include "../ICollection/interfaces/ICollection.h"

class Factura :: public ICollection
{
private:
    int Codigo;
    DtFecha Fecha;
    ICollection producto;
    float subtotal;
    float descuento;
    float monototal; 
    
public:
    Factura(int Codigo, DtFecha Fecha,ICollection producto,float subtotal,float descuento,float monototal);
    void setCodigo(int Codigo);
    int getCodigo();
    void setFecha(DtFecha Fecha);
    DtFecha getFecha();
    void setproducto(DtProducto producto);
    ICollection getProducto();
    void setSubtotal(float substotal);
    float getSubstotal();
    void setMonototal(float Monototal);
    float getMonototal();    
    DtFactura * getDatos();
    virtual ~Factura();
};


