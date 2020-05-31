#include <iostream>
#include "../ICollection/interfaces/ICollectible.h"
#include "../ICollection/interfaces/ICollection.h"
class  Mesa :: ICollectible
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


