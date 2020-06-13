#include "Sistema.h"

typedef struct nodolista *Lista;

Sistema * Sistema::instance=NULL;

Sistema::Sistema() {

	mozos = new ListDictionary();
	VentasLocales = new ListDictionary();
	mesas = new ListDictionary();
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
	
	InsertEnd(this->temp,idmozo);
	IKey * k = new IntKey(idmozo);
	Mozo * mo= (Mozo*) mozos->find(k);
	if(mo==NULL){
		throw "No existe el mozo en el sistema";
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

void Sistema::agregarMozo(Mozo * m){
	IKey * k = new IntKey(m->getId());
	this->mozos->add(k,m);
}

void Sistema::agregarMesa(Mesa * m){
	IKey * k = new IntKey(m->getid());
	this->mesas->add(k,m);
}

void Sistema::seleccionarMesas(int idmesa){
	InsertEnd(this->temp,idmesa);
}

Lista Sistema::listarMesasSeleccionadas(){
	Lista p=this->temp;
	p=temp->sig;
	return p;
}

void Sistema::confirmarSeleccion(Lista L, DtFecha * fecha){
	Lista p;
	p= this->temp->sig;
	IKey * mozo_k = new IntKey(temp->info);
	Mozo * mozo = (Mozo *)this->mozos->find(mozo_k);
	if(mozo==NULL){
		throw "No existe el mozo en el sistema";
	}
	Vlocal * venta = new Vlocal(new List(),fecha,mozo);
	while(p!=NULL){
		IntKey * k = new IntKey(p->info);
		Mesa* m = (Mesa*) mesas->find(k);
		if(m!=NULL)m->setVenta(venta);
		p=p->sig;
		
	}
	
	
	IntKey * v = new IntKey(venta->getCodigo());
	
	this->VentasLocales->add(v,venta);
}

DtFactura * Sistema::emitirFactura(int idmesa, float descuento){
	IKey * k = new IntKey(idmesa);
	Mesa * m = (Mesa *) this->mesas->find(k);
	Vlocal * v = m->getVenta();
	Factura * f = new Factura(v->getFecha(),v->getProductos(),v->getSubtotal(),descuento,v->getMontototal());
}

void Sistema::liberarMemoria(){
	eliminarLista(this->temp);
}


