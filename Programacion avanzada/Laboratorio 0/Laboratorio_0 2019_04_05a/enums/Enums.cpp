#include "Enums.h"


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


string listaDeOpciones(const string arr[], int cantElem){
	string str = "";
	for (int i = 0; i < cantElem; i++){
		str += arr[i];
		if (i+1<cantElem)	str += ", ";
	}
	return str;
}



