
#include <iostream>
#include "../interfaces/ICollectible.h"
#include "../interfaces/IDictionary.h"


#ifndef MESA_H
#define MESA_H

class Vlocal;
class  Mesa : public ICollectible
{
private:
    int id;
    IDictionary * historial;
    Vlocal * venta;
public:
     Mesa(int id, IDictionary*);
     void setid(int id);
     bool coincide(Vlocal *);
     int getid();
     void setVenta(Vlocal *);
     Vlocal * getVenta();
    ~Mesa(); 
};

#endif
