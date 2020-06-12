#include <iostream>
#include "../interfaces/ICollectible.h"
#include "../interfaces/ICollection.h"

#ifndef MESA_H
#define MESA_H
class  Mesa : public ICollectible
{
private:
    int id;
    IDictionary * historial;
public:
     Mesa (int id, IDictionary*);
     void setid(int id);
     int getid();
    //Venta getVenta();
    virtual ~Mesa(); 
};

#endif
