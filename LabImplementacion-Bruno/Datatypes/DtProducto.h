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
	 	string tipo;
	
	public:
	
	    DtProducto(int, string, float, int,string);
	    int getCodigo();
	    string getDescripcion();
	    float getPrecio();
	    string getTipo();
	    int getCantidad();
	    virtual ~DtProducto();
};
#endif
