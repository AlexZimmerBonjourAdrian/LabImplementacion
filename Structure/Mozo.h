#include <iostream>
#include "../ICollection/interfaces/ICollectible.h"
#include "../ICollection/interfaces/ICollection.h"
class Mozo :: public ICollectible
{
private:
    int idmozo;
public:
    Mozo(int idmozo);
    void setIdMozo(int idmozo);
    int getidmozo();
    ICollection * getMesa();
    virtual ~Mozo();
};


