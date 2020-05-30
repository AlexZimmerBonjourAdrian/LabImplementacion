#ifndef DtGato_h
#define DtGato_h
#include "DtMascota.h"
#include "..\..\enums\Enums.h"

class DtGato: public DtMascota{
    private:
        TipoPelo pelo;
    public:
        //--- Constructor de Gato ---------
        DtGato(std::string _nombre, int _genero, float _peso, TipoPelo _pelo);
        DtGato(std::string _nombre, int _genero, float _peso, TipoPelo _pelo, float _racionDiaria);
        virtual ~DtGato();
		//___ Get
        TipoPelo getPelo();
        friend std::ostream& operator <<(std::ostream &, DtGato *);

};

#endif
