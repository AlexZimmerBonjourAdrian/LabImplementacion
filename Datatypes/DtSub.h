#include "../ICollection/interfaces/ICollectible.h"
class DtSub :: public ICollectible
{
private:
     int cod;
     int cant;
public:
    DtSub(int cod, int cant);
    int getCod();
    int getCant();
    virtual ~DtSub();
};


