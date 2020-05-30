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
		Racional(const Racional &);					// constructor por copia
		~Racional();						// destructor
		
		void set_numerador(int);			// establecer el numerador
		void set_denominador(int);			// establecer el denominador
		int get_numerador() const;			// obtener el numerador
		int get_denominador() const;				// obtener el denominador
		
		Racional suma(const Racional &);	// al hacer r1->suma(r2) devuelve un r3 con la suma
		Racional diferencia(const Racional &);
		Racional producto(const Racional &);
		Racional cociente(const Racional &);
		Racional reducir() const ;					// reduce/simplifica la fraqccion, ej: 4/8 devuelve 1/2
		bool igualdad(const Racional &);
		
		// Estas sobrecargas son exactamente iguales a las otras
		friend Racional operator *( const Racional &r1, const Racional &r2);
		friend Racional operator +(const Racional &r1, const Racional &r2);
		friend Racional operator -(const Racional &r1, const Racional &r2);
		friend Racional operator /(const Racional &r1, const Racional &r2);
		friend bool operator ==(const Racional &r1, const Racional &r2);
		friend bool operator !=(const Racional &r1, const Racional &r2);
};

#endif



