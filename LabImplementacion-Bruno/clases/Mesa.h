#include <iostream>
#include "../interfaces/ICollectible.h"
#include "../interfaces/ICollection.h"

#ifndef MESA_H
#define MESA_H
class  Mesa : public ICollectible
{
private:
    int id;
public:
     Mesa (int id);
     void setid(int id);
     int getid();
    // Venta getVenta();
    virtual ~Mesa(); 
};

#endif
