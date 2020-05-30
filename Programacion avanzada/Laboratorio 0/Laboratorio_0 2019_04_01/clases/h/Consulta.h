#ifndef Consulta_h
#define Consulta_h
#include <iostream>
#include "..\..\datatypes\h\DtFecha.h"

class Consulta{
	private:
		DtFecha fechaConsulta;
		std::string motivo;
	public:
		Consulta();
		Consulta(&DtConsulta);
		~Consulta();
		
		DtFecha getFechaConsulta();
		std::string getMotivo();
		
		void setFechaConsulta(DtFecha fechaConsulta);
		void setMotivo(std::string motivo);
};
#endif
