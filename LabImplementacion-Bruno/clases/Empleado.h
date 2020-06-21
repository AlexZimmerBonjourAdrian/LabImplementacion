#include "../interfaces/ICollectible.cpp"
#include<iostream>
#include "../Datatypes/DtEmpleado.cpp"
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
		int getId() const;
		string getNombre() const;
		virtual DtEmpleado * getDatos() const = 0;
		~Empleado();
		
}; 
#endif

