#include "Sistema.cpp"
#include<iostream>
#include<stdio.h>
#include "./clases/Producto.cpp"
#include "./clases/Repartidor.cpp"
#include "./clases/Vdomicilio.cpp"
#include "./Datatypes/DtDireccion.cpp"
#include "./clases/Cliente.cpp"
#include <windows.h>
#include <typeinfo>
#include<ctime>
using namespace std;

main(){
	Empleado * m = new Mozo("jorhe",new ListDictionary());
	Repartidor * r = dynamic_cast<Repartidor*>(m);
	if(r==NULL){
		cout << "FUNCIONA" << endl;
	}
	else{
		cout << r->getMedio() << endl;
		cout << "NO FUNCIONA" << endl;
	}
	system("PAUSE");
	
}
