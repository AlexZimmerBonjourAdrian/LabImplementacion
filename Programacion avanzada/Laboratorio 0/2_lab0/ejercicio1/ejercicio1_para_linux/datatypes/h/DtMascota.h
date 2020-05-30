#ifndef DtMascota_h
#define DtMascota_h
#include <iostream>
#include "../../enums/Enums.h"

class DtMascota{
	protected:
		std::string nombre;
		Genero genero;
		float peso;
		float racionDiaria;
	public:
		DtMascota(std::string _nombre, Genero _genero, float _peso);
		DtMascota(std::string _nombre, Genero _genero, float _peso, float _racionDiaria);
		virtual ~DtMascota();
		//---Getters ------------
		std::string getNombre();
		Genero getGenero();
		float getPeso();
};

#endif
