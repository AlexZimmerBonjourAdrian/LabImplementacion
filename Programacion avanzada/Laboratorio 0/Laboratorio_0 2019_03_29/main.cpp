#include <iostream>
using namespace std;

// include de Clases
#include "Socio.h"
#include "Consulta.h"
#include "Mascota.h"
#include "Perro.h"
#include "Gato.h"
// include de DataTypes
#include "DtMascota.h"
#include "DtPerro.h"
#include "DtGato.h"
#include "DtConsulta.h"
#include "DtFecha.h"

void registrarSocio(string, string, const DtMascota&);
void agregarMascota(string , const DtMascota&);
void ingresarConsulta(string motivo, string ci);
DtConsulta** verConsultasAntesDeFecha(const DtFecha&, string, int&);
void eliminarSocio(string);




int main() {
	/*
	DtFecha *f1 = new DtFecha(31,12,1983);
	DtFecha *f2 = new DtFecha(12,3,1996);
	
	cout << *f1 << " < " << *f2 << " = ";
	cout << (*f1 < *f2) << endl;
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


