#include<iostream>
#include "DtDireccion.cpp"
#ifndef APARTAMENTO_H
#define APARTAMENTO_H

using namespace std;

class DtApartamento : public DtDireccion{
	
	private:
		string nombre_ed;
		int nro;
		
	public:
		DtApartamento(string,int,string,int);
		string getDpto();
		int getPiso();
		~DtApartamento();
		
};



#endif
