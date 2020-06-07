#include "Mesa.h"

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



