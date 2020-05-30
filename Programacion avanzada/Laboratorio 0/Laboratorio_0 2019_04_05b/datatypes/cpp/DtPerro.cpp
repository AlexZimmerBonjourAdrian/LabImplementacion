#include "..\h\DtPerro.h"

DtPerro::DtPerro(std::string _nombre, int _genero, float _peso,RazaPerro _raza, bool _vacuna):DtMascota (_nombre, _genero, _peso){
    raza = _raza;
    vacunaCachorro = _vacuna;
}

DtPerro::DtPerro(std::string _nombre, int _genero, float _peso,RazaPerro _raza, bool _vacuna, float _racionDiaria):DtMascota (_nombre, _genero, _peso, _racionDiaria){
    raza = _raza;
    vacunaCachorro = _vacuna;
}

DtPerro::~DtPerro(){
	
}


//Getters ---------------
RazaPerro DtPerro::getRaza(){
    return raza;
}


bool DtPerro::getVacunaCachorro(){
    return vacunaCachorro;
}


std::ostream& operator <<(std::ostream &salida, DtPerro *p){
	salida << "soy perro";
	return salida;
}
