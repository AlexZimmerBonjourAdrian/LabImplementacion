#ifndef DtConsulta_h
#define DtConsulta_h
#include "..\..\datatypes\h\DtFecha.h"

class DtConsulta{
	private:
		DtFecha fechaConsulta;
		std::string motivo;
	public:
		DtConsulta(const DtFecha& , std::string);
		~DtConsulta();
		
		DtFecha getFechaConsulta();
		std::string getMotivo();
		
};
#endif
