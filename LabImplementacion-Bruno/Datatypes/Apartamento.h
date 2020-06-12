#include<iostream>
#include "DtDireccion.cpp"
#ifndef APARTAMENTO_H
#define APARTAMENTO_H

using namespace std;

class Apartamento : public DtDireccion{
	
	private:
		string nombre_ed;
		int nro;
		
	public:
		Apartamento(string,int,string,int);
		int getNro();
		~Apartamento();
		
};



#endif
