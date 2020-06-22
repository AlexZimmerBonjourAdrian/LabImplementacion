#include "DtMozo.h"
#ifndef DTMOZO_CPP
#define DTMOZO_CPP
#include<iostream>
#include "DtMesa.cpp"
using namespace std;

DtMozo::DtMozo(int codigo, string nombre,ICollection * mesas) : DtEmpleado(codigo,nombre){
	this->mesas=mesas;
}

ICollection * DtMozo::getMesas(){
	return this->mesas;
}

DtMozo::~DtMozo(){
	IIterator * it = this->mesas->getIterator();
	while(it->hasCurrent()){
		DtMesa * dp = (DtMesa*)it->getCurrent();
		it->next();
		this->mesas->remove(dp);
		delete dp;
	}
	delete it;
	delete this->mesas;
}
#endif
