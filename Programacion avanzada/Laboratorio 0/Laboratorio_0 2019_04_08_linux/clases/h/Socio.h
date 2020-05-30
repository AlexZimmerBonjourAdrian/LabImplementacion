#ifndef Socio_h
#define Socio_h
#include <iostream>
#include "Mascota.h"
#include "Gato.h"
#include "Perro.h"
#include "Consulta.h"
#include "../../datatypes/h/DtConsulta.h"
#include "../../datatypes/h/DtMascota.h"
#include "../../datatypes/h/DtGato.h"
#include "../../datatypes/h/DtPerro.h"
#include "../../datatypes/h/DtFecha.h"

#define MAX_MASCOTAS 10
#define MAX_CONSULTAS 20

class Socio{
	private:
		std::string ci;
		std::string nombre;
		DtFecha FechaIngreso;
		
		Mascota *MisMascotas[MAX_MASCOTAS];
		int cantMascotas;
		Consulta *MisConsultas[MAX_CONSULTAS];
		int cantConsultas;
	public:
		Socio(std::string, std::string, DtFecha, DtMascota&);
		~Socio();
		// sets
		void setCi(std::string);
		void setNombre(std::string);
		void setFechaIngreso(DtFecha);
		/// gets
		std::string getCi();
		std::string getNombre();
		DtFecha getFechaIngreso();
		// operaciones con mascotas
		bool mascotaExiste(std::string);
		bool puedeAgregarMascota();
		bool puedeEliminarMascota();
		void agregarMascota(DtMascota &);
		void eliminarMascota(std::string);
		DtMascota** obtenerMascotas(int&);
		// operaciones con consultas
		bool puedeAgregarConsulta();
		void agregarConsulta(DtConsulta &);
		DtConsulta** obtenerConsultas(int& );
};

#endif
