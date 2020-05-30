#include <iostream>
#include "racional.h"
using namespace std;

/* Practico 1 - Ejercicio 2 */
string mostrar(Racional *);	// para mostrar la fraccion
string cStr(int);			// sirve para la funcion mostrar

int main(int argc, char** argv) {
	Racional *rac1 = new Racional(4,5);
	Racional *rac2 = new Racional(10,7);
	Racional *resultado = new Racional();
	
	
	resultado->~Racional();
	
	// Algunas pruebas con funciones y con sobrecarga de operadores
	cout << "--------------------------" << endl;
	cout << "Operaciones con funciones entre " << mostrar(rac1) << " y " << mostrar(rac2) << endl;
	
	resultado = rac1->suma(rac2); 
	cout << "Suma: " << mostrar(resultado) << endl;
	resultado->~Racional();
	
	resultado = rac1->diferencia(rac2); 
	cout << "Diferencia: " << mostrar(resultado) << endl;
	resultado->~Racional();
		
	resultado = rac1->producto(rac2); 
	cout << "Producto: " << mostrar(resultado) << endl;
	resultado->~Racional();
		
	resultado = rac1->cociente(rac2); 
	cout << "Cociente: " << mostrar(resultado) << endl;
	resultado->~Racional();
	
	
	cout << "--------------------------" << endl;
	cout << "Operaciones con sobrecarga entre " << mostrar(rac1) << " y " << mostrar(rac2) << endl;
	
	*resultado = *rac1 + *rac2;
	cout << "Suma: " << mostrar(resultado) << endl;
	resultado->~Racional();
	
	*resultado = *rac1 - *rac2;
	cout << "Diferencia: " << mostrar(resultado) << endl;
	resultado->~Racional();
		
	*resultado = *rac1 * *rac2;
	cout << "Producto: " << mostrar(resultado) << endl;
	resultado->~Racional();
		
	*resultado = *rac1 / *rac2;
	cout << "Cociente: " << mostrar(resultado) << endl;
	resultado->~Racional();
	
	
	cout << "--------------------------" << endl;
	cout << "Comparaciones con funciones" << mostrar(rac1) << " y " << mostrar(rac2) << endl;
	
	if (rac1->igualdad(rac1))	cout << mostrar(rac1) << " = " << mostrar(rac1) << endl;
	if (rac1->igualdad(rac2))	cout << mostrar(rac1) << " = " << mostrar(rac2) << endl;
	if (!rac1->igualdad(rac1))	cout << mostrar(rac1) << " != " << mostrar(rac1) << endl;
	if (!rac1->igualdad(rac2))	cout << mostrar(rac1) << " != " << mostrar(rac2) << endl;
	
	
	cout << "--------------------------" << endl;
	cout << "Comparaciones con sobrecarga" << mostrar(rac1) << " y " << mostrar(rac2) << endl;
	
	if (*rac1 == *rac1)		cout << mostrar(rac1) << " = " << mostrar(rac1) << endl;
	if (*rac1 == *rac2)		cout << mostrar(rac1) << " = " << mostrar(rac2) << endl;
	if (*rac1 != *rac1)		cout << mostrar(rac1) << " != " << mostrar(rac1) << endl;
	if (*rac1 != *rac2)		cout << mostrar(rac1) << " != " << mostrar(rac2) << endl;
	
	cout << "==========================" << endl;
	cout << "Parte b" << endl;
	
	// El codigo siguiente es la parte b, que en el practico estaban como objetos y aca lo traduje a punteros
	// Si lo quieren ver con objetos como lo pedia, esta en la version 2 en la otra carpeta
	Racional *r1 = new Racional(2,3), *r2 = new Racional();
	Racional *r3 = new Racional(4), *r4 = new Racional(r1);
	
	cout << "r1 = " << mostrar(r1) << endl;
	cout << "r2 = " << mostrar(r2) << endl;
	cout << "r3 = " << mostrar(r3) << endl;
	cout << "r4 = " << mostrar(r4) << endl;
	cout << "----------" << endl;
	
	// hay que usar el * porque no se puede hacer sobrecarga recibiendo punteros como parametro
	// Entonces hay que comparar 'a lo que apunta r1 con a lo que apunta r2'
	// y lo mismo para las cuentas
	if (*r1 == *r2){
		*r1 = *r1 + *r2;
		cout << "r1 = r1 + r2 = " << mostrar(r1) << endl;
	}else{
		*r1 = *r1 - *r2;
		cout << "r1 = r1 - r2 = " << mostrar(r1) << endl;
	}
	
	if (*r3 != *r4){
		*r3 = *r3 * *r4;
		cout << "r3 = r3 * r4 = " << mostrar(r3) << endl;
	}else{
		*r3 = *r3 / *r4;
		cout << "r3 = r3 / r4 = " << mostrar(r3) << endl;
	}
	
	/* Aca empieza a usar Racionales e int, al parecer, como hay un constructor que recibe un int como parametro
	el compilador convierte el 2 en racional (2/1) y con el realiza la operacion mediante las sobrecargas
	Llegue a esa conclusion porque si se saca dicho constru, no compila y da error
	*/
	if (*r1 == 2){
		*r1 = *r1 + 1;
		cout << "r1 = r1 + 1 = " << mostrar(r1) << endl;
	}else{
		*r1 = *r1 - 1;
		cout << "r1 = r1 - 1 = " << mostrar(r1) << endl;
	}
	
	
	if (*r3 != 3){
		*r3 = *r3 * 2;
		cout << "r3 = r3 * 2 = " << mostrar(r3) << endl;
	}else{
		*r3 = *r3 / 2;
		cout << "r3 = r3 / 2 = " << mostrar(r3) << endl;
	}
	
	*r3 = 3 * *r2;
	cout << "r3 = 3 * r2 = " << mostrar(r3) << endl;
	if (4 == (2 + *r2)){
		*r3 = 1 / *r2;
		cout << "r3 = 1 * r2 = " << mostrar(r3) << endl;
	}
	
	
	system("PAUSE");
	return 0;
}

//************************************************************************
string mostrar(Racional *r){
	// retorna un string con la fraccion
	return cStr(r->get_numerador()) + '/' + cStr(r->get_denominador());
}


string cStr(int n){
	// Dado un entero, devuelve un string con el numero
	
	const char DIGITOS[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
	std::string ret = "";
	bool negativo = n < 0;
	if (negativo){
		n *= -1;
	}
	
	do{
		ret = DIGITOS[n % 10] + ret;	// agrega el ultimo digito del numero a la variable de retorno
		n /= 10;	// avanza el contador
	 }while(n != 0);
	
	if (negativo){
		ret = '-' + ret;
	}
	
	return ret;
}



