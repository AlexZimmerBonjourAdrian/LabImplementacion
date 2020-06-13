
#include <iostream>
#include <string.h>
#include "../interfaces/ICollectible.h"
#include "../interfaces/ICollection.cpp"
#include "../Datatypes/DtFecha.cpp"
#ifndef DTFACTURA_H
#define DTFACTURA_H

using namespace std;

class DtFactura : public ICollectible{

	private:
	    int codigo;
	    DtFecha * fecha;
	    ICollection * productos;
	    string nombre_trabajador;
	    float subtotal;
	    float descuento;
	    float total_iva;
	    
	public:
		DtFactura(int, DtFecha *, ICollection * ,string, float, float ,float);
		int getCodigo();
		DtFecha * getFecha();
		ICollection * getProductos();
		string getNombre_Trabajador();
		float getSubtotal();
		float getDescuento();
		float gettotal_iva();
    	virtual ~DtFactura();
    	
};
#endif

