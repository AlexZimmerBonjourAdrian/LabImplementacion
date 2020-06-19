#include "Producto.cpp"
#include "../interfaces/ICollection.cpp"
#include "Empleado.cpp"
#include "../Datatypes/DtFecha.cpp"
#ifndef VENTA_H
#define VENTA_H

using namespace std;

class Venta : public ICollectible{
	
	private:
		int codigo;
		ICollection * cantidades;
		static int maximo;
		DtFecha * fecha;
		
	public:
		Venta(ICollection *,DtFecha *);
		void agregarProd(Producto * p, int cantProd);
		void borrarProd(Producto * p);
		void setNuevaCantidad(Producto * p, int cantProd);
		int getCodigo();
		ICollection * getProductos();
		ICollection * getCantidades();
		float getSubtotal();
		int getCantidadProd(Producto *);
		float getMontototal();
		bool buscarProd(Producto *);
		DtFecha * getFecha();
		virtual string getEmpleado() const = 0;
		~Venta();
};

#endif
