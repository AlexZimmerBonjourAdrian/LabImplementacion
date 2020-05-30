#ifndef DtConsulta_h
#define DtConsulta_h
#include <iostream>
#include "..\..\datatypes\h\DtFecha.h"

class DtConsulta{
	private:
		DtFecha fechaConsulta;
		std::string motivo;
	public:
		DtConsulta(const DtFecha& , std::string);
		~DtConsulta();
		
		DtFecha getFecha();
		std::string getMotivo();
		
        // sobrecarga de operadores
        friend std::ostream& operator <<(std::ostream &o, const DtConsulta &c);
};
#endif
