#ifndef EMPRESAEXTRANJERA_H
#define EMPRESAEXTRANJERA_H

#include "Empresa.h"

class EmpresaExtranjera : public Empresa {
private:
    string nombreFantacia;
public:
    EmpresaExtranjera(string id, const Direccion& direccion, string nombreFantacia);
    
    string getNombreFantacia() const;
    float getDescuento();
    virtual DtEmpresa* getDtEmpresa();
    
    virtual ~EmpresaExtranjera();
};

#endif /* DTEMPRESAEXTRANJERA_H */
