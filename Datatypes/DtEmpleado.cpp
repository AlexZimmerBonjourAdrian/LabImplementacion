#include "DtEmpleado.h"

DtEmpleado::DtEmpleado(int Id, string nombre)
{
    this->id=Id;
    this->nombre=nombre;
}
int DtEmpleado::getId()
{
    return this->id;
}
string DtEmpleado::getNombre()
{
    return this->nombre;
}
DtEmpleado::~DtEmpleado(){
    
}