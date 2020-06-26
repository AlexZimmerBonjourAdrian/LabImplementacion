
#include "Venta.cpp"
#include "Mozo.cpp"
#include "../interfaces/IDictionary.cpp"
#include "../interfaces/ICollection.cpp"

#include "../Datatypes/DtMozo.cpp"
#ifndef VLOCAL_H
#define VLOCAL_H



using namespace std;

class Vlocal : public Venta{
	
	private:
		Mozo * mozo;
	
	public:
		Vlocal(ICollection *,DtFecha *,string,Mozo*);
		DtEmpleado * getEmpleado() const;
		Mozo * getMozo();
	
		~Vlocal();
		
};

#endif
