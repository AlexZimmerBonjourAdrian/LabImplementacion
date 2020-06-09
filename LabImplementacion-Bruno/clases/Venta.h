#include "Producto.cpp"
#include "../interfaces/ICollection.cpp"
#ifndef VENTA_H
#define VENTA_H

class Venta : public ICollectible{
	
	private:
		int codigo;
		ICollection * cantidades;
		
	public:
		Venta(int);
		void agregarProd(Producto * p, int cantProd);
		void borrarProd(Producto * p);
		int getNuevaCantidad(Producto * p, int cantProd);
		~Venta();
};

#endif
