#include "DtComun.h"
#include<iostream>
#ifndef DTCOMUN_CPP
#define DTCOMUN_CPP

using namespace std;

DtComun::DtComun(int codigo, string descripcion, float precio, int cantidad, string tipo) : DtProducto(codigo,descripcion,precio,cantidad,tipo){
	
} 

DtComun::~DtComun(){
	
}

#endif
