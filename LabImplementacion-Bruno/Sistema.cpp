#include "Sistema.h"

typedef struct nodolista *Lista;

Sistema * Sistema::instance=NULL;

Sistema::Sistema() {

	empleados = new ListDictionary();
	ventas = new ListDictionary();
	mesas = new ListDictionary();
	productos = new ListDictionary();
	facturas = new ListDictionary;
	temp=NULL;
}

Sistema * Sistema::getInstance(){
	if(instance==NULL){
		instance = new Sistema(); 
	}
	return instance;
}

IDictionary * Sistema::getEmpleados(){
	return this->empleados;
}


void Sistema::agregarProdMenu(int codigo,int cantidad){
	InsertEnd(this->temp,codigo);
	InsertEnd(this->temp,cantidad);
	
}

void Sistema::agregarMenu(int codigo, string descripcion, float precio){
	
	Menu * m = new Menu(codigo,descripcion,precio);
	while(this->temp->sig!=NULL){
		IKey * k = new IntKey(this->temp->info);
		Comun * p = (Comun*)this->productos->find(k);
		if(p==NULL){
			delete k;
			throw "(Sistema)No se encontro el producto";
		}
		m->agregarProd(p,this->temp->sig->info);
		this->temp=this->temp->sig;
		delete k;
	}
	IKey * k2 = new IntKey(codigo);
	this->productos->add(k2,m);
	
}

void Sistema::agregarProducto(int codigo,string descripcion,float precio){
	IKey * k = new IntKey(codigo);
	Comun * p = new Comun(codigo,descripcion,precio);
	productos->add(k,p);
}

Lista Sistema::listarMesasAsignadas(int idmozo){
	
	InsertEnd(this->temp,idmozo);
	IKey * k = new IntKey(idmozo);
	
	Mozo * mo= (Mozo*) empleados->find(k);
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
		else{
			while(itmesas->hasCurrent()){
			ICollectible * i = itmesas->getCurrent();
			Mesa * m = (Mesa *) i;
			InsertEnd(IDmesas,m->getid());
			itmesas->next();
			}
		}
		return IDmesas;
	}
	
	
	
}

void Sistema::agregarMozo(Mozo * m){
	IKey * k = new IntKey(m->getId());
	this->empleados->add(k,m);
}

void Sistema::agregarMesa(int idmesa){
	IKey * k = new IntKey(idmesa);
	if(this->mesas->member(k)){
		delete k;
		throw "(Sistema)Existe una mesa con ese codigo";
	}
	Mesa * m = new Mesa(idmesa,new ListDictionary());
	this->mesas->add(k,m);
}

bool Sistema::check_prod_sistema(int idprod){
	IKey * k = new IntKey(idprod);
	if(this->productos->member(k)){
		return true;
	}
	else{
		delete k;
		return false;
	}
}

void Sistema::seleccionarMesas(int idmesa){
	InsertEnd(this->temp,idmesa);
}

void Sistema::agregarMesaMozo(int idmesa, int idmozo){
	IKey * k1 = new IntKey(idmesa);
	IKey * k2 = new IntKey(idmozo);
	Mesa * m1 = (Mesa*) this->mesas->find(k1);
	Mozo * m2 = (Mozo*)this->empleados->find(k2);
	if(m1 != NULL && m2 != NULL){
		m2->agregarMesa(m1);
		return;
	}
	delete k1;
	delete k2;
	throw "No se pudo agregar la mesa";
	
	
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
	Mozo * mozo = (Mozo *)this->empleados->find(mozo_k);
	if(mozo==NULL){
		throw "No existe el mozo en el sistema";
	}
	Vlocal * venta = new Vlocal(new List(),fecha,mozo);
	while(p!=NULL){
		IntKey * k = new IntKey(p->info);
		Mesa* m = (Mesa*) mesas->find(k);
		if(m!=NULL){
			m->setVenta(venta);
			
		}
		p=p->sig;
		
	}
	
	
	IntKey * v = new IntKey(venta->getCodigo());
	
	this->ventas->add(v,venta);
}

DtFactura * Sistema::emitirFactura(int idmesa, float descuento){
	IKey * k1 = new IntKey(idmesa);
	Mesa * m = (Mesa *) this->mesas->find(k1);
	Vlocal * v = m->getVenta();
	Factura * f = new Factura(v,descuento);
	IKey * k2 = new IntKey(f->getCodigo());
	this->facturas->add(k2,f);
	DtFactura * df = f->getDatos();
	delete k1;
	return df;
}

void Sistema::ingresarMesa(int idmesa){
	IKey * k = new IntKey(idmesa);
	Mesa * m = (Mesa *) mesas->find(k);
	if(m!=NULL){
		Vlocal * v = m->getVenta();
		InsertEnd(this->temp,v->getCodigo());
	}
	delete k;
}

ICollection * Sistema::mostrarProductos(){
	if(productos!=NULL){
		IIterator * it = productos->getIterator();
		ICollection * dp = new List();
		while(it->hasCurrent()){
			Producto * p = (Producto *) it->getCurrent();
			dp->add(p->getDatos());	
			it->next();
		}
		return dp;
		
	}
}


bool Sistema::check_prod_venta(int idprod){
	int idventa = this->temp->info;
	IKey * k2 = new IntKey(idventa);
	Vlocal * v = (Vlocal*)this->ventas->find(k2);
	if(v==NULL){
		throw "(Sistema) La venta no existe en el sistema";
	}
	delete k2;
	IKey * k1 = new IntKey(idprod);
	Producto * p = (Producto *)productos->find(k1);
	delete k1;
	if(p==NULL){
		throw "(Sistema) El producto no existe en el sistema";
	}
	
	return v->buscarProd(p);
}

void Sistema::agregarProductoVenta(int idprod,int cantProd){
	int idventa = this->temp->info;
	IKey * k2 = new IntKey(idventa);
	Vlocal * v = (Vlocal*)this->ventas->find(k2);
	if(v==NULL){
		throw "(Sistema) La venta no existe en el sistema";
	}
	delete k2;
	IKey * k1 = new IntKey(idprod);
	Producto * p = (Producto *)productos->find(k1);
	delete k1;
	if(p==NULL){
		throw "(Sistema) El producto no existe en el sistema";
	}
	v->agregarProd(p,cantProd);
}





void Sistema::modificarCantidad(int idprod, int cantProd){
	int idventa = this->temp->info;
	IKey * k2 = new IntKey(idventa);
	Vlocal * v = (Vlocal *)this->ventas->find(k2);
	if(v==NULL){
		throw "(Sistema) La venta no existe en el sistema";
	}
	delete k2;
	IKey * k1 = new IntKey(idprod);
	Producto * p = (Producto *)productos->find(k1);
	delete k1;
	if(p==NULL){
		throw "(Sistema) El producto no existe en el sistema";
	}
	v->setNuevaCantidad(p,cantProd);
}


ICollection * Sistema::getFacturas(){
	
	IIterator * it = facturas->getIterator();
	ICollection * datos = new List();
	while(it->hasCurrent()){
		Factura * f = (Factura *)it->getCurrent();
		DtFactura * df = f->getDatos();
		datos->add(df);
		it->next();
	}
	return datos;
}

void Sistema::ingresarMozo(string nombre){
	Mozo * m = new Mozo(nombre,new ListDictionary());
	IKey * k = new IntKey(m->getId());
	this->empleados->add(k,m);
}

void Sistema::ingresarRepartidor(string nombre, string mt){
	Repartidor * r = new Repartidor(nombre,mt,new ListDictionary());
	IKey * k = new IntKey(r->getId());
	this->empleados->add(k,r);
}

void Sistema::liberarMemoria(){
	eliminarLista(this->temp);
}


