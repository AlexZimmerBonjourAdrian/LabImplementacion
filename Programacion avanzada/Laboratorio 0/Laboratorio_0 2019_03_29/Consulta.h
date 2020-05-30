#ifndef Consulta_H
#define Consulta_H
#include <iostream>

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
}
#endif
