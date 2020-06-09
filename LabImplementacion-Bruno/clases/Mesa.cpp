#include "Mesa.h"
#ifndef MESA_CPP
#define MESA_CPP
Mesa::Mesa(int id)
{
    this->id=id;
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

