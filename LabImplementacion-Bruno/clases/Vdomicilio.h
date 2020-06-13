#include<iostream>
#include "Venta.cpp"
#include "../Datatypes/DtDireccion.cpp"
#include "Repartidor.cpp"
#include "Cliente.cpp"
#ifndef VDOMICILIO_H
#define VDOMICILIO_H

using namespace std;

class Vdomicilio : public Venta{
	private:
		DtDireccion * direccion;
		string nombre_rec;
		string telefono_rec;
		Repartidor * repartidor;
		Cliente * cliente;
		
	public:
		Vdomicilio(ICollection *,DtDireccion *,string,string,Repartidor*, Cliente *);
		DtDireccion * getDireccion();
		string getNombre();
		string getEmpleado() const;
		~Vdomicilio();
};




#endif
