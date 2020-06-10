#include "Venta.cpp"
#include "../interfaces/IDictionary.cpp"
#include "../interfaces/ICollection.cpp"
#ifndef VLOCAL_H
#define VLOCAL_H

class Vlocal : public Venta{
	
	private:
		IDictionary * mesas;
	
	public:
		Vlocal(int,ICollection *,IDictionary* mesas);
		void asignarMesas(ICollection * mesas);
		~Vlocal();
		
};

#endif
