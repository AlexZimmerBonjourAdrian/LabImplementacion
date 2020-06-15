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
	Mesa * m1 = new Mesa(1,new ListDictionary());
//	ListDictionary * dic = new ListDictionary();
	ICollection * dic = new List();
//IKey * k1 = new IntKey(m1->getid());
	dic->add(m1);
	IIterator * it = dic->getIterator();
	while(it->hasCurrent()){
//		IKey * k = new IntKey(1);
		it->next();
		dic->remove(m1);
		cout << "HOLA" << endl;
//	system("PAUSE");
	}
}
