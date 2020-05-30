// racional.h
#ifndef racional_h
#define racional_h

// <iostream> lo usa mostrar() para poder mostrar el valor, pero creo que no se deberia hacer asi pero bue... es para probar.

class Racional{
	private:
		int num;				// numerador
		int den;				// denominador
		int MCM(int, int);		// Minimo Comun Multiplo
	public:
		Racional();							// constructor por defecto
		Racional(int);						// constructor con parametro
		Racional(int, int);					// constructor con parametros
		Racional(Racional*);				// constructor por copia
		~Racional();						// destructor
		
		void set_numerador(int);			// establecer el numerador
		void set_denominador(int);			// establecer el denominador
		int get_numerador();				// obtener el numerador
		int get_denominador();				// obtener el denominador
		
		Racional* suma(Racional *);			// al hacer r1->suma(r2) devuelve un r3 con la suma
		Racional* diferencia(Racional*);
		Racional* producto(Racional*);
		Racional* cociente(Racional*);
		Racional* reducir();				// reduce/simplifica la fraqccion, ej: 4/8 devuelve 1/2
		bool igualdad(Racional*);
		
		// Respecto a las siguientes sobrecargas: cualquier parecido con el codigo que julio me mostro, es pura coincidencia...
		friend Racional operator *( const Racional &r1, const Racional &r2);
		friend Racional operator +(const Racional &r1, const Racional &r2);
		friend Racional operator -(const Racional &r1, const Racional &r2);
		friend Racional operator /(const Racional &r1, const Racional &r2);
		friend bool operator ==(const Racional &r1, const Racional &r2);
		friend bool operator !=(const Racional &r1, const Racional &r2);
		/* Intente hacer las sobrecargas sin friend pero daba muchos errores
		como los parametros recibidos son const, no se puede invocar una funcion donde ese parametro no sea const, 
		por eso (y para no reescribir todas las funciones) tuve que repetir codigo para darle metodo por separado alas funciones y a las sobrecargas
		*/
};

#endif



