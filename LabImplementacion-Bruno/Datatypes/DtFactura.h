#ifndef DTFACTURA_H
#define DTFACTURA_H
#include <iostream>
#include <string.h>
#include "../interfaces/ICollectible.h"
#include "../interfaces/ICollection.cpp"
#include "time.h"

using namespace std;

class DtFactura : public ICollectible{

	private:
	    int codigo;
	    string fecha;
	    ICollection * productos;
	    string nombre_trabajador;
	    float subtotal;
	    float descuento;
	    float total_iva;
	    
	public:
		DtFactura(int, string, ICollection * ,string, float, float ,float);
		int getCodigo();
		string getFechaHora();
		ICollection * getProductos();
		string getNombre_Trabajador();
		float getSubtotal();
		float getDescuento();
		float gettotal_iva();
    	virtual ~DtFactura();
    	
};
#endif

