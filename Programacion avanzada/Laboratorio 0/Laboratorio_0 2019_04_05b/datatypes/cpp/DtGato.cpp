#include "..\h\DtGato.h"


DtGato::DtGato(std::string _nombre, int _genero, float _peso, TipoPelo _pelo): DtMascota(_nombre,_genero,_peso){
    pelo = _pelo;
}

DtGato::DtGato(std::string _nombre, int _genero, float _peso, TipoPelo _pelo, float _racionDiaria): DtMascota(_nombre,_genero,_peso,_racionDiaria){
    pelo = _pelo;
}

DtGato::~DtGato(){
	
}

TipoPelo DtGato::getPelo(){
    return  pelo;
}


std::ostream& operator <<(std::ostream &salida, DtGato *p){
	salida << "soy gato";
	return salida;
}

