#include "../interfaces/ICollectible.h"
#include<iostream>
#ifndef CLIENTE_H
#define CLIENTE_H
#include "../Datatypes/DtDireccion.cpp"
#include "../Datatypes/DtDireccion.cpp"

using namespace std;

class Cliente : public ICollectible{
	
	private:
		string telefono;
		string nombre;
		DtDireccion * direccion;
	public:
		Cliente(string,string,DtDireccion *);
		void setNombre(string);
		void setTelefono(string);
		string getNombre();
		string getTelefono();
		DtDireccion * getDireccion();
		~Cliente(); 	
		
};

#endif


