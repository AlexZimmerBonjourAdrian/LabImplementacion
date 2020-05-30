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
		DtFecha();
		DtFecha(int, int, int);
		DtFecha(DtFecha &);
		~DtFecha();
		
		//gets y sets
		void setDia(int);
		void setMes(int);
		void setAnio(int);
		int getDia();
		int getMes();
		int getAnio();
		
		// sobrecarga de operadores
		friend bool operator <(const DtFecha &, const DtFecha &);
		friend std::ostream& operator <<(std::ostream &, const DtFecha &);
};




#endif
