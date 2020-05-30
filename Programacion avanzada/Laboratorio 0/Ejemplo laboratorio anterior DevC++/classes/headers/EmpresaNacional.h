#ifndef EMPRESANACIONAL_H
#define EMPRESANACIONAL_H

#include "Empresa.h"

class EmpresaNacional : public Empresa {
private:
    string rut;
public:
    EmpresaNacional(string id, const Direccion& direccion, string rut);
    
    string getRut() const;
    float getDescuento();
    virtual DtEmpresa* getDtEmpresa();

    virtual ~EmpresaNacional();
};

#endif /* EMPRESANACIONAL_H */

