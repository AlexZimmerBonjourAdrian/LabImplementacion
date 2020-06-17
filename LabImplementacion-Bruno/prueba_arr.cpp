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
	
	Menu * m = new Menu(1,"Papas",120);
	cout << m->getTipo() << endl;
	system("PAUSE");
	m->setTipo("Comun");
	cout << m->getTipo() << endl;
	system("pause");
}
