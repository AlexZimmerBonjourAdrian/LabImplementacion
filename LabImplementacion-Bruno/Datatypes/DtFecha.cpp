#include "DtFecha.h"
#ifndef DTFECHA_CPP
#define DTFECHA_CPP

DtFecha::DtFecha(int anio, int mes, int dia){
    this->anio=anio;
    this->mes=mes;
    this->dia=dia;
}

int DtFecha::getAnio(){
	return this->anio;
}

int DtFecha::getMes(){
	return this->mes;
}

int DtFecha::getDia(){
	return this->dia;
}
DtFecha::~DtFecha()
{

}
#endif
