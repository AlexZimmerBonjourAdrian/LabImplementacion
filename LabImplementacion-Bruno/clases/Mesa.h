
#include <iostream>
#include "../interfaces/ICollectible.h"
#include "../interfaces/IDictionary.h"
class Vlocal;

#ifndef MESA_H
#define MESA_H


class  Mesa : public ICollectible
{
private:
    int id;
    IDictionary * historial;
    Vlocal * venta;
public:
     Mesa (int id, IDictionary*);
     void setid(int id);
     int getid();
     void setVenta(Vlocal *);
     Vlocal * getVenta();
    virtual ~Mesa(); 
};

#endif
