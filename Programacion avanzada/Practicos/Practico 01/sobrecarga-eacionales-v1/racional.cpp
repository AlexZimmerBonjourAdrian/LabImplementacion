// racional.cpp
#include "racional.h"

//-------------------------------------------------------------------
Racional::Racional(){	// constructor por defecto
	this->num = 0;
	this->den = 1;
}


Racional::Racional(int n){	// constructor con datos
	this->num = n;
	this->den = 1;
}


Racional::Racional(int n, int d){	// constructor con datos
	this->num = n;
	this->den = d;
}


Racional::Racional(Racional *r){	// constructor por copia
	this->num = r->get_numerador();
	this->den = r->get_denominador();
}


Racional::~Racional(){	// destructor
	/* Segun este video, aca no va nada...
	https://www.youtube.com/watch?v=N-3BVAvWJjk
	Supongo que cuando hayan relaciones entre clases aca habra que hacer algo con ellas, pero ni idea
	*/
}

//-------------------------------------------------------------------
void Racional::set_numerador(int n){
	this->num = n;
}


void Racional::set_denominador(int d){
	this->den = d;
}


int Racional::get_numerador(){
	return this->num;
}


int Racional::get_denominador(){
	return this->den;
}

//-------------------------------------------------------------------
Racional*  Racional::suma(Racional  *r){
	/* Hallar minimo comun multiplo de denominadores (sera denominador final)
	multiplicar cada numerador por el numero que hay que multiplicar el denominador para obtener el minimo comun multiplo
	sumar los dos resultados para obtener el numerador final
	Nota: Si no se entiende busca en gugle
	*/
	int mcm = MCM(this->den, r->get_denominador());	// denominador del resultado
	int numA = (mcm / this->den) * this->num; // un numerador
	int numB = (mcm / r->get_denominador()) * r->get_numerador(); // el otro numerador
	return new Racional(numA + numB, mcm);
}


Racional* Racional::diferencia(Racional *r){
	/* 	Hay dos casos:
	-Fracciones con el mismo denominador:
	Restar numeradores y dejar el denominador.
	-Fracciones con distinto denominador:
	Multiplicar numerador de la primera por denominador de la segunda y 
	el denominador de la primera por el numerador de la segunda.
	Ambas multiplicaciones se restan y el resultado es el numerador.
	Para el denominador hay que multiplicar los dos denominadores
	*/
	if (this->den == r->get_denominador()){
		return new Racional(this->num - r->get_numerador(), this->den);
	}else{
		return new Racional((this->num * r->get_denominador()) - (this->den * r->get_numerador()), this->den * r->get_denominador());
	}
}


Racional* Racional::producto(Racional *r){
	// Multiplicar los de arriba y multiplicar los de abajo
	return new Racional(this->num * r->get_numerador(), this->den * r->get_denominador());
}


Racional* Racional::cociente(Racional *r){
	/* Multiplicar en cruz
	numerador final = numerador de la primera * denominador de la segunda
	denominador final = denominador de la primera * numerador de la segunda
	*/
	return new Racional(this->num * r->get_denominador(), this->den * r->get_numerador());
}


Racional* Racional::reducir(){
	/* funcion basada en la siguiente pagina, aunque tenia varios errores la arregle xD:
	https://isseu.wordpress.com/2009/08/27/funcion-reducir-fraccion-c/
	*/
	
	int n, d; // numerador y denominador resultantes
	
	if (this->num == 1 || this->den == 1){
		// como el denominador es 1, no se puede reducir, entonces devuelve un puntero a un nuevo racional copiando el actual
		return new Racional(this);
	}
	
	for (int i = 2; i <= this->num; i++){
		if (this->num % i == 0 && this->den % i == 0){
			return new Racional(this->num / i, this->den / i); 
		}
	}
	
	// si no encontro un numero por el cual se pueda dividir tanto el numerador como el denominador, no se puede reducir y retorna una copia
	return new Racional(this);
}


bool Racional::igualdad(Racional *r){
	// los racionales a comparar pueden o no estar reducidos, asi que los redusco a los dos para compararlos
	Racional *r1 = this->reducir();
	Racional *r2 = r->reducir();
	
	bool ret = r1->get_numerador() == r2->get_numerador() && r1->get_denominador() == r2->get_denominador();
	
	// como reserve memoria para r1 y r2, debo liberarla antes de retornar el resultado
	r1->~Racional();
	r2->~Racional();
	return ret;
}

//-------------------------------------------------------------------
Racional operator +(const Racional &r1, const Racional &r2){
	/* Hallar minimo comun multiplo de denominadores (sera denominador final)
	multiplicar cada numerador por el numero que hay que multiplicar el denominador para obtener el minimo comun multiplo
	sumar los dos resultados para obtener el numerador final
	Nota: Si no se entiende busca en gugle */
	
	// Esta vez no pude acceder a la funcion MCM directamente, por eso defini primero el Racional ret, para luego a travez de el aceder a MCM
	
	Racional ret = Racional();
	int mcm = ret.MCM(r1.den, r2.den);	// denominador del resultado
	int numA = (mcm / r1.den) * r1.num; // un numerador
	int numB = (mcm / r2.den) * r2.num; // el otro numerador
	ret.set_numerador(numA + numB);
	ret.set_denominador(mcm);
	return ret;
}


Racional operator -(const Racional &r1, const Racional &r2){
    /* 	Hay dos casos:
	-Fracciones con el mismo denominador:
	Restar numeradores y dejar el denominador.
	-Fracciones con distinto denominador:
	Multiplicar numerador de la primera por denominador de la segunda y 
	el denominador de la primera por el numerador de la segunda.
	Ambas multiplicaciones se restan y el resultado es el numerador.
	Para el denominador hay que multiplicar los dos denominadores
	*/
	if (r1.den == r2.den){
		return new Racional(r1.num - r2.num, r1.den);
	}else{
		return new Racional((r1.num * r2.den) - (r1.den * r2.num), r1.den * r2.den);
	}
}


Racional operator *(const Racional &r1, const Racional &r2){
	// Multiplicar los de arriba y multiplicar los de abajo
	return new Racional(r1.num * r2.num, r1.den * r2.den);
}


Racional operator /(const Racional &r1, const Racional &r2){
	/* Multiplicar en cruz
	numerador final = numerador de la primera * denominador de la segunda
	denominador final = denominador de la primera * numerador de la segunda
	*/
	return new Racional(r1.num * r2.den, r1.den * r2.num);
}


bool operator ==(const Racional &r1, const Racional &r2){
	// los racionales a comparar pueden o no estar reducidos, asi que los redusco a los dos para compararlos
	// Aca no se puede hacer
	// Racional rac1 = r1.reducir();
	// porque r1 es constante y da problemas con la funcion, entonces es mejor hacer esto otro
	
	Racional *aux;
	Racional rac1(r1.num, r1.den);	// copia r1 (no uso el constructor por copia porque recibi variables como const
	aux = &rac1;					// apunto a donde esta rac1
	rac1 = rac1.reducir();			// me devuelve un nuevo lugar de memoria con la fraccion reducida
	delete aux;						// y para no dejar memoria colgada con la fraccion sin reducir, la libero ahora
	 
	Racional rac2(r2.num, r2.den);
	aux = &rac2;
	rac2 = rac2.reducir();
	delete aux;
	
	bool ret = rac1.get_numerador() == rac2.get_numerador() && rac1.get_denominador() == rac2.get_denominador();
	return ret;
}


bool operator !=(const Racional &r1, const Racional &r2){
		Racional *aux;
	Racional rac1(r1.num, r1.den);	// copia r1 (no uso el constructor por copia porque recibi variables como const
	aux = &rac1;					// apunto a donde esta rac1
	rac1 = rac1.reducir();			// me devuelve un nuevo lugar de memoria con la fraccion reducida
	delete aux;						// y para no dejar memoria colgada con la fraccion sin reducir, la libero ahora
	 
	Racional rac2(r2.num, r2.den);
	aux = &rac2;
	rac2 = rac2.reducir();
	delete aux;
	
	bool ret = rac1.get_numerador() == rac2.get_numerador() && rac1.get_denominador() == rac2.get_denominador();
	return !ret;
}


//-------------------------------------------------------------------
int Racional::MCM(int a, int b){
	if (a == b)	return a;
	
	int mcm;
	
	if (a>b)	mcm = a;
	else		mcm = b;
	
	for (; !(mcm % a == 0 && mcm % b == 0); mcm++);
	return mcm;
}



