#include <iostream>
#include "../interfaces/ICollectible.h"
#include "../interfaces/ICollection.h"
#include "Mesa.cpp"

#ifndef MOZO_H
#define MOZO_H
class Mozo : public ICollectible
{
private:
    int idmozo;
    ICollection * mesas;
public:
    Mozo(int, ICollection *);
    void setIdMozo(int idmozo);
    int getidmozo();
    ICollection * getMesa();
    void agregarMesa(Mesa *);
    virtual ~Mozo();
};
#endif
