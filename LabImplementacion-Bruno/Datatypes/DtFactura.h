
#include <iostream>
#include <string.h>
#include "../interfaces/ICollectible.h"
#include "../interfaces/ICollection.cpp"
#include "../Datatypes/DtFecha.cpp"
#include "../Datatypes/DtEmpleado.cpp"
#ifndef DTFACTURA_H
#define DTFACTURA_H

using namespace std;

class DtFactura : public ICollectible{

	private:
	    int codigo;
	    DtFecha * fecha;
	    ICollection * productos;
	    DtEmpleado * trabajador;
	    float subtotal;
	    float descuento;
	    float montototal;
	    float total_iva;
	
	    
	public:
		DtFactura(int, DtFecha *, ICollection * ,DtEmpleado*, float, float,float,float);
		int getCodigo();
		DtFecha * getFecha();
		ICollection * getProductos();
		DtEmpleado * getTrabajador();
		float getSubtotal();
		float getDescuento();
		float gettotal_iva();
		float getMonto();
    	virtual ~DtFactura();
    	
};
#endif

