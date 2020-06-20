#include "DtEmpleado.cpp"
#include<iostream>
#ifndef DTREPARTIDOR_H
#define DTREPARTIDOR_H

using namespace std;

class DtRepartidor : public DtEmpleado{
	
	private:
		string medio_transporte;
		ICollection * ventas;
	
	public:
		DtRepartidor(int,string,string);
		string getMedio();
		void agregarVentas(ICollection *);
		ICollection * getVentas();
		~DtRepartidor();
		
	
};
#endif
