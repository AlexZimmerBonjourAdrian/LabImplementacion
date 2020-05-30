#ifndef Gato_h
#define Gato_h
#include "Mascota.h"
#include "..\..\enums\Enums.h"

class Gato: public Mascota{
    private:
        TipoPelo pelo;
    public:
        //--- Constructor de Gato ---------
        Gato(string _nombre, Genero _genero, float _peso, TipoPelo _pelo);
        virtual ~Gato();
        
		//___ Geter y Seter ---------------
        TipoPelo getPelo();
        void setPelo(TipoPelo _pelo);
        float obtenerRacionDiaria();
};



#endif
