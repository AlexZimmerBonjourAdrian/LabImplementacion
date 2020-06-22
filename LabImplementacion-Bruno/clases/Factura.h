#include "Venta.cpp"
#include "../Datatypes/DtFecha.cpp"
#include "../Datatypes/DtFactura.cpp"
#ifndef FACTURA_H
#define FACTURA_H

class Factura : public ICollectible{
	
	protected:
		int codigo;
		DtFecha * fecha;
		ICollection * productos;
		float subtotal;
		float descuento;
		float montototal;
		float montototal_iva;
		Venta * venta;
		
	
		
	public:
		Factura(Venta *, int);
		int getCodigo();
		DtFecha * getFecha();
		DtFactura * getDatos();
		~Factura();
};
#endif
