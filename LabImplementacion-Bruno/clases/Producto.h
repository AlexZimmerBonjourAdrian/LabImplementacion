#include "../Datatypes/DtProducto.cpp"
#ifndef PRODUCTO_H
#define PRODUCTO_H

class Producto : public ICollectible {
	
	private:
		int codigo;
		string descripcion;
		float precio;
	
	public:
		Producto(int,string,float);
		int getCodigo();
		DtProducto * getDatos();
		virtual ~Producto();
		
};
#endif
