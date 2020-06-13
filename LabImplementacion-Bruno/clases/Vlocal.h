
#include "Venta.cpp"
#include "../interfaces/IDictionary.cpp"
#include "../interfaces/ICollection.cpp"
#include "Mozo.cpp"

#ifndef VLOCAL_H
#define VLOCAL_H



using namespace std;

class Vlocal : public Venta{
	
	private:
		Mozo * mozo;
	
	public:
		Vlocal(ICollection *,DtFecha *,Mozo*);
		string getEmpleado() const;
		
		~Vlocal();
		
};

#endif
