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
		
	public:
		Factura(Venta *, int);
		int getCodigo();
		DtFactura * getDatos();
		~Factura();
};
#endif
