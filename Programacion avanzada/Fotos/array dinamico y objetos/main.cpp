#include <iostream>
#include "Persona.h"
#include "Auto.h"
#include "DtAuto.h"
#include "DtFecha.h"
using namespace std;

void inicializar();
void agregarPersona(string, string, DtFecha &, DtAuto &);
void mostrarTodo();
void aumentarCapacidadPersonas(int);

int maxPersonas = 0;
Persona** personas = new Persona*[0];	// personas es un puntero que apunta a un array[10] de punteros de tipo persona
int cantPersonas = 0;

int main() {
	inicializar();
	mostrarTodo();
	
	system("PAUSE");
	return 0;
}


void inicializar(){
	int cantIngresos = 4;
	string cedulas[] = {"11111111", "22222222", "33333333", "44444444"};
	string nombres[] = {"facundo", "juan", "julio", "lucas"};
	DtFecha fechas[] = {DtFecha(1,2,1998), 
						DtFecha(3,4,1999), 
						DtFecha(5,6,2000), 
						DtFecha(7,8,2001)};
	DtAuto autos[] = {	DtAuto("wtf-1111", 1978, false), 
						DtAuto("win-1111", 1979, true), 
						DtAuto("lin-1111", 1980, false), 
						DtAuto("mac-1111", 1981, true)};
	
	for (int i = 0; i < cantIngresos; i++){
		agregarPersona(cedulas[i], nombres[i], fechas[i], autos[i]);
	}
}


void agregarPersona(string ci, string nombre, DtFecha &f, DtAuto &a){
	if (cantPersonas == maxPersonas){	// si no hay lugar en el array para agregar uno nuevo
		aumentarCapacidadPersonas(1);	 // aumenta la capacidad del array
	}
	personas[cantPersonas] = new Persona(ci, nombre, f, a);;
	cantPersonas++;
}


void mostrarTodo(){
	DtAuto **autos;	// para obtener los autos
	int cantAutos;
	
	// recorre el array de personas
	for (int i = 0; i < cantPersonas; i++){
		cout << "###################################" << endl;
		cout << "CI: " << personas[i]->getCi() << endl;
		cout << "Nombre: " << personas[i]->getNombre() << endl;
		cout << "Fecha de nacimiento: " << personas[i]->getFechaNac() << endl;
		
		// obtiene un array con los datos de los aytos
		autos = personas[i]->getAutos(cantAutos);
		// lo recorre mostrando
		for (int j = 0; j < cantAutos; j++){
			cout << "---- Auto " << j+1 << " ----" << endl;
			cout << *autos[j] << endl;
			delete autos[j];		}
		delete []autos;	// libera el espacio que ocupan los punteros en el array y el DtAuto al que apuntan, osea, borra todo
	}
}


void aumentarCapacidadPersonas(int cant){
	Persona **nuevoArr = new Persona*[maxPersonas + cant];	// crea un array de punteros con mas capacidad que el anterior
	for (int i = 0; i < cantPersonas; i++){
		// copia del array viejo al nuevo
		nuevoArr[i] = personas[i];
	}
	
	/* Aca tengo la duda, se deberia eliminar el array de punteros viejos (pero sin eliminar los objetos)
	creo que si se pone delete[]*persona borra los objetos
	pero no se como deberia ser realmente
	*/
	delete personas;
	personas = nuevoArr;	// actualiza el puntero al nuevo array
	maxPersonas += cant;	// incrementa el tope
}









