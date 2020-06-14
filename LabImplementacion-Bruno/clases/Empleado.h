#include "../interfaces/ICollectible.cpp"
#include<iostream>
#ifndef EMPLEADO_H
#define EMPLEADO_H

using namespace std;
 
class Empleado : public ICollectible{

	private:
		int id;
		string nombre;
		static int maximo;
	
	public:
		Empleado(string);
		int getId();
		string getNombre();
		~Empleado();
		
}; 
#endif

