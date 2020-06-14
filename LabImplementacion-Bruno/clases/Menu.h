#include "../interfaces/ICollection.cpp"
#include "Comun.cpp"
#include<iostream>
#ifndef MENU_H
#define MENU_H

using namespace std;

class Menu : public Producto {
	private:
		ICollection * componentes;
	public:
		Menu(int,string,float);
		void agregarProd(Comun*,int);
		void sacardeLista(Comun * p);
		bool vacio();
		~Menu();
};

#endif

