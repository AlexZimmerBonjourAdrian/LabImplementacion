#include "Sistema.h"


typedef struct nodolista *Lista;

Sistema * Sistema::instance=NULL;

Sistema::Sistema() {

	mozos = new ListDictionary();
}

Sistema * Sistema::getInstance(){
	if(instance==NULL){
		instance = new Sistema(); 
	}
	return instance;
}

IDictionary * Sistema::getMozos(){
	return this->mozos;
}

Lista Sistema::listarMesasAsignadas(int idmozo){
	IKey * k = new IntKey(idmozo);
	Mozo * mo= (Mozo*) mozos->find(k);
	if(mo==NULL){
		throw "No existe el mozo";
	}
	else{
		Lista IDmesas = NULL;
		IDictionary * mesas = mo->getMesa();
		IIterator * itmesas  = mesas->getIterator();
		if(itmesas->hasCurrent()==false){
			throw "El mozo no tiene mesas asignadas";
		}
		while(itmesas->hasCurrent()){
			ICollectible * i = itmesas->getCurrent();
			Mesa * m = (Mesa *) i;
			InsertEnd(IDmesas,m->getid());
			itmesas->next();
		}
		
		return IDmesas;
	}
	
	
	
}

int Sistema::seleccionarMesas(int idmesa){
	return idmesa;
}

void Sistema::confirmarSeleccion(Lista L){
	
}
