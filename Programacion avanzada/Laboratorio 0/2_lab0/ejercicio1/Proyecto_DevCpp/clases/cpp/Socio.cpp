#include "..\h\Socio.h"
using namespace std;

Socio::Socio(string ci, string nombre, DtFecha FechaIngreso, DtMascota &MiMascota){
	cantMascotas = 0;
	cantConsultas = 0;
	
	this->ci=ci;
	this->nombre=nombre;
	this->FechaIngreso=FechaIngreso;
	
	DtPerro *EsPerro = dynamic_cast<DtPerro*>(&MiMascota);
	if(EsPerro){
		this->MisMascotas[0]= new Perro(
			MiMascota.getNombre(),
			MiMascota.getGenero(),
			MiMascota.getPeso(),
			EsPerro->getRaza(),
			EsPerro->getVacunaCachorro()
		);
	}
	else{
		DtGato *EsGato = dynamic_cast<DtGato*>(&MiMascota);
		if(EsGato){
			this->MisMascotas[0]= new Gato(
				MiMascota.getNombre(),
				MiMascota.getGenero(),
				MiMascota.getPeso(),
				EsGato->getPelo()
			);
		}else {
			// Ni idea no es perro no es gato debe ser un alien :o
		}
	}
	this->cantMascotas++;
}


Socio::~Socio(){
	// Destructor
	// libera memoria de mascotas
	for(int i=0; i<this->cantMascotas; i++){
		delete MisMascotas[i];
	}
	// libera memoria de consultas
	for(int i=0; i<this->cantConsultas; i++){
		delete MisConsultas[i];
	}
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


// operaciones con mascotas
bool Socio::mascotaExiste(string nombre){
	// devuelve true si ya existe una mascota con ese nombre
	for(int i = 0; i < this->cantMascotas ; i++){
		if(nombre == MisMascotas[i]->getNombre()){
			return true;
		}
	}
	return false;
	
}


bool Socio::puedeAgregarMascota(){
	// devuelve true si hay lugar en el array para agregar mas mascotas
	if(this->cantMascotas < MAX_MASCOTAS){
		return true;
	}
	return false;
}


bool Socio::puedeEliminarMascota(){
	// devuelve true si hay lugar en el array para agregar mas mascotas
	return !(this->cantMascotas <= 1);
}


void Socio::agregarMascota(DtMascota& NuevaMas){
	// agrega mascota al array de mascotas
	if(this->mascotaExiste(NuevaMas.getNombre())){
		return;
	}
	
	DtPerro *EsPerro = dynamic_cast<DtPerro*>(&NuevaMas);
	
	if(EsPerro){
		this->MisMascotas[this->cantMascotas]= new Perro(
			NuevaMas.getNombre(),
			NuevaMas.getGenero(),
			NuevaMas.getPeso(),
			EsPerro->getRaza(),
			EsPerro->getVacunaCachorro()
		);
	}
	else{
		DtGato *EsGato = dynamic_cast<DtGato*>(&NuevaMas);
		if(EsGato){
			this->MisMascotas[this->cantMascotas]= new Gato(
				NuevaMas.getNombre(),
				NuevaMas.getGenero(),
				NuevaMas.getPeso(),
				EsGato->getPelo()
			);
		}
	}
	this->cantMascotas++;
}


void Socio::eliminarMascota(string nombre){
	// busca el nombre de la mascota y la borra del array (reorganizandolo para que no queden huecos)
	if (cantMascotas == 1)	return;	// no se puede dejar a un socio sin mascotas

	for (int i = 0; i < cantMascotas; i++){
		if (MisMascotas[i]->getNombre() == nombre){
			delete MisMascotas[i];
			MisMascotas[i] = MisMascotas[cantMascotas-1];
			cantMascotas--;
		}
	}
}


DtMascota** Socio::obtenerMascotas(int& cantElem){
	// devuelve un array de punteros DtMascota con los datos de las mascotas. cantMascotas se modificara segun la cantidad de elementos devueltos
	DtMascota** mascotas = new DtMascota*[cantMascotas];
	cantElem = cantMascotas;
    //Busca todas las mascotas en el array MisMascotas y
    //crea un array de DtMascotas con todas las mascotas
	for(int i = 0; i< cantMascotas; i++){
        Perro *EsPerro = dynamic_cast<Perro*>(MisMascotas[i]);
        if(EsPerro){
            mascotas[i]= new DtPerro(
                MisMascotas[i]->getNombre(),
                MisMascotas[i]->getGenero(),
                MisMascotas[i]->getPeso(),
                EsPerro->getRaza(),
                EsPerro->getVacunaCachorro(),
                MisMascotas[i]->obtenerRacionDiaria()
            );
        }
        else{
            Gato *EsGato = dynamic_cast<Gato*>(MisMascotas[i]);
            if(EsGato){
                mascotas[i]= new DtGato(
                    MisMascotas[i]->getNombre(),
                    MisMascotas[i]->getGenero(),
                    MisMascotas[i]->getPeso(),
                    EsGato->getPelo(),
             	   MisMascotas[i]->obtenerRacionDiaria()
				);
            }
        }
	}
	return mascotas;
	
}

// operaciones con consultas
bool Socio::puedeAgregarConsulta(){
	// devuelve true si hay lugar en el array para agregar mas consultas
	if (cantConsultas < MAX_CONSULTAS)
		return true;
	else 
		return false;
}


void Socio::agregarConsulta(DtConsulta& consulta){
	// agrega una consulta al array de consultas
	if(puedeAgregarConsulta() == true){
		this->MisConsultas[this->cantConsultas] = new Consulta(
			consulta.getFecha(),
			consulta.getMotivo()
		);
		this->cantConsultas++;
	}
}


DtConsulta** Socio::obtenerConsultas(int& cantElem){
	// devuelve un array de punteros DtConsulta con las consultas. cantMascotas se modificara segun la cantidad de elementos devueltos
	DtConsulta** ret = new DtConsulta*[this->cantConsultas];
	for (cantElem = 0; cantElem < this->cantConsultas; cantElem++){
		ret[cantElem] = new DtConsulta(
			MisConsultas[cantElem]->getFechaConsulta(),
			MisConsultas[cantElem]->getMotivo()
		);
	}
	return ret;
}

















