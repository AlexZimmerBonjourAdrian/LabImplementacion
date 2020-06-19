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
using namespace std;

main(){
	
	Empleado * m1 = new Mozo("Gustavo", new ListDictionary());
	Repartidor * r1 = dynamic_cast<Repartidor*>(m1);
	if(r1==NULL){
		cout << "FUNCIONA" << endl;
	}
	system("pause");
}
