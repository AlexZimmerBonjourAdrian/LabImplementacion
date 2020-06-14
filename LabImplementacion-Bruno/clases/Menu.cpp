#include "../clases/Menu.h"
#include "Componente.cpp"
#include<iostream>
#include "../iterators/IIterator.cpp"
#include "../colecciones/List.cpp"
#ifndef MENU_CPP
#define MENU_CPP

Menu::Menu(int codigo,string descripcion, float precio) : Producto(codigo, descripcion,precio){
	this->componentes = new List();
}

void Menu::agregarProd(Comun *p, int cant){
	Componente * c = new Componente(cant,p);
	this->componentes->add(c);
}

void Menu::sacardeLista(Comun *p){
	IIterator * it = this->componentes->getIterator();
	while(it->hasCurrent()){
		Componente * c = (Componente *) it->getCurrent();
		if(c->coincide(p)){
			this->componentes->remove(c);
			return;
		}
		it->next();
	}
}

bool Menu::vacio(){
	IIterator * it = this->componentes->getIterator();
	return it->hasCurrent();
}


Menu::~Menu(){
	
}





#endif
