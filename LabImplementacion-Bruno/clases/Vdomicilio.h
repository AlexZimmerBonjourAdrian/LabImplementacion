#include<iostream>
#include "Venta.cpp"
#include "../Datatypes/DtDireccion.cpp"
#include "../Datatypes/DtFecha.cpp"
#include "Repartidor.cpp"
#include "Cliente.cpp"
#include "../Datatypes/DtRepartidor.cpp"
#ifndef VDOMICILIO_H
#define VDOMICILIO_H

using namespace std;

class Vdomicilio : public Venta{
	private:
		DtDireccion * direccion;
		string nombre_rec;
		long int telefono_rec;
		Repartidor * repartidor;
		Cliente * cliente;
		
	public:
		Vdomicilio(ICollection *,DtFecha *,DtDireccion *,string,long int,Repartidor*, Cliente *);
		DtDireccion * getDireccion();
		string getNombre();
		DtEmpleado * getEmpleado() const;
		~Vdomicilio();
};




#endif
