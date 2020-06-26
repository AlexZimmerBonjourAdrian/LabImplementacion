#include "Empleado.cpp"
#include<iostream>
#include "../clases/Venta.cpp"
#ifndef REPARTIDOR_H
#define REPARTIDOR_H
#include "../interfaces/IDictionary.cpp"
#include "../Datatypes/DtRepartidor.cpp"
#include "../clases/Factura.cpp"
using namespace std;

class Repartidor : public Empleado{
	private:
		string medio_de_transporte;
		IDictionary * ventas;
		
	public:
		Repartidor(string,string,IDictionary *);
		string getMedio();
		IDictionary * getVentas();
		DtEmpleado * getDatos() const;
		void agregarVenta(Venta *);
		~Repartidor();
	
};

#endif
