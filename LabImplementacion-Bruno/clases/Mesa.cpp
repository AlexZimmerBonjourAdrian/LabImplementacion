#include "Mesa.h"
#ifndef MESA_CPP
#define MESA_CPP
Mesa::Mesa(int id, IDictionary * historial)
{
    this->id=id;
    this->historial=historial;
}

Mesa::~Mesa(){
}

void Mesa::setid(int id)
{
    this->id = id;
}

int Mesa::getid()
{
    return id;
}

#endif

