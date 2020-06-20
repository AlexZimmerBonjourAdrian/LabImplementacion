#include<iostream>
#include "DtMesa.h"

#ifndef DTMESA_CPP
#define DTMESA_CPP
using namespace std;

DtMesa::DtMesa(int id){
	this->id=id;
}

int DtMesa::getId(){
	return this->id;
}

DtMesa::~DtMesa(){
	
}
#endif

