#include "DtRepartidor.h"
#ifndef DTREPARTIDOR_CPP
#define DTREPARTIDOR_CPP
#include<iostream>

using namespace std;

DtRepartidor::DtRepartidor(int codigo, string nombre,string medio_transporte) : DtEmpleado(codigo,nombre){
	this->medio_transporte=medio_transporte;
}

void DtRepartidor::agregarVentas(ICollection * ventas){
		this->ventas=ventas;
}

string DtRepartidor::getMedio(){
	return this->medio_transporte;
}

ICollection * DtRepartidor::getVentas(){
	return this->ventas;
}

DtRepartidor::~DtRepartidor(){
	delete this->ventas;
}

#endif
