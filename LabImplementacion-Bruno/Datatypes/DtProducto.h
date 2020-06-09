#include<iostream>
#include "../interfaces/ICollectible.cpp"
#ifndef DTPRODUCTO_H
#define DTPRODUCTO_H

using namespace std;
class DtProducto : public ICollectible{
	
	private:
	 	int Codigo;
	 	string Descripcion;
	 	float Precio;
	 	int Cantidad;
	
	public:
	
	    DtProducto(int, string, float, int);
	    int getCodigo();
	    string getDescripcion();
	    float getPrecio();
	    int getCantidad();
	    virtual ~DtProducto();
};
#endif
