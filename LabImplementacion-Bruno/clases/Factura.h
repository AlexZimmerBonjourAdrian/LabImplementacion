#include "Venta.cpp"
#include "../Datatypes/DtFecha.cpp"
#include "../Datatypes/DtFactura.cpp"
#ifndef FACTURA_H
#define FACTURA_H

class Factura : public ICollectible{
	
	private:
		int codigo;
		string fecha;
		ICollection * productos;
		float subtotal;
		float descuento;
		float montototal;
		Venta * venta;
		
	public:
		Factura(int,string,ICollection *, float,float,float);
		DtFactura * getDatos();
		~Factura();
};
#endif
