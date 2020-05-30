#include "DtFecha.h"


// Constructores
DtFecha::DtFecha(){
	this->dia = 1;
	this->mes = 1;
	this->anio = 2000;
}


DtFecha::DtFecha(int dia, int mes, int anio){
	this->dia = dia;
	this->mes = mes;
	this->anio = anio;
}


DtFecha::DtFecha(DtFecha &fecha){
	this->dia = fecha.getDia();
	this->mes = fecha.getMes();
	this->anio = fecha.getAnio();
}


DtFecha::~DtFecha(){
	
}

// gets y sets
void DtFecha::setDia(int dia){
	this->dia = dia;
}


void DtFecha::setMes(int mes){
	this->mes = mes;
}
void DtFecha::setAnio(int anio){
	this->anio = anio;
}


int DtFecha::getDia(){
	return this->dia;
}


int DtFecha::getMes(){
	return this->mes;
}


int DtFecha::getAnio(){
	return this->anio;
}


bool operator <(const DtFecha &f1, const DtFecha &f2){
	if (f1.anio < f2.anio)	return true;
	if (f1.anio > f2.anio)	return false;
	// si llega hasta aca, son el mismo anio y hay que verificar el mes
	if (f1.mes < f2.mes)	return true;
	if (f1.mes > f2.mes)	return false;
	// si llega hasta aca, son el mismo anio y el mismo mes, hay que verificar el dia
	if (f1.dia < f2.dia)	return true;
	if (f1.dia > f2.dia)	return false;
	// si llega hasta aca, es la misma fecha, y retorna false
	return false;
}


std::ostream& operator <<(std::ostream &salida, const DtFecha &f){
	salida << f.dia << "/" << f.mes << "/" << f.anio;
	return salida;
}






