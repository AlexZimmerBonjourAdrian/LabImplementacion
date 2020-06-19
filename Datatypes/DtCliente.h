#include <iostream>
#include "./DtDireccion.h"
#ifndef DtCliente_H
#define DTCliente_H
using namespace std;
class DtCliente
{
private:
string telefono;
string nombre;
DtDireccion * direccion;
   
public:
    DtCliente(string,string,DtDireccion);
    string getTelefono();
    string getNombre();
    DtDireccion * getdireccion();
    virtual ~DtCliente();
};

#endif
