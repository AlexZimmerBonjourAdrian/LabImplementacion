

#include <iostream>
#include "../interfaces/ICollectible.h"
#include "../interfaces/IDictionary.h"
#include "Empleado.cpp"
#include "Mesa.cpp"

#ifndef MOZO_H
#define MOZO_H

class Mozo : public Empleado{
private:
    IDictionary * mesas;
public:
    Mozo(string, IDictionary *);
    IDictionary * getMesa();
    void agregarMesa(Mesa *);
    virtual ~Mozo();
};
#endif
