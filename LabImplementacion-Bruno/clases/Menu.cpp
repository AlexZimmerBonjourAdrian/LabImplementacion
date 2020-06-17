#include "../clases/Menu.h"
#include "Componente.cpp"
#include<iostream>
#include "../iterators/IIterator.cpp"
#include "../colecciones/List.cpp"
#include "../Datatypes/DtMenu.cpp"
#ifndef MENU_CPP
#define MENU_CPP

Menu::Menu(int codigo,string descripcion, float precio) : Producto(codigo, descripcion,precio){
	this->componentes = new List();
	this->setTipo("Menu");
}

void Menu::agregarProd(Comun *p, int cant){
	Componente * c = new Componente(cant,p);
	this->componentes->add(c);
}

DtProducto * Menu::getDatos() const{
	IIterator * it = this->componentes->getIterator();
	ICollection * dtcomp = new List;
	while(it->hasCurrent()){
		Componente * c = (Componente *)it->getCurrent();
		Producto * p = c->getProducto();
		DtProducto * dp = p->getDatos();
		dp->setCantidad(c->getCantidad());
		dtcomp->add(dp);
		it->next();
	}
	return  new DtMenu(this->getCodigo(),this->getDescripcion(), this->getPrecio(),0,this->getTipo(),dtcomp);

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
