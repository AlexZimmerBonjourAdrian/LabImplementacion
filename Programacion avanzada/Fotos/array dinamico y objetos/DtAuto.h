#ifndef DtAuto_H
#define DtAuto_H
#include <iostream>

class DtAuto{
	private:
		std::string matricula;
		int anio;
		bool patenteAlDia;
	public:
		//Constructores
		DtAuto(){
			this->matricula = "sin asignar";
			this->anio = -1;
			this->patenteAlDia = false;
		}
		DtAuto(std::string matricula, int anio, bool patenteAlDia){
			this->matricula = matricula;
			this->anio = anio;
			this->patenteAlDia = patenteAlDia;
		}
		~DtAuto(){
			
		}
		
		//gets y sets
		std::string getMatricula(){
			return this->matricula;
		}
		int getAnio(){
			return this->anio;
		}
		bool getPatenteAlDia(){
			return this->patenteAlDia;
		}
		
		// sobrecarga de operadores
		friend std::ostream& operator <<(std::ostream &salida, const DtAuto &a){
			salida << "Matricula: " << a.matricula << std::endl;
			salida << "Anio: " << a.anio << std::endl;
			salida << "Patente al dia: " << a.patenteAlDia << std::endl;
			return salida;
		}
};



#endif
