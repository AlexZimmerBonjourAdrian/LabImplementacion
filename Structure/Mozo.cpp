#include "Mozo.h"
#include <iostream>
//#include "Mesa.h"
Mozo::Mozo(int idmozo)
{
    this->idmozo=idmozo;
    
}
void Mozo::setIdMozo(int idmozo)
{
    this->idmozo= idmozo;
}
int Mozo:getMozo()
{
    return this->idmozo;
}

ICollection * Mozo::getMesa()
{
 
}

Mozo::~Mozo()
{

}