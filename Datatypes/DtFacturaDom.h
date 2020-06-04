
#ifndef DTFACTURADOM_H
#define DTFACTURADOM_H
#include "../Datatypes/DtFactura.h"
#include "../ICollection/interfaces/ICollectible.h"
#include "string.h"
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

