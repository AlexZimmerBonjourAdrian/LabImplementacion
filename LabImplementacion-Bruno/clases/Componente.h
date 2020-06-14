#include<iostream>
#include "Comun.cpp"
#include "../interfaces/ICollectible.cpp"
#ifndef COMPONENTES_H
#define COMPONENTES_H

using namespace std;

class Componente : public ICollectible{
	private:
		int cantidad;
		Comun * producto;
	public:
		Componente(int,Comun*);
		bool coincide(Comun *);
		~Componente();
		
};
#endif
