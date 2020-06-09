#include "Producto.cpp"
#ifndef CANTIDADPROD_H
#define CANTIDADPROD_H

class CantidadProd : public ICollectible{
	private:
		int cantidad;
		Producto * producto;
		
	public:
		CantidadProd(int, Producto *);
		bool coincideProd(Producto * p);
		void sumarCantidad(int cantProd);
		Producto * getProducto();
		int getCantidadRestada(int cantProd);
		virtual ~CantidadProd();
};

#endif
