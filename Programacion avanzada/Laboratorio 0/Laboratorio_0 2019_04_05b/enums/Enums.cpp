#include "Enums.h"

//  Validadores de opciones  //////////////////////////////////////////////////////////////
int tipoMascotaValido(string s){
	for (int i = 0; i < CANT_TIPO_MASCOTA; i++){
		if (eTipoMascota[i] == s)	return i;
	}
	return -1;
}


int generoValido(string s){
	for (int i = 0; i < CANT_GENERO; i++){
		if (eGenero[i] == s)	return i;
	}
	return -1;
}


int tipoPeloValido(string s){
	for (int i = 0; i < CANT_TIPO_PELO; i++){
		if (eTipoPelo[i] == s)	return i;
	}
	return -1;
}


int razaPerroValido(string s){
	for (int i = 0; i < CANT_RAZA_PERRO; i++){
		if (eRazaPerro[i] == s)	return i;
	}
	return -1;
}


int siNoValido(string s){
	for (int i = 0; i < CANT_SI_NO; i++){
		if (eSiNo[i] == s)	return i;
	}
	return -1;
}


string listaDeOpciones(const string arr[], int cantElem){
	string str = "";
	for (int i = 0; i < cantElem; i++){
		str += arr[i];
		if (i+1<cantElem)	str += ", ";
	}
	return str;
}

// devuelven el string correspondiente al parametro pasado
string strTipoMascota(TipoMascota n){
	if (n < 0 || n >= CANT_TIPO_MASCOTA)	return "";
	return eTipoMascota[n];
}


string strGenero(Genero n){
	if (n < 0 || n >= CANT_GENERO)	return "";
	return eGenero[n];
}


string strTipoPelo(TipoPelo n){
	if (n < 0 || n >= CANT_TIPO_PELO)	return "";
	return eTipoPelo[n];
}


string strRazaPerro(RazaPerro n){
	if (n < 0 || n >= CANT_RAZA_PERRO)	return "";
	return eRazaPerro[n];
}


string strSiNo(SiONo n){
	if (n < 0 || n >= CANT_SI_NO)	return "";
	return eSiNo[n];
}










