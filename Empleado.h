#include <iostream>
#include <stdio.h>
#include "./interfaces/ICollectible.h"

class Empleado : public ICollectible {
	
	private:
		string nombre;
		int nroEmp;
	public:
		Empleado(string,int);
		string getNombre();
		int getnroEmp();
		void setNombre(string);
		void setnroEmp(int); 
};
