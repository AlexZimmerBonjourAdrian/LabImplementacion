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
	public:
	    DtFecha(int anio, int mes, int dia);
	    int getAnio();
	    int getMes();
	    int getDia();
	   	bool operator >(const DtFecha f2)const{	 	
  		 	return((this->anio >f2.anio) || (this->mes > f2.mes)|| (this->dia >f2.dia)) ? true: false;
		}
	   	virtual ~DtFecha();
};

#endif
