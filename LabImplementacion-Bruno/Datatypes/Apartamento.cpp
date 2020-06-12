#include<iostream>
#include "Apartamento.h"
#ifndef APARTAMENTO_CPP
#define APARTAMENtO_CPP

using namespace std;

Apartamento::Apartamento(string calle, int nro_calle, string nombre_ed, int nro_ap) : DtDireccion(calle,nro_calle){
	this->nombre_ed=nombre_ed;
	this->nro=nro_ap;
}

int Apartamento::getNro(){
	return this->nro;
}

Apartamento::~Apartamento(){
	
}

#endif
