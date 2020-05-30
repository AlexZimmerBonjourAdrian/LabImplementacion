#ifndef Gato_h
#define Gato_h

enum TipoPelo{ Corto, Mediano, Largo };

class Gato: public Mascota{
    private:
        TipoPelo pelo;
    public:
        //--- Constructor de Gato ---------
        Gato(string _nombre, Genero _genero, float _peso, TipoPelo _pelo);
        //___ Geter y Seter ---------------
        TipoPelo getPelo();
        void setPelo(TipoPelo _pelo);
        float obtenerRacionDiaria();
};



#endif
