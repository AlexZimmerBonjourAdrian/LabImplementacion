#include "Sistema.h"
#include <typeinfo>
#include<stdexcept>
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

	
void Sistema::cargarDatos(){
	Mozo * m1 = new Mozo("Juan",new ListDictionary());
	IKey * k1 = new IntKey(m1->getId());
	
	empleados->add(k1,m1);
	
	Comun * c1 = new Comun(1,"Papas",35);
	IKey * k2 = new IntKey(1);
	
	productos->add(k2,c1);

	Comun * c2 = new Comun(2,"Coca",55);
	IKey * k3 = new IntKey(2);
	
	productos->add(k3,c2);
	
	Comun * c3 = new Comun(3,"Milanesa",65);
	IKey * k4 = new IntKey(3);

	productos->add(k4,c3);

	Menu * men1 = new Menu(4,"Menu1",100);
	IKey * k5 = new IntKey(4);

	men1->agregarProd(c1,2);
	men1->agregarProd(c2,1);
	men1->agregarProd(c3,1);
	
	productos->add(k5,men1);
	
	Mesa * mesa1 = new Mesa(1,new ListDictionary());
	IKey * mk1 = new IntKey(1);
	Mesa * mesa2 = new Mesa(2,new ListDictionary());
	IKey * mk2 = new IntKey(2);
	Mesa * mesa3 = new Mesa(3,new ListDictionary());
	IKey * mk3 = new IntKey(3);
	
	mesas->add(mk1,mesa1);
	mesas->add(mk2,mesa2);
	mesas->add(mk3,mesa3);
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
	Lista nodo = this->temp;
	Menu * m = new Menu(codigo,descripcion,precio);
	while(nodo!=NULL && nodo->sig!=NULL){
		
		int cod = nodo->info;
		IKey * k = new IntKey(cod);
		Producto * p = (Producto*)this->productos->find(k);
		if(p==NULL){
			delete k;
			throw "### EL PRODUCTO NO EXISTE EN EL SISTEMA ###";
		}
		if(p->getTipo()=="Menu"){
			delete k;
			throw "### NO SE PUEDE AGREGAR UN MENU DENTRO DE UN MENU ###";
		}
		Comun * c = (Comun*) p;
		nodo=nodo->sig;
		m->agregarProd(c,nodo->info);
		nodo=nodo->sig;
		delete k;
	}
	IKey * k2 = new IntKey(codigo);
	this->productos->add(k2,m);
	
}

bool Sistema::ventaFacturada(int idventa){
	IKey * k = new IntKey(idventa);
	if(facturas->member(k)){
		delete k;
		return true;
	}
	else{
		delete k;
		return false;
	}
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
		throw "### NO EXISTE EL MOZO EN EL SISTEMA ###";
	}
	else{
		Lista IDmesas = NULL;
		IDictionary * mesas = mo->getMesa();
		IIterator * itmesas  = mesas->getIterator();
		if(itmesas->hasCurrent()==false){
			throw "### EL MOZO NO TIENE MESAS ASIGNADAS ###";
		}
		else{
			while(itmesas->hasCurrent()){
			ICollectible * i = itmesas->getCurrent();
			Mesa * m = (Mesa *) i;
			if(m->getVenta()==NULL){
				InsertEnd(IDmesas,m->getid());
			}
		
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
		throw "### YA EXISTE UNA MESA CON ESE CODIGO ###";
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
	throw "### NO SE PUDO AGREGAR LA MESA ###";
	
	
}

Lista Sistema::listarMesasSeleccionadas(){
	Lista p=this->temp;
	return p->sig;
}

void Sistema::confirmarSeleccion(Lista L, DtFecha * fecha){
	Lista p;
	if(this->temp==NULL){
		return;
	}
	p = this->temp->sig;
	IKey * mozo_k = new IntKey(temp->info);
	Mozo * mozo = (Mozo *)this->empleados->find(mozo_k);
	if(mozo==NULL){
		this->liberarMemoria();
		throw "### NO EXISTE EL MOZO EN EL SISTEMA ###";
	}
	
	Vlocal * venta = new Vlocal(new List(),fecha,mozo);
	while(p!=NULL){
		IntKey * k = new IntKey(p->info);
		Mesa* m = (Mesa*) mesas->find(k);
		if(m!=NULL && m->getVenta()==NULL){
			m->setVenta(venta);
			
		}
		else{
			this->liberarMemoria();
			throw "### LA MESA NO EXISTE O YA TIENE UNA VENTA EN CURSO ###"; 
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
	m->setVenta(NULL);
	if(v==NULL){
		return NULL;
	}
	Mozo * mozo = v->getMozo();

	mozo->borrarMesas(v);
	
	IKey * k3 = new IntKey(v->getCodigo());
	
	if(!facturas->member(k3)){
		
		Factura * f = new Factura(v,descuento);
		IKey * k2 = new IntKey(f->getCodigo());
		
		this->facturas->add(k2,f);
		DtFactura * df = f->getDatos();
		delete k1;
		return df;
	}
	
	delete k3,k1;
	return NULL;

	
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
		throw "### LA VENTA NO EXISTE EN EL SISTEMA ###";
	}
	delete k2;
	IKey * k1 = new IntKey(idprod);
	Producto * p = (Producto *)productos->find(k1);
	delete k1;
	if(p==NULL){
		throw "### EL PRODUCTO NO EXISTE EN EL SISTEMA ###";
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
		throw "### EL PRODUCTO NO EXISTE EN EL SISTEMA ###";
	}
	v->agregarProd(p,cantProd);
}

DtProducto * Sistema::mostrarProducto(int cod){
	IKey * k = new IntKey(cod);
	Producto * p = (Producto*)this->productos->find(k);
	if(p==NULL){
		throw "### NO SE ENCONTRO EL PRODUCTO EN EL SISTEMA ###";
	}
	DtProducto * dp =  p->getDatos();
	IIterator * it = this->ventas->getIterator();
	int total=0;
	while(it->hasCurrent()){
		Venta * v = (Venta *) it->getCurrent();
		total = total + v->getCantidadProd(p);
		it->next();
	}
	dp->setCantidad(total);
	return dp;
}



void Sistema::modificarCantidad(int idprod, int cantProd){
	int idventa = this->temp->info;
	IKey * k2 = new IntKey(idventa);
	Vlocal * v = (Vlocal *)this->ventas->find(k2);
	if(v==NULL){
		throw "### LA VENTA NO EXISTE EN EL SISTEMA ###";
	}
	delete k2;
	IKey * k1 = new IntKey(idprod);
	Producto * p = (Producto *)productos->find(k1);
	delete k1;
	if(p==NULL){
		throw "### EL PRODUCTO NO EXISTE EN EL SISTEMA ###";
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


