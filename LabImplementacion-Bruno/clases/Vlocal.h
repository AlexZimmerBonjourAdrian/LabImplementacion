#include "Venta.cpp"
#include "../interfaces/IDictionary.cpp"
#include "../interfaces/ICollection.cpp"
#include "Mozo.cpp"
#ifndef VLOCAL_H
#define VLOCAL_H

using namespace std;

class Vlocal : public Venta{
	
	private:
		IDictionary * mesas;
		Mozo * mozo;
	
	public:
		Vlocal(int,ICollection *,IDictionary* mesas,Mozo*);
		void asignarMesas(ICollection * mesas);
		string getEmpleado() const = 0;
		~Vlocal();
		
};

#endif
