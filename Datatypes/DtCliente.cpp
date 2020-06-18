#include "./DtCliente.h"

DtCliente::DtCliente(string telefono, string nombre, DtDireccion * Direccion)
{
    this->nombre=nombre;
    this->telefono=telefono;
    this->direccion=Direccion;
}

DtCliente::getNombre()
{
    return this->nombre;
}

DtCliente::getTelefono()
{
    return this->telefono;
}

DtCliente::getdireccion()
{
    return this->direccion;
}

DtCliente::~DtCliente(){
    
}