#ifndef DtFecha_H
#define DtFecha_H
#include <iostream>

class DtFecha{
	private:
		int dia;
		int mes;
		int anio;
	public:
		//Constructores
		DtFecha(){
			this->dia = 1;
			this->mes = 1;
			this->anio = 2000;
		}
		DtFecha(int dia, int mes, int anio){
			this->dia = dia;
			this->mes = mes;
			this->anio = anio;
		}
		DtFecha(const DtFecha &fecha){
			this->dia = fecha.dia;
			this->mes = fecha.mes;
			this->anio = fecha.anio;
		}
		~DtFecha(){
			
		}
		
		// gets y sets
		void setDia(int dia){
			this->dia = dia;
		}
		void setMes(int mes){
			this->mes = mes;
		}
		void setAnio(int anio){
			this->anio = anio;
		}
		int getDia(){
			return this->dia;
		}
		int getMes(){
			return this->mes;
		}
		int getAnio(){
			return this->anio;
		}
		
		
		friend bool operator <(const DtFecha &f1, const DtFecha &f2){
			if (f1.anio < f2.anio)	return true;
			if (f1.anio > f2.anio)	return false;
			// si llega hasta aca, son el mismo anio y hay que verificar el mes
			if (f1.mes < f2.mes)	return true;
			if (f1.mes > f2.mes)	return false;
			// si llega hasta aca, son el mismo anio y el mismo mes, hay que verificar el dia
			if (f1.dia < f2.dia)	return true;
			if (f1.dia > f2.dia)	return false;
			// si llega hasta aca, es la misma fecha, y retorna false
			return false;
		}
		friend std::ostream& operator <<(std::ostream &salida, const DtFecha &f){
			salida << f.dia << "/" << f.mes << "/" << f.anio;
			return salida;
		}
};




#endif
