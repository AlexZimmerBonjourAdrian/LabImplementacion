#include "../Datatypes/DtProducto.cpp"
#ifndef PRODUCTO_H
#define PRODUCTO_H

class Producto : public ICollectible {
	
	private:
		int codigo;
		string descripcion;
		float precio;
		string tipo;
	
	public:
		Producto(int,string,float);
		int getCodigo();
		DtProducto * getDatos();
		void setTipo(string); 
		string getTipo();
		virtual ~Producto();
		
};
#endif
