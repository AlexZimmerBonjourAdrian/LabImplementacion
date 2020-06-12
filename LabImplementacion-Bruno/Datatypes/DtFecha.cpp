#include "DtFecha.h"

DtFecha::DtFecha(time_t FechaHora)
{
    this->FechaHora=FechaHora;
}

time_t DtFecha::getFechaHora()
{
    return  this->FechaHora;
}

DtFecha::~DtFecha()
{

}
