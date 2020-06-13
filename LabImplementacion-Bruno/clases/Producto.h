#include "../Datatypes/DtProducto.cpp"
#ifndef PRODUCTO_H
#define PRODUCTO_H

class Producto : ICollectible {
	
	private:
		int codigo;
		string descripcion;
		float precio;
	
	public:
		Producto(int,string,float);
		DtProducto * getDatos();
		virtual ~Producto();
		
};
#endif
