#ifndef Consulta_h
#define Consulta_h
#include <iostream>
#include "..\..\datatypes\h\DtFecha.h"

class Consulta{
	private:
		DtFecha fechaConsulta;
		std::string motivo;
	public:
		Consulta(const DtFecha&, std::string);
		~Consulta();
		
		DtFecha getFechaConsulta();
		std::string getMotivo();

		void setFechaConsulta(const DtFecha&);
		void setMotivo(std::string motivo);
};
#endif
