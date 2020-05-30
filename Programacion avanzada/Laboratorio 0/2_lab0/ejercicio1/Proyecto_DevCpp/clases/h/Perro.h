#ifndef Perro_h
#define Perro_h
#include "Mascota.h"
#include "..\..\enums\Enums.h"

class Perro: public Mascota{
    private:
        RazaPerro raza;
        bool vacunaCachorro;
    public:
        Perro(string, Genero, float, RazaPerro, bool);
        virtual ~Perro();
        //---Seter y Geter ---------------
        RazaPerro getRaza();
        bool getVacunaCachorro();
        void setRaza(RazaPerro);
        void setVacunaCachorro(bool);
        //--- Operación abstracta heredada de mascota -------
        float obtenerRacionDiaria();
};

#endif
