#include "../h/DtGato.h"


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


// sobrecarga de operadores
std::ostream& operator <<(ostream &salida, const DtGato &gato){
	salida << "Nombre: " << gato.nombre<< "\n"
        << "Genero: " << strGenero(gato.genero) << "\n"
        << "Peso: " << gato.peso <<" kg" << "\n"
        << "Racion diaria: " << gato.racionDiaria << " gramos.\n"
        << "Tipo de pelo: " << strTipoPelo(gato.pelo) ;
    return salida;
}
