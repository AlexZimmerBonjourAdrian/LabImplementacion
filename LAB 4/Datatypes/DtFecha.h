#include<iostream>
#include "../interfaces/ICollectible.cpp"
#ifndef DTFECHA_H
#define DTFECHA_H

using namespace std;

class DtFecha : public ICollectible {
	private:
	    int anio;
	    int mes;
	    int dia;
	    int hora;
	    int minutos;
	public:
	    DtFecha(int anio, int mes, int dia,int,int);
	    int getAnio();
	    int getMes();
	    int getDia();
	    int getHora();
	    int getMinutos();
	   	virtual ~DtFecha();
};

#endif
