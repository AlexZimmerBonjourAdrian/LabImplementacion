#include "Producto.cpp"
#include "../interfaces/ICollection.cpp"
#include "Empleado.cpp"
#ifndef VENTA_H
#define VENTA_H

using namespace std;

class Venta : public ICollectible{
	
	private:
		int codigo;
		ICollection * cantidades;
		
	public:
		Venta(int,ICollection *);
		void agregarProd(Producto * p, int cantProd);
		void borrarProd(Producto * p);
		int getNuevaCantidad(Producto * p, int cantProd);
		ICollection * getCantidades();
		virtual string getEmpleado() const = 0;
		~Venta();
};

#endif
