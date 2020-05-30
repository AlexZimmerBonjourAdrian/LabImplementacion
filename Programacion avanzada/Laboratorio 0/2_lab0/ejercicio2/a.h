#ifndef A_H
#define A_H

class B;   // Declaración forward de la clase B
class C;   // Declaración forward de la clase C

class A{
    private:
        int a;
        B * miB;
        C * miC;
    public:
        A(int);
        void imprimir();
};

#endif // A_H
