#include "Producto.cpp"
#include<iostream>
#ifndef COMUN_H
#define COMUN_H

using namespace std;

class Comun : public Producto{
	

	public:
		Comun(int,string,float);
		DtProducto * getDatos() const;
		void borrar(Producto *);
		~Comun();
};

#endif
