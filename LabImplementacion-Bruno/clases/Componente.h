#include<iostream>
#include "Comun.cpp"

#ifndef COMPONENTES_H
#define COMPONENTES_H

using namespace std;

class Componente{
	private:
		int cantidad;
		Comun * producto;
	public:
		Componente(int,Comun*);
		bool coincide(Comun *);
		~Componente();
		
};
#endif
