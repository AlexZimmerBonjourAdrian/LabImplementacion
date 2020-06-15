#include "../Datatypes/DtProducto.cpp"
#ifndef PRODUCTO_H
#define PRODUCTO_H

class Producto : public ICollectible {
	
	private:
		int codigo;
		string descripcion;
		float precio;
		DtProducto * P;
		string tipo;

	
	public:
		Producto(int,string,float,string);
		void setCodigo();
		int getCodigo();
		DtProducto * getDatos();
		void setPrecio(float);
		float getPrecio();
		void setTipo(string); 
		string getTipo();
		virtual ~Producto();
		
};
#endif
