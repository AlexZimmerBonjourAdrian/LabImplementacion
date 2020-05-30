#include <iostream>
#include "racional.h"

using namespace std;

int main(){
    Racional r1(2,3), r2;
    Racional r3(4), r4 = r1;
    if (r1 == r2)
        r1 = r1 + r2;
    else
        r1 = r1 -r2;
    if (r3 != r4)
        r3 = r3 * r4;
    else
        r3 = r3 / r4;
    if (r1 == 2)
        r1 = r1 + 1;
    else
        r1 = r1 -1;
    if (r3 != 3)
        r3 = r3 * 2;
    else
        r3 = r3 / 2;
    cout << "r3 = " << r3.getNumerador() << "/" << r3.getDenominador() << endl;

    return 0;
}






