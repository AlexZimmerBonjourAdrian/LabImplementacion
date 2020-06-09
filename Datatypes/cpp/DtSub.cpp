#include "../DtSub.h"

DtSub::DtSub(int cod, int cant)
{
this->cod = cod;
this->cant = cant;
}

int DtSub::getCod()
{
    return this->cod;
}

int DtSub::getCant()
{
    return this->cant;
}

DtSub::~DtSub()
{

}