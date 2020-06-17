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
		int getCodigo() const;
		virtual DtProducto * getDatos() const = 0;
		void setTipo(string);
		string getTipo() const;
		string getDescripcion() const;
		int getPrecio() const;
		virtual ~Producto();
		
};
#endif
