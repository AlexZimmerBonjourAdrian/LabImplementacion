#ifndef Socio_h
#define Socio_h
#include <iostream>
#include "Mascota.h"
#include "Consulta.h"
#include "..\..\datatypes\h\DtFecha.h"

#define MAX_MASCOTAS 10
#define MAX_CONSULTAS 20

class Socio{
	private:
		std::string ci;
		std::string nombre;
		DtFecha FechaIngreso;
		
		Mascota *MisMascotas[MAX_MASCOTAS];
		Consulta *MisConsultas[MAX_CONSULTAS];
	public:
		Socio(DtSocio &, DtMascota &);
		~Socio();
		void setCi(std::string ci);
		void setNombre(std::string nombre);
		void setFechaingreso(DtFecha FechaIngreso);
		std::string getCi();
		std::string getNombre();
		DtFecha getFechaIngreso();
};

#endif
