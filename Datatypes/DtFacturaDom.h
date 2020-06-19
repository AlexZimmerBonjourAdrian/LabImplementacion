#include "../Datatypes/DtFactura.h"
#include "../interfaces/ICollectible.h"
#include "string.h"
#ifndef DTFACTURADOM_H
#define DTFACTURADOM_H
using namespace std;
class DtFacturaDom :: public ICollectible
{
private:
    string medio_transporte;
public:
    DtFacturaDom(string medio_transporte);
    string getMedio_Transporte();
     virtual ~DtFacturaDom();
};

#endif

