#ifndef DTREPARTIDOR_H
#define DTREPARTIDR_H

#include "./DtEmpleado.h"

class DtRepartidor : DtEmpleado
{
private:
    string Medio_Transporte;
public:
    DtRepartidor(string);
    string getMedio_Transporte;
    ~DtRepartidor();
};

#endif


