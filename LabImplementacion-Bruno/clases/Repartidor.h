#include "Empleado.cpp"
#include<iostream>
#ifndef REPARTIDOR_H
#define REPARTIDOR_H
#include "../interfaces/IDictionary.cpp"
#include "../Datatypes/DtRepartidor.cpp"
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
		~Repartidor();
	
};

#endif
