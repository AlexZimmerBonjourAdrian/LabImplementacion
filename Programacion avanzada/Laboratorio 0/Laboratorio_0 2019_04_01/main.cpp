#include <iostream>
using namespace std;

// include de Clases
#include "clases\h\Socio.h"
#include "clases\h\Consulta.h"
#include "clases\h\Mascota.h"
#include "clases\h\Perro.h"
#include "clases\h\Gato.h"
// include de DataTypes
#include "datatypes\h\DtConsulta.h"
#include "datatypes\h\DtFecha.h"
#include "datatypes\h\DtMascota.h"
#include "datatypes\h\DtPerro.h"
#include "datatypes\h\DtGato.h"

void registrarSocio(string, string, const DtMascota &);
void agregarMascota(string , const DtMascota&);
void ingresarConsulta(string motivo, string ci);
DtConsulta** verConsultasAntesDeFecha(const DtFecha&, string, int&);
void eliminarSocio(string);


int main(){
	
	
	
	/*
    //Test de la clase perro;
    Perro p1 = Perro("Paco", Macho,25.0,Labrador,true);
    cout << "Datos Perro 1 \nNombre:"<< p1.getNombre()<< endl
         << "Raza: " << p1.getRaza() << endl
         << "Peso: " << p1.getPeso() << endl
         << "Genero: " << p1.getGenero() << endl
         << "Vacunas: " << p1.getVacunaCachorro() <<endl<<endl;
    //Test de los metodos seter para perro
    p1.setRaza(Pekines);
    p1.setPeso(30);
    p1.setGenero(Hembra);
    p1.setNombre("Cuqui");
    p1.setVacunaCachorro(false);
    cout << "Datos Perro 1 \nNombre:"<< p1.getNombre()<< endl
         << "Raza: " << p1.getRaza() << endl
         << "Peso: " << p1.getPeso() << endl
         << "Genero: " << p1.getGenero() << endl
         << "Vacunas: " << p1.getVacunaCachorro() <<endl<<endl;

    //Test de la clase gato;
    Gato g1 = Gato("Garfiel", Macho,5.0,Mediano);
    cout << "Datos Gato 1 \nNombre:"<< g1.getNombre()<< endl
         << "Pelo: " << g1.getPelo() << endl
         << "Peso: " << g1.getPeso() << endl
         << "Genero: " << g1.getGenero() << endl << endl;

    //Test de los metodos seter para gato
    g1.setPeso(12);
    g1.setGenero(Hembra);
    g1.setNombre("Monitor");
    g1.setPelo(Largo);
    cout << "Datos Gato 1 \nNombre:"<< g1.getNombre()<< endl
         << "Pelo: " << g1.getPelo() << endl
         << "Peso: " << g1.getPeso() << endl
         << "Genero: " << g1.getGenero() << endl << endl;
	*/
    return 0;
}



void registrarSocio(string ci, string nombre, const DtMascota& dtMascota){
	/* Registra un socio con su mascota. El valor el atributo racionDiaria se debe setear en 0
	*/
}

void agregarMascota(string ci, const DtMascota& dtMascota){
	/* Agrega una nueva mascota a un socio ya registrado. Si no existe un socio registrado con esa cedula, se levanta una excepcion std::invalid_argument
	*/
}

void ingresarConsulta(string motivo, string ci){
	/* Crea una consulta con un motivo para un socio. Si no existe un socio registrado con esa cedula, se levanta una excepcion std::invalid_argument
	*/
}

DtConsulta** verConsultasAntesDeFecha(const DtFecha& Fecha, string ciSocio, int& cantConsultas){
	/* Devuelve las consultas antes de cierta fecha. El largo del arreglo esta dadopor el parametro cantConsultas
	*/
}

void eliminarSocio(string ci){
	/* Elimina al socio, sus consultas y sus mascotas. Si no existe un socio registrado con esa cedula, se levanta una excepcion std::invalid_argument
	*/
}

DtMascota** obtenerMascotas(string ci, int& cantMascotas){
	/*Devuelve un arreglo con las mascotas del socio. El largo del arreglo esta dado por el parametro cantMascotas. Si no existe un socio registrado con esa cedula, se levanta una excepcion std::invalid_argument
	*/
}


