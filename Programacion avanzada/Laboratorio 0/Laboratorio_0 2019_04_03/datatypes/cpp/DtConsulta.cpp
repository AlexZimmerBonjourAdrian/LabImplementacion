#include "..\h\DtConsulta.h"

// Constructor y destructor
DtConsulta::DtConsulta(const DtFecha& fechaConsulta, std::string motivo){
	this->fechaConsulta = fechaConsulta;
	this->motivo = motivo;
}

DtConsulta::~DtConsulta(){
	
}

// gets
DtFecha DtConsulta:: getFechaConsulta(){
	return fechaConsulta;
}

std::string DtConsulta:: getMotivo(){
	return motivo;
}


