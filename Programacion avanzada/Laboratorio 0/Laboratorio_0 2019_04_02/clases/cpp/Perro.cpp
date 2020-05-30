#include "..\h\perro.h"
//#include "Mascota.h"

Perro::Perro(string _nombre, Genero _genero, float _peso,RazaPerro _raza, bool _vacuna):Mascota (_nombre, _genero, _peso){
    raza = _raza;
    vacunaCachorro = _vacuna;
}

Perro::~Perro(){}

//---Seter y Geter ---------------
RazaPerro Perro::getRaza(){
    return raza;
}

bool Perro::getVacunaCachorro(){
    return vacunaCachorro;
}

void Perro::setRaza(RazaPerro _raza){
    raza = _raza;
}

void Perro::setVacunaCachorro(bool _vacuna){
    vacunaCachorro = _vacuna;
}

//--- Metodo abstracto heredado de mascota -------
float Perro::obtenerRacionDiaria(){
    const float constante = 0.025;
    return (peso * constante);
}
