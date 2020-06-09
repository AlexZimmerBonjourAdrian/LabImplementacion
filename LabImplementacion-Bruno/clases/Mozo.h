#include <iostream>
#include "../interfaces/ICollectible.h"
#include "../interfaces/IDictionary.h"
#include "Mesa.cpp"

#ifndef MOZO_H
#define MOZO_H
class Mozo : public ICollectible
{
private:
    int idmozo;
    IDictionary * mesas;
public:
    Mozo(int, IDictionary *);
    void setIdMozo(int idmozo);
    int getidmozo();
    IDictionary * getMesa();
    void agregarMesa(Mesa *);
    virtual ~Mozo();
};
#endif
