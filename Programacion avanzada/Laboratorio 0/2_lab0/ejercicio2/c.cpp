#include "c.h"
#include <iostream>
using namespace std;

C::C(int _c){
    c = _c;
}

void C::imprimir(){
    cout << "Nombre de clase: C, c=" << c << endl;
}
