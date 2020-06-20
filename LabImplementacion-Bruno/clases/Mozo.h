

#include <iostream>
#include "../colecciones/List.cpp"
#include "../interfaces/IDictionary.h"
#include "../Datatypes/DtMesa.cpp"
#include "Empleado.cpp"
#include "Mesa.cpp"

#ifndef MOZO_H
#define MOZO_H

class Mozo : public Empleado{
private:
    IDictionary * mesas;
public:
    Mozo(string, IDictionary *);
    ICollection * getDTMesa();
    IDictionary * getMesa();
    void borrarMesas(Vlocal *);
    void agregarMesa(Mesa *);
    bool  check_mesa(Mesa * m);
    virtual ~Mozo();
};
#endif
