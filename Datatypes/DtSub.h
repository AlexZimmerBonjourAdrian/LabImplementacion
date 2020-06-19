#include "../interfaces/ICollectible.h"
#ifndef DTSUB_H
#define DTSUB_H
class DtSub : public ICollectible
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

#endif


