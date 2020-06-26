

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
    ICollection * getDTMesa()  const;
    IDictionary * getMesa();
    void borrarMesas(Vlocal *);
    void agregarMesa(Mesa *);
    bool  check_mesa(Mesa * m);
    DtEmpleado * getDatos() const;
    int cantMesas();
    virtual ~Mozo();
};
#endif
