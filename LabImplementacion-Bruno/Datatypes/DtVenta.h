#include<iostream>
#include "../interfaces/ICollection.cpp"
#include "../Datatypes/DtFecha.cpp"
#ifndef DTVENTA_H
#define DTVENTA_H

using namespace std;

class DtVenta : public ICollectible{
	
	private:
		int codigo;
		ICollection * productos;
		DtFecha * fecha;
		string estado;
	
	public:
		DtVenta(int,ICollection*,DtFecha*,string);
		int getCodigo();
		ICollection * getProductos();
		DtFecha * getFecha();
		string getEstado();
		~DtVenta();
		
};

#endif
