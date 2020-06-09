#include "Sistema.h"


typedef struct nodolista *Lista;

Sistema * Sistema::instance=NULL;

Sistema::Sistema() {

	mozos = new ColMozos(new List());
}

Sistema * Sistema::getInstance(){
	if(instance==NULL){
		instance = new Sistema(); 
	}
	return instance;
}

ColMozos * Sistema::getMozos(){
	return this->mozos;
}

Lista Sistema::listarMesasAsignadas(int idmozo){
	Sistema * s =Sistema::getInstance();
	ColMozos * mozos= s->getMozos();
	MozoIterator * it = mozos->getIterator();
	while(it->hasCurrent()){
		Mozo * mo = it->getCurrent();
		if(idmozo==mo->getidmozo()){
			Lista IDmesas = NULL;
			ICollection * mesas = mo->getMesa();
			IIterator * itmesas  = mesas->getIterator();
			while(itmesas->hasCurrent()){
				ICollectible * i = itmesas->getCurrent();
				Mesa * m = (Mesa *) i;
				InsertEnd(IDmesas,m->getid());
				itmesas->next();
			}
			return IDmesas;
		}
		else{
			it->next();
		}
	}
	
	
}

int Sistema::seleccionarMesas(int idmesa){
	return idmesa;
}

void Sistema::confirmarSeleccion(Lista L){
	
}
