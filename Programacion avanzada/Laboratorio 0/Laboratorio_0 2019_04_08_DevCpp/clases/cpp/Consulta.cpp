#include "..\h\Consulta.h"
#include <iostream>

// constructor y destructor
Consulta::Consulta(const DtFecha& _fechaConsulta, std::string _motivo){
	this->fechaConsulta=_fechaConsulta;
	this->motivo=_motivo;
}

Consulta::~Consulta(){ 
	
}

// gets
DtFecha Consulta::getFechaConsulta(){
	return fechaConsulta;
}

// sets
std::string Consulta::getMotivo(){
	return motivo;
}

void Consulta::setFechaConsulta(const DtFecha& _fechaConsulta){
	this->fechaConsulta=_fechaConsulta;
}

void Consulta::setMotivo(std::string _motivo){
	this->motivo=_motivo;
}
