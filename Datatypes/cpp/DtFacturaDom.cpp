#include "../DtFacturaDom.h"
#include "string.h"
using namespace std;
DtFacturaDom::DtFacturaDom(string medio_transporte)
{
    this->medio_transporte= medio_transporte;
}

DtFacturaDom::getMedio_Transporte(string getMedio_Transporte)
{
    return this->medio_transporte;
}

DtFacturaDom::~DtFacturaDom()
{
    
}