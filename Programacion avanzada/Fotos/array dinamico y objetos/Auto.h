#ifndef Auto_H
#define Auto_H
#include <iostream>
#include "DtAuto.h"

class Auto{
	private:
		std::string matricula;
		int anio;
		bool patenteAlDia;
	public:
		//Constructores
		Auto(DtAuto &nuevoAuto){
			this->matricula = nuevoAuto.getMatricula();
			this->anio = nuevoAuto.getAnio();
			this->patenteAlDia = nuevoAuto.getPatenteAlDia();
		}
		~Auto(){
			
		}
		std::string getMatricula(){
			return  this->matricula;
		}
		int getAnio(){
			return this->anio;
		}
		bool getPatenteAlDia(){
			return this->patenteAlDia;
		}
};




#endif
