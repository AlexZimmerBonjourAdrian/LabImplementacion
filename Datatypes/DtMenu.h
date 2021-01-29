#include<iostream>
#include "DtProducto.cpp"
#include "../interfaces/ICollection.cpp"
#ifndef DTMENU_H
#define DTMENU_H

using namespace std;

class DtMenu : public DtProducto{
	private:
	
		ICollection * componentes;
	public:
		DtMenu(int,string,float,int,string,ICollection *);
		ICollection * getComponentes();
		~DtMenu();
};

#endif
