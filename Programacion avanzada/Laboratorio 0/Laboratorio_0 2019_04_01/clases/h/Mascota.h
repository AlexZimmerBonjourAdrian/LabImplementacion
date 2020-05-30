#ifndef Mascota_h
#define Mascota_h
#include <iostream>

using namespace std;

enum Genero{Macho, Hembra};

class Mascota{
    protected:
        string nombre;
        Genero genero;
        float peso;
    public:
        Mascota(string _nombre, Genero _genero, float _peso);
 //       ~Mascota();

        //---Geter y Seter ------------
        string getNombre();
        Genero getGenero();
        float getPeso();
        void setNombre(string);
        void setGenero(Genero);
        void setPeso(float);
        //--- Método abstracto --------
        virtual float obtenerRacionDiaria()=0;
};

#endif
