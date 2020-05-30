#include "../h/DtConsulta.h"

// Constructor y destructor
DtConsulta::DtConsulta(const DtFecha& fechaConsulta, std::string motivo){
	this->fechaConsulta = fechaConsulta;
	this->motivo = motivo;
}

DtConsulta::~DtConsulta(){
	
}

// gets
DtFecha DtConsulta:: getFecha(){
	return fechaConsulta;
}

std::string DtConsulta:: getMotivo(){
	return motivo;
}


// sobrecarga de operadores
std::ostream& operator <<(std::ostream &salida, const DtConsulta &c){
	salida << "Fecha: " << c.fechaConsulta << "\n"
        << "Motivo: " << c.motivo;
    return salida;
}

