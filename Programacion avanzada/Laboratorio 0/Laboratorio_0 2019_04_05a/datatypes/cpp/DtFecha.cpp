#include "..\h\DtFecha.h"


// Constructores
DtFecha::DtFecha(){
	//Funcion que obtiene la fecha y hora actual del sistema
	// La funcion time_t time(time_t *time)
	time_t fechaHoraActual = time(0);
	
	//Convierte fecha y hora a estructura tipo UTC
	tm * strcFechaHora = gmtime(&fechaHoraActual);
	//	struct tm{
	//		int tm_sec; 	//Segundos 0-61
	//		int tm_min; 	//Minutos del 0-59
	//		int tm_hour; 	//Horas del 0-24
	//		int tm_mday; 	//Dias del 1-31
	//		int tm_mon; 	//Meses de 0-11
	//		int tm_year; 	//Anios desde 1900
	//		int tm_wday; 	//Dias desde el domingo
	//		int tm_yday; 	//Dias desde el primero de enero
	//		int tm_isdst; 	//Manejo del horario de verano
	//	};
	
	//Asigna los datos necesarios
	this->dia = strcFechaHora->tm_mday;
	this->mes = strcFechaHora->tm_mon;
	this->anio = strcFechaHora->tm_year - 100 + 2000;
}


DtFecha::DtFecha(int dia, int mes, int anio){
	this->dia = dia;
	this->mes = mes;
	this->anio = anio;
}


DtFecha::DtFecha(const DtFecha &fecha){
    this->dia = fecha.dia;
    this->mes = fecha.mes;
    this->anio = fecha.anio;
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










