#include "../interfaces/ICollectible.cpp"
#include<iostream>
#ifndef EMPLEADO_H
#define EMPLEADO_H

using namespace std;
 
class Empleado : public ICollectible{

	private:
		int id;
		string nombre;
	
	public:
		Empleado(int,string);
		int getId();
		string getNombre();
		~Empleado();
		
}; 
#endif

