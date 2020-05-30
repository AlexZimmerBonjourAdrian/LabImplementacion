#ifndef Enums_h
#define Enums_h
#include <iostream>
using namespace std;


//  TipoMascota  /////////////////////////////////////////////////////////////////
typedef short int TipoMascota;
const int CANT_TIPO_MASCOTA = 2;
const string eTipoMascota[CANT_TIPO_MASCOTA] = {	"perro", 
													"gato"};

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


//  SiNo  /////////////////////////////////////////////////////////////////
typedef short int SiONo;
const int CANT_SI_NO = 2;
const string eSiNo[CANT_SI_NO] = {	"no", 
									"si"};



//  Validadores de opciones  //////////////////////////////////////////////////////////////
int tipoMascotaValido(string);
int generoValido(string);
int tipoPeloValido(string);
int razaPerroValido(string);
int siNoValido(string);
string listaDeOpciones(const string[], int);
// devuelven el string correspondiente al parametro pasado
string strGenero(Genero);
string strTipoPelo(TipoPelo);
string strRazaPerro(RazaPerro);
string strSiNo(SiONo);

#endif
