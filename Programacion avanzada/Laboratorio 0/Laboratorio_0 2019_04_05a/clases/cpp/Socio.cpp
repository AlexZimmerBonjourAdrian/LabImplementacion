#include "..\h\Socio.h"
using namespace std;

Socio::Socio(string ci, string nombre, DtFecha FechaIngreso, DtMascota MiMascota){
	this->ci=ci;
	this->nombre=nombre;
	this->FechaIngreso=FechaIngreso;
	
	//DtPerro *EsPerro = dynamic_cast<*sascota[&MiMascota)
	//if(EsPerro){
	
	if (dynamic_cast<DtPerro*>(&MiMascota))
		this->MisMascotas[0]= new Perro(
			MiMascota->getnombre(),
			MiMascota->getGenero(),
			MiMascota->getPeso(),
			MiMascota->getRazaPerro(),
			MiMascota->getVacunaCachorro()
		);
	}
	else{
		this->MisMascotas[0]= new Gato(
		MiMascota->getNombre,
		MiMascota->getGenero,
		MiMascota->getPeso,
		MiMascota->getPelo
		);
	}
	
}

Socio::~Socio(){
	// Destructor
}


// Set
void Socio::setCi(std::string ci){
	this->ci = ci;
}

void Socio::setNombre(string nombre){
	this->nombre = nombre;
}

void Socio::setFechaIngreso(DtFecha fechaIngreso){
	this->FechaIngreso = FechaIngreso;
}

// Get
std::string Socio::getCi(){
	return this->ci;
}

std::string Socio::getNombre(){
	return this->nombre;
}

DtFecha Socio::getFechaIngreso(){
	return this->FechaIngreso;
}
