#ifndef Enums_h
#define Enums_h
#include <iostream>
using namespace std;

//  Genero  /////////////////////////////////////////////////////////////////
typedef short int Genero;
const int CANT_GENERO = 2;
const string eGenero[CANT_GENERO] = {	"macho", 
										"hembra"};

//  TipoPelo  ///////////////////////////////////////////////////////////////
typedef short int TipoPelo;
const int CANT_TIPO_PELO = 3;
const string eTipoPelo[CANT_TIPO_PELO] = {	"corto", 
											"mediano", 
											"largo" };

//  RazaPerro  //////////////////////////////////////////////////////////////
typedef short int RazaPerro;
const int CANT_RAZA_PERRO = 6;
const string eRazaPerro[CANT_RAZA_PERRO] = {	"labrador", 
												"ovejero", 
												"bulldog", 
												"collie", 
												"pekines", 
												"otros"};

//  funciones  //////////////////////////////////////////////////////////////
int generoValido(string);
int tipoPeloValido(string);
int razaPerroValido(string);
string listaDeOpciones(const string[], int);


#endif
