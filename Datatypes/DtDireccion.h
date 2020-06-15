#include<iostream>
#include "../interfaces/ICollectible.cpp"
#ifndef DTDIRECCION_H
#define DTDIRECCION_H

using namespace std;

class DtDireccion : public ICollectible{
	private:
		string calle;
		int nro;
		
	public:
		DtDireccion(string,int);
		string getCalle();
		int getNro();
		virtual ~DtDireccion();
};
#endif
