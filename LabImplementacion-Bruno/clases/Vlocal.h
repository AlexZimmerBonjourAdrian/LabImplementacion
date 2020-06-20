
#include "Venta.cpp"
#include "../interfaces/IDictionary.cpp"
#include "../interfaces/ICollection.cpp"
#include "Mozo.cpp"
#include "../Datatypes/DtMozo.cpp"
#ifndef VLOCAL_H
#define VLOCAL_H



using namespace std;

class Vlocal : public Venta{
	
	private:
		Mozo * mozo;
	
	public:
		Vlocal(ICollection *,DtFecha *,Mozo*);
		DtEmpleado * getEmpleado() const;
		Mozo * getMozo();
	
		~Vlocal();
		
};

#endif
