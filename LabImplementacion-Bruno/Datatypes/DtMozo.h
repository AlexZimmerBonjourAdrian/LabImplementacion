#include "DtEmpleado.cpp"
#include<iostream>
#ifndef DTMOZO_H
#define DTMOZO_H

using namespace std;

class DtMozo : public DtEmpleado{
	
	private:
		ICollection * mesas;
	
	public:
		DtMozo(int,string,ICollection *);
		ICollection * getMesas();
		~DtMozo();
		
	
};
#endif
