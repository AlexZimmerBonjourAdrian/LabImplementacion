#ifndef C_H
#define C_H

class A;   // Declaración forward de la clase A
class B;   // Declaración forward de la clase B

class C{
    private:
        int c;
        A * miA;
        B * miB;
    public:
        C(int);
        void imprimir();
};

#endif // C_H
