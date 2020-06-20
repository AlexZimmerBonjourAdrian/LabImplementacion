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
	int dia, mes, ano;  
	time_t tiempo = time (NULL);  
	struct tm *fecha = localtime (&tiempo); 
	cout << fecha->tm_year+1900 << "-" << fecha->tm_mon << "-" <<fecha->tm_mday<< endl;
	system("PAUSE");
	
}
