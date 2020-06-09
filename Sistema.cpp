#include "Sistema.h"

Sistema* Sistema::instancia = NULL;

Sistema* Sistema::getInstancia()
{
	if(instancia == NULL){
		instancia = new Sistema();
	}
	return instancia;
}

ColMozos* Sistema::getMozos(){
	return this->mozos;
}
