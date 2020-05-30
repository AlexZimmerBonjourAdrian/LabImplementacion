#include "racional.h"

Racional::Racional(){
    numerador = 0;
    denominador = 1;
}
Racional::Racional(int _num){
    numerador = _num;
    denominador = 1;
}
Racional::Racional(int _num, int _deno){
    numerador = _num;
    denominador = _deno;
}

Racional::Racional(const Racional &r){ //Constructor por copia
    numerador = r.numerador;
    denominador = r.denominador;
}

Racional::~Racional(){
}

int Racional::getNumerador(){
    return numerador;
}

int Racional::getDenominador(){
    return denominador ;
}

void Racional::setNumerador(int _num){
    numerador = _num;
}

void Racional::setDenominador(int _deno){
    denominador = _deno;
}

Racional Racional::producto(Racional &r){
    Racional res = Racional(numerador * r.getNumerador(), denominador * r.getDenominador());
    return res;
}

Racional Racional::suma(Racional &r){
    Racional res = Racional();
    res.setDenominador(denominador * r.getDenominador());
    res.setNumerador((res.getDenominador()/denominador * numerador) + (res.getDenominador()/r.getDenominador() * r.getNumerador()));
    return res;
}

Racional Racional::diferencia(Racional &r){
    Racional res = Racional();
    res.setDenominador(denominador * r.getDenominador());
    res.setNumerador((res.getDenominador() / denominador * numerador) - (res.getDenominador()/r.getDenominador() * r.getNumerador()) );
    return res;
}

Racional Racional::cociente(Racional &r){
    Racional res = Racional(numerador * r.getDenominador(), denominador * r.getNumerador());
    return res;
}

Racional operator +(const Racional &r1, const Racional &r2){
    Racional res = Racional();
    res.setDenominador(r1.denominador * r2.denominador);
    res.setNumerador((res.getDenominador()/r1.denominador * r1.numerador) + (res.getDenominador()/r2.denominador * r2.numerador));
    return res;
}

Racional operator *(const Racional &r1, const Racional &r2){
    return (Racional(r1.numerador * r2.numerador, r1.denominador * r2.denominador));
}

Racional operator -(const Racional &r1, const Racional &r2){
    Racional res = Racional();
    res.setDenominador(r1.denominador * r2.denominador);
    res.setNumerador((res.getDenominador() / r1.denominador * r1.numerador) - (res.getDenominador()/r2.denominador * r2.numerador) );
    return res;
}

Racional operator /(const Racional &r1, const Racional &r2){
    Racional res = Racional(r1.numerador * r2.denominador, r1.denominador * r2.numerador);
    return res;
}

bool operator ==(const Racional &r1, const Racional &r2){
    if(r1.numerador == r2.numerador && r1.denominador==r2.denominador)
        return true;
    else
        return false;
}

bool operator !=(const Racional &r1, const Racional &r2){
    if(r1.numerador != r2.numerador || r1.denominador != r2.denominador)
        return true;
    else
        return false;
}




