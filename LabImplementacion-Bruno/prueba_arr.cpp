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
	Sistema * s = Sistema::getInstance();
	s->cargarDatos();
	cout << "### Productos ###" << endl << endl;
	ICollection * prod = s->mostrarProductos();
	ICollection * prod2 = prod;
	if(prod==NULL){
		cout << endl << "### NO HAY PRODUCTOS EN EL SISTEMA ###" << endl;
		Sleep(2000);
		exit(1);
	}
	DtProducto * dpcopia = NULL;
	IIterator * it_p = prod->getIterator();
	while(it_p->hasCurrent()){
		DtProducto * dp = (DtProducto *) it_p->getCurrent();
		dpcopia = dp;
		cout << "\t ..Codigo: " << dp->getCodigo() << endl;
		cout << "\t ..Nombre del Producto: " << dp->getDescripcion() << endl;
		cout << "\t ..Precio: " << dp->getPrecio() << endl;
		cout << endl << endl;	
		it_p->next();
	}
	system("PAUSE");
	
	IIterator * it = prod->getIterator();
	while(it->hasCurrent()){
		DtProducto * dp = (DtProducto*)it->getCurrent();
		it->next();
		delete dp;
	}
	delete prod;
	system("PAUSE");
	cout << "\t ..Codigo: " << dpcopia->getCodigo() << endl;
	cout << "\t ..Nombre del Producto: " << dpcopia->getDescripcion() << endl;
	cout << "\t ..Precio: " << dpcopia->getPrecio() << endl;
	
	
	system("PAUSE");
	
}
