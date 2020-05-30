#include "a.h"
#include <iostream>
using namespace std;

A::A(int _a){
    a = _a;
}

void A::imprimir(){
    cout << "Nombre de clase: A, a=" << a << endl;
}
