#ifndef Persona_H
#define Persona_H
#include <iostream>

#include "Auto.h"
#include "DtAuto.h"
#include "DtFecha.h"

#define MAX_AUTOS 10

class Persona{
	private:
		std::string ci;
		std::string nombre;
		DtFecha fechaNac;
		Auto *misAutos[MAX_AUTOS];
		int cantAutos;
	public:
		Persona(std::string ci, std::string nombre, DtFecha &f, DtAuto &a){
			this->ci = ci;
			this->nombre = nombre;
			this->fechaNac = DtFecha(f);
			this->cantAutos = 0;
			this->agregarAuto(a);
		}
		void agregarAuto(DtAuto &a){
			this->misAutos[cantAutos] = new Auto(a);
			this->cantAutos++;
		}
		~Persona(){
			
		}
		std::string getCi(){
			return this->ci;
		}
		std::string getNombre(){
			return this->nombre;
		}
		DtFecha getFechaNac(){
			return this->fechaNac;
		}
		DtAuto** getAutos(int &cantAutos){
			DtAuto **autos = new DtAuto*[this->cantAutos];	// puntero a array de punteros a DtAuto
			Auto *a;	// no es necesario, pero acorta la linea donde hace new DtAuto(...)
			for (cantAutos = 0; cantAutos < this->cantAutos; cantAutos++){
				a = misAutos[cantAutos];	// apunto al auto al cual quiero crearle un DtAuto con sus datos para devolver
				autos[cantAutos] = new DtAuto(a->getMatricula(), a->getAnio(), a->getPatenteAlDia());
			}
			return autos;
		}
		
};



#endif
