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
	
	DtFecha  * f1 = new DtFecha(2017,04,31);
	DtFecha f2(2018,12,11);
	if(f1>&f2){
		cout << "LA FECHA ES MAYOR" << endl;
	}
	else{
		cout << "LA FECHA NO ES MAYOR" << endl;
	}
	system("pause");
}
