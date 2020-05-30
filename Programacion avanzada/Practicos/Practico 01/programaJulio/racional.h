#ifndef RACIONAL_H
#define RACIONAL_H

class Racional{
private:
    int numerador; //Numerador
    int denominador; //Denominador

public:
    //--- Constructores -------
    Racional();
    Racional(int _num);
    Racional(int _num, int _deno);
    Racional(const Racional &r);
    //--- Destructor ----------
    ~Racional();
    //--- Operaciones geter y seter ------
    int getNumerador();
    int getDenominador();
    void setNumerador(int _num);
    void setDenominador(int _deno);
    //--- Operacines basicas con Racionales ------
    Racional suma(Racional &r);
    Racional diferencia(Racional &r);
    Racional producto(Racional &r);
    Racional cociente(Racional &r);
    //--- Sobrecarga de operadores --------------
    friend Racional operator *( const Racional &r1, const Racional &r2);
    friend Racional operator +(const Racional &r1, const Racional &r2);
    friend Racional operator -(const Racional &r1, const Racional &r2);
    friend Racional operator /(const Racional &r1, const Racional &r2);
    friend bool operator ==(const Racional &r1, const Racional &r2);
    friend bool operator !=(const Racional &r1, const Racional &r2);

};

#endif // RACIONAL_H
