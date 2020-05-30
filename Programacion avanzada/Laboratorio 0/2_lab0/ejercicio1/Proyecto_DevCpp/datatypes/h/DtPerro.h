#ifndef DtPerro_h
#define DtPerro_h
#include "DtMascota.h"
#include "..\..\enums\Enums.h"

class DtPerro: public DtMascota{
    private:
        RazaPerro raza;
        bool vacunaCachorro;
    public:
        DtPerro(std::string _nombre, int _genero,  float _peso, RazaPerro _raza, bool _vacuna);
        DtPerro(std::string _nombre, int _genero,  float _peso, RazaPerro _raza, bool _vacuna, float _racionDiaria);
		virtual ~DtPerro();
        //---Getters ---------------
        RazaPerro getRaza();
        bool getVacunaCachorro();
        
        // sobrecarga de operadores
		friend std::ostream& operator <<( std::ostream &o ,const DtPerro &);
};

#endif
