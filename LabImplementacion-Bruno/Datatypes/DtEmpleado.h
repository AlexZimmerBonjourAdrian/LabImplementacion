#include "../interfaces/ICollection.cpp"
#include<iostream>
#ifndef DTEMPLEADO_H
#define DTEMPLEADO_H

using namespace std;

class DtEmpleado : public ICollectible{
	private:
		int codigo;
		string nombre;
		
	public:
		DtEmpleado(int,string);
		int getId();
		string getNombre();
		virtual ~DtEmpleado();
		
};

#endif
