#include "Producto.cpp"
#ifndef CANTIDADPROD_H
#define CANTIDADPROD_H

class CantidadProd : public ICollectible{
	private:
		int cantidad;
		Producto * producto;
		
	public:
		int getCantidad();
		CantidadProd(int, Producto *);
		bool coincideProd(Producto * p);
		void sumarCantidad(int cantProd);
		void restarCantidad(int cantProd);
		Producto * getProducto();
		bool esMenu();
		DtProducto * getDtProducto();
		int getCantidadRestada(int cantProd);
		virtual ~CantidadProd();
};

#endif
