#ifndef DTEMPLEADO_H
#define DTEMPLEADO_H
#include <iostream>
using namespace std;

class DtEmpleado
{
private:
    int id;
    string nombre;
    
public:
     DtEmpleado(int,string);
    int getId();
    string getNombre();   
    virtual ~DtEmpleado();
    
};

#endif
