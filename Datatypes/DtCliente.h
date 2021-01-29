#include<iostream>
#include "../interfaces/ICollectible.cpp"
#include "DtDireccion.cpp"
#ifndef DTCLIENTE_H
#define DTCLIENTE_H

using namespace std;

class  DtCliente : public ICollectible{
	private:
		int telefono;
		string nombre;
		DtDireccion * dir;
	public:
		DtCliente(int,string,DtDireccion*);
		int getTelefono();
		string getNombre();
		DtDireccion * getDireccion();
		~DtCliente();
};

#endif
