#include "b.h"
#include <iostream>
using namespace std;

B::B(int _b){
    b = _b;
}

void B::imprimir(){
    cout << "Nombre de clase: B, b=" << b << endl;
}
