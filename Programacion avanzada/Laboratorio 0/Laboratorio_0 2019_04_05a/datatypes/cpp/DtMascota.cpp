#include "..\h\DtMascota.h"

DtMascota::DtMascota(std::string _nombre, int _genero, float _peso){
    nombre = _nombre;
    genero = _genero;
    peso = _peso;
}

DtMascota::DtMascota(std::string _nombre, int _genero, float _peso, float _racionDiaria){
    nombre = _nombre;
    genero = _genero;
    peso = _peso;
	racionDiaria = _racionDiaria;
}
DtMascota::~DtMascota(){
	
}

//--- Getters -------
std::string DtMascota:: getNombre(){
    return nombre;
}

int DtMascota:: getGenero(){
    return genero;
}

float DtMascota::getPeso(){ //
    return peso;
}
