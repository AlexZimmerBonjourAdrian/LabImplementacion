#include "Venta.cpp"
#include "../Datatypes/DtFecha.cpp"
#include "../Datatypes/DtFactura.cpp"
#ifndef FACTURA_H
#define FACTURA_H

class Factura : public ICollectible{
	
	private:
		int codigo;
		DtFecha * fecha;
		ICollection * productos;
		float subtotal;
		float descuento;
		float montototal;
		Venta * venta;
		static int maximo;
		
	public:
		Factura(DtFecha *,ICollection *, float,float,float);
		DtFactura * getDatos();
		~Factura();
};
#endif
