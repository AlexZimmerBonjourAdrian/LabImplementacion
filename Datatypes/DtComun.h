#include "DtProducto.cpp"
#include<iostream>
#ifndef DTCOMUN_H
#define DTCOMUN_H

using namespace std;

class DtComun : public DtProducto{
	public:
		DtComun(int, string, float, int,string);
		~DtComun();
};

#endif

