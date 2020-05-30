#ifndef B_H
#define B_H

class A;   // Declaración forward de la clase A
class C;   // Declaración forward de la clase C

class B{
    private:
        int b;
        A * miA;
        B * miB;
    public:
        B(int);
        void imprimir();
};

#endif // B_H
