#include "..\h\Gato.h"

Gato::Gato(string _nombre, Genero _genero, float _peso, TipoPelo _pelo): Mascota (_nombre,_genero,_peso){
    pelo = _pelo;
}

//--- Metodo abstracto heredado de mascota -------
float Gato::obtenerRacionDiaria(){
    const float constante = 0.015;
    return (peso * constante);
}

TipoPelo Gato::getPelo(){
    return  pelo;
}

void Gato::setPelo(TipoPelo _pelo){
    pelo = _pelo;
}


