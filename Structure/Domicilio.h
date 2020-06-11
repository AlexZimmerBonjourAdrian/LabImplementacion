#include <iostream>

#include "../interfaces/ICollectible.h"
#include "../interfaces/ICollection.h"
#include "string.h"
using namespace std;

#ifndef Domicilio_H
#define Domicilio_h
class Domicilio : public ICollectible
{
private:
    
 //DtDireccion pedido;
 string nomRecibe;
 string telRecibe;
 

public:
    Domicilio(DtDirrecion pedido, string nomRecibe,string telRecibe);
    
    ~Domicilio();
};




