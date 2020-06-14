#include "../interfaces/ICollection.cpp"
#include "Producto.cpp"
#include<iostream>
#ifndef MENU_H
#define MENU_H

using namespace std;

class Menu : public Producto {
	private:
		ICollection * componentes;
	public:
		Menu();
		void agregarProd(int,int);
		void sacardeLista(Producto * p);
		bool vacio();
		~Menu();
};

#endif

