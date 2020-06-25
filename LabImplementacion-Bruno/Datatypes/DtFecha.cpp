#include "DtFecha.h"
#ifndef DTFECHA_CPP
#define DTFECHA_CPP

DtFecha::DtFecha(int anio, int mes, int dia,int hora, int minutos){
    this->anio=anio;
    this->mes=mes;
    this->dia=dia;
    this->hora=hora;
    this->minutos=minutos;
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

int DtFecha::getHora(){
	return this->hora;
}

int DtFecha::getMinutos(){
	return this->minutos;
}

DtFecha::~DtFecha()
{

}
#endif
