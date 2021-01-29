#include "../interfaces/ICollectible.h"
#include<iostream>
#ifndef CLIENTE_H
#define CLIENTE_H
#include "../Datatypes/DtDireccion.cpp"

using namespace std;

class Cliente : public ICollectible{
	
	private:
		int telefono;
		string nombre;
		DtDireccion * direccion;
	public:
		Cliente(int,string,DtDireccion *);
		string getNombre();
		int getTelefono();
		DtDireccion * getDireccion();
		~Cliente(); 	
		
};

#endif


