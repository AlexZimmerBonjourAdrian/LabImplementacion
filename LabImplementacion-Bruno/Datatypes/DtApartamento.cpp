#include<iostream>
#include "DtApartamento.h"
#ifndef APARTAMENTO_CPP
#define APARTAMENtO_CPP

using namespace std;

DtApartamento::DtApartamento(string calle, int nro_calle, string nombre_ed, int nro_ap) : DtDireccion(calle,nro_calle){
	this->nombre_ed=nombre_ed;
	this->nro=nro_ap;
}


string DtApartamento::getDpto(){
	return this->nombre_ed;
}

int DtApartamento::getPiso(){
	return this->nro;
}

DtApartamento::~DtApartamento(){
	
}

#endif
