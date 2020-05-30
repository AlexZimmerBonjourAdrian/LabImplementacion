#include "..\h\Mascota.h"
#include <iostream>

using namespace std;

//Constructor de la clase mascota
Mascota::Mascota(string _nombre, Genero _genero, float _peso){
    nombre = _nombre;
    genero = _genero;
    peso = _peso;
}
//--- Geter y Seter -------
string Mascota:: getNombre(){
    return nombre;
}

Genero Mascota:: getGenero(){
    return genero;
}

float Mascota::getPeso(){ //
    return peso;
}

void Mascota::setNombre(string _nombre){
    nombre = _nombre;
}

void Mascota::setGenero(Genero _genero){
    genero = _genero;
}

void Mascota::setPeso(float _peso){
    peso = _peso;
}
