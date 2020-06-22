#include "Sistema.h"
#include <typeinfo>
#include<stdexcept>
#include<ctime>
typedef struct nodolista *Lista;

Sistema * Sistema::instance=NULL;

Sistema::Sistema() {

	empleados = new ListDictionary();
	ventas = new ListDictionary();
	mesas = new ListDictionary();
	productos = new ListDictionary();
	facturas = new ListDictionary;
	clientes = new ListDictionary();
	temp=NULL;
}

//Instancia
void Sistema::cargarDatos(){
	Mozo * m1 = new Mozo("Juan",new ListDictionary());
	IKey * k1 = new IntKey(m1->getId());
	
	empleados->add(k1,m1);
	
	Repartidor * r1 = new Repartidor("Daniel","A pie",new ListDictionary());
	IKey * k6 = new IntKey(r1->getId());
	
	empleados->add(k6,r1);
	
	DtDireccion * dd = new DtDireccion("Herrera", 154);
	
	Cliente * c = new Cliente(1,"Gustavo",dd);
	IKey * ck = new IntKey(1);
	
	clientes->add(ck,c);
	
	
	Comun * c1 = new Comun(1,"Papas",35);
	IKey * k2 = new IntKey(1);
	
	productos->add(k2,c1);

	Comun * c2 = new Comun(2,"Coca",55);
	IKey * k3 = new IntKey(2);
	
	productos->add(k3,c2);
	
	Comun * c3 = new Comun(3,"Milanesa",65);
	IKey * k4 = new IntKey(3);

	productos->add(k4,c3);

	Menu * men1 = new Menu(4,"Menu1",171);
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

//ALta cliente
void Sistema::crearCliente(string nombre, int telefono, string calle, int nro){
	IKey * k = new IntKey(telefono);
	DtDireccion * dt = new DtDireccion(calle,nro);
	Cliente * c = new Cliente(telefono,nombre,dt);
	clientes->add(k,c);
	
}

//Obtener datos del sistema

ICollection * Sistema::getEmpleados(){
	IIterator * it = empleados->getIterator();
	ICollection * de = new List();
	while(it->hasCurrent()){
		Empleado * e = (Empleado *) it->getCurrent();
		DtEmpleado * dt = e->getDatos();
		de->add(dt);
		it->next();
	}
	return de;
	
}

ICollection * Sistema::mostrarClientes(){
	ICollection *dtclientes= new List();
	IIterator * it = clientes->getIterator();
	while(it->hasCurrent()){
		Cliente * c = (Cliente*) it->getCurrent();
		DtCliente * dt = new DtCliente(c->getTelefono(),c->getNombre(),c->getDireccion());
		dtclientes->add(dt);
		it->next();
	}
	return dtclientes;
}

ICollection * Sistema::mostrarProductos(){
	
	IIterator * it = productos->getIterator();
	if(it->hasCurrent()){
		ICollection * dp = new List();
		while(it->hasCurrent()){
			Producto * p = (Producto *) it->getCurrent();
			dp->add(p->getDatos());	
			it->next();
		}
		//cout << "SALI" << endl;
		return dp;
		
	}
	return NULL;
}

ICollection * Sistema::getTodosPedidos(int idrep){
	
	IKey * k = new IntKey(idrep);
	Empleado *e = (Empleado *) this->empleados->find(k);
	Repartidor * r = dynamic_cast<Repartidor*>(e);
	if(r==NULL){
		throw "### NO SE ENCONTRO EL REPARTIDOR ###";
	}
	IDictionary * ventas = r->getVentas();
	IIterator * it = ventas->getIterator();
	if(!it->hasCurrent()){
		throw "### EL REPARTIDOR NO TIENE VENTAS INCOMPLETAS ###";
	}
	ICollection * dtventas = new List();
	while(it->hasCurrent()){
		Venta * v = (Venta *) it->getCurrent();
		DtVenta * dv = new DtVenta(v->getCodigo(),v->getProductos(),v->getFecha(),v->getEstado());
		dtventas->add(dv);
		it->next();
	}
	delete k, it;
	return dtventas;
	
}


ICollection * Sistema::mostrarProdVenta(int idmesa){
	IKey * k = new IntKey(idmesa);
	Mesa * m = (Mesa *) mesas->find(k);
	if(m!=NULL){
		Venta * v = m->getVenta();
		return v->getProductos();
	}
	else{
		delete k;
		throw "### NO SE ENCONTRO LA MESA ###";
	}
	delete k;
	
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

ICollection * Sistema::getFacturasFecha(DtFecha * fecha){
	
	IIterator * it = facturas->getIterator();
	ICollection * datos = new List();
	while(it->hasCurrent()){
		Factura * f = (Factura *)it->getCurrent();
		DtFecha * df = f->getFecha();
		if((df->getAnio()==fecha->getAnio()) && (df->getMes()==fecha->getMes()) && (df->getDia()==fecha->getDia())){
			DtFactura * df = f->getDatos();
			datos->add(df);
		}
	
		it->next();
	}
	return datos;
}


//Alta producto

void Sistema::agregarProdMenu(int codigo,int cantidad){
	InsertEnd(this->temp,codigo);
	InsertEnd(this->temp,cantidad);
	
}

void Sistema::agregarMenu(int codigo, string descripcion){
	Lista nodo = this->temp;
	Menu * m = new Menu(codigo,descripcion,0);
	float total=0;
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
		total = total + (c->getPrecio()*nodo->info);
		m->agregarProd(c,nodo->info);
		nodo=nodo->sig;
		delete k;
	}
	total = total - ((total*10)/100);
	m->setPrecio(total);
	IKey * k2 = new IntKey(codigo);
	this->productos->add(k2,m);
	
}

void Sistema::modificarCantidad(int idprod, int cantProd,string op){
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
	v->setNuevaCantidad(p,cantProd,op);
}


//Agregar datos al sistema

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





void Sistema::agregarProducto(int codigo,string descripcion,float precio){
	IKey * k = new IntKey(codigo);
	Comun * p = new Comun(codigo,descripcion,precio);
	productos->add(k,p);
}

//Iniciar venta en mesa

void Sistema::ingresarMesa(int idmesa){
	IKey * k = new IntKey(idmesa);
	Mesa * m = (Mesa *) mesas->find(k);
	if(m==NULL){
		throw "### NO SE ENCONTRO LA MESA ###";
	}
	
	Vlocal * v = m->getVenta();
	if(v==NULL){
		throw "### LA MESA NO TIENE VENTAS EN ESTE MOMENTO ###";
	}
	InsertEnd(this->temp,v->getCodigo());
	
	delete k;
}

Lista Sistema::listarMesasAsignadas(int idmozo){
	this->liberarMemoria();
	InsertEnd(this->temp,idmozo);
	IKey * k = new IntKey(idmozo);
	
	Empleado * e= (Empleado *) empleados->find(k);
	Mozo * mo = dynamic_cast<Mozo *>(e);
	if(mo==NULL){
		throw "### NO EXISTE EL MOZO EN EL SISTEMA ###";
	}
	else{
		Lista IDmesas = NULL;
		IDictionary * mes = mo->getMesa();
		IIterator * itmesas  = mes->getIterator();
		
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

Lista Sistema::listarMesasSeleccionadas(){
	Lista p=this->temp;
	return p->sig;
}

void Sistema::seleccionarMesas(int idmesa){
	IKey * k1 = new IntKey(idmesa);
	Mesa * m1=(Mesa *)this->mesas->find(k1);
	if(m1==NULL){
		delete k1;
		this->liberarMemoria();
		throw "### NO EXISTE LA MESA SELECCIONADA ###";
	}
	IKey * k2 = new IntKey(this->temp->info);
	Mozo * m2 =  dynamic_cast<Mozo*>(this->empleados->find(k2));
	if(m2==NULL){
		delete k1,k2;
		this->liberarMemoria();
		throw "### NO EXISTE EL MOZO SELECCIONADO ###";
	}
	if(!m2->check_mesa(m1) || m1->getVenta()!=NULL){
		delete k1,k2;
		this->liberarMemoria();
		throw "### LA MESA SELECCIONADA NO CORRESPONDE AL MOZO O YA TIENE UNA VENTA ###";
	}
	InsertEnd(this->temp,idmesa);
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
	
	Vlocal * venta = new Vlocal(new List(),fecha,"En curso",mozo);
	while(p!=NULL){
		IntKey * k = new IntKey(p->info);
		Mesa* m = (Mesa*) mesas->find(k);
		if(m!=NULL && m->getVenta()==NULL){
			m->setVenta(venta);
			
		}
		else{
			this->liberarMemoria();
			delete venta;
			throw "### ALGUNA DE LAS MESAS NO EXISTE O YA TIENE UNA VENTA EN CURSO ###"; 
		}
		p=p->sig;
		
	}
	
	
	IntKey * v = new IntKey(venta->getCodigo());
	
	this->ventas->add(v,venta);
}


bool Sistema::mesaAsignada(Mesa * m1){
	IIterator * it = empleados->getIterator();
	while(it->hasCurrent()){
		Empleado * e = (Empleado *)it->getCurrent();
		Mozo * r1 = dynamic_cast<Mozo*>(e);
		if(r1!=NULL){
			if(r1->check_mesa(m1)){
				return true;
			}
		}
		it->next();
	}
}

//Agregar meza a mozo

void Sistema::agregarMesaMozo(int idmesa, int idmozo){
	IKey * k1 = new IntKey(idmesa);
	IKey * k2 = new IntKey(idmozo);
	Mesa * m1 = (Mesa*) this->mesas->find(k1);
	Mozo * m2 = (Mozo*)this->empleados->find(k2);
	if(m1 == NULL || m2 == NULL){
		throw "### NO SE PUDO AGREGAR LA MESA ###";
	}
	if(this->mesaAsignada(m1)){
		throw "### LA MESA YA HA SIDO ASIGNADA ###";
	}

	m2->agregarMesa(m1);
	return;
	delete k1;
	delete k2;

	
	
}


ICollection * Sistema::getMesas(){
	IIterator * it = mesas->getIterator();
	if(!it->hasCurrent()){
		delete it;
		throw "### NO HAY MESAS EN EL SISTEMA ###";
	}
	ICollection * mes = new List();
	while(it->hasCurrent()){
		Mesa * m = (Mesa*)it->getCurrent();
		DtMesa * dm = new DtMesa(m->getid());
		mes->add(dm);
		it->next();
	}
	delete it;
	return mes;
}


//Baja producto

void Sistema::eliminarProducto(int idprod){
	IKey * k = new IntKey(idprod);
	Producto * p = (Producto*)productos->find(k);
	if(p==NULL){
		delete k;
		throw "### EL PRODUCTO NO EXISTE EN EL SISTEMA ###";
	}
	if(!this->productoFacturado(p->getCodigo())){
		throw "### NO SE PUEDE ELIMINAR UN PRODUCTO QUE NO HAYA SIDO COMPLETAMENTE FACTURADO ###";
	}
	IIterator * it = ventas->getIterator();
	while(it->hasCurrent()){
		
		Venta * v = (Venta *)it->getCurrent();

		if(v!=NULL)v->borrarProd(p);
		it->next();
	}
	delete it;
	it = productos->getIterator();

	if(p->getTipo()=="Comun"){	
		while(it->hasCurrent()){
			Producto * p2 = (Producto *) it->getCurrent();
			if(p2->getTipo()=="Menu" && p2!=p){
				Menu * m = (Menu *) p2;
				p2->borrar(p);
				if(m->vacio()){
					this->eliminarProducto(m->getCodigo());
				
				}
			} 
			
			it->next();
		}
		
	}
	productos->remove(k);
	delete p;

}

ICollection * Sistema::getVentas(){
	IIterator * it = ventas->getIterator();
	if(!it->hasCurrent()){
		delete it;
		throw "### NO EXISTEN VENTAS EN EL SISTEMA ###";
	}
	ICollection * dtventas = new List();
	while(it->hasCurrent()){
		Venta * v = (Venta *) it ->getCurrent();
		DtVenta * dv = new DtVenta(v->getCodigo(),v->getProductos(),v->getFecha(),v->getEstado());
		dtventas->add(dv);
		it->next();
	}
	delete it;
	return dtventas;
}


ICollection * Sistema::getPedidosCliente(int cliente){
	IKey * k = new IntKey(cliente);
	Cliente * c = (Cliente *)this->clientes->find(k);
	delete k;
	if(c==NULL){
		throw "### NO SE ENCONTRO EL CLIENTE ###";
	}
	IIterator * it = ventas->getIterator();
	if(!it->hasCurrent()){
		delete it;
		throw "### NO EXISTEN VENTAS EN EL SISTEMA ###";
	}
	ICollection * dtventas = new List();
	while(it->hasCurrent()){
		Venta * v = (Venta *) it ->getCurrent();
		Vdomicilio * vdom = dynamic_cast<Vdomicilio *>(v);
		if(vdom !=NULL && vdom->getCliente()==c){
			DtVenta * dv = new DtVenta(v->getCodigo(),v->getProductos(),v->getFecha(),v->getEstado());
			dtventas->add(dv);
		}
		
		it->next();
	}
	delete it;
	return dtventas;
	
	
}



int Sistema::cantMesas(){
	IIterator * it = mesas->getIterator();
	int mesas = 0;
	while(it->hasCurrent()){
		Mesa * m = (Mesa*)it->getCurrent();
		if(!this->mesaAsignada(m)){
			mesas++;	
		}
		
		it->next();
	}
	return mesas;
}

int Sistema::cantMozos(){
	IIterator * it = empleados->getIterator();
	int mozos = 0;
	while(it->hasCurrent()){
		Empleado * e = (Empleado*) it->getCurrent();
		Mozo * m = dynamic_cast<Mozo*>(e);
		if(m!=NULL){
			mozos++;	
		}
		
		it->next();
	}
	return mozos;
}



void Sistema::asignarMesasAutomatico(){
	IIterator * it = ventas->getIterator();
	while(it->hasCurrent()){
		Venta * venta = (Venta *) it->getCurrent();
		Vlocal * v = dynamic_cast<Vlocal *>(venta);
		if(v!=NULL){
			IKey * k = new IntKey(v->getCodigo());
			if(!this->facturas->member(k)){
				throw "### LAS VENTAS DEBEN ESTAR FACTURADAS ###";
			}	
		}
		it->next();
	}
	int mesas = this->cantMesas();
	int mozos=this->cantMozos();
	if(mesas==0 || mozos == 0){
		throw "### DEBEN HABER MOZOS Y MESAS DISPONIBLES";
	}
	delete it;

	IIterator * it2= this->mesas->getIterator();
	
	while(it2->hasCurrent()){
		Mesa * m2=(Mesa*)it2->getCurrent();
		if(!this->mesaAsignada(m2)){
			Mozo * m1 = this->mozoVago();
			m1->agregarMesa(m2);
		}
		
		it2->next();
			
	}
}

	

Mozo * Sistema::mozoVago(){
	IIterator * it = empleados->getIterator();
	bool pri=true;
	Mozo * vago=NULL;
	int menor=0;
	while(it->hasCurrent()){
		Empleado * e = (Empleado*) it->getCurrent();
		Mozo * m = dynamic_cast<Mozo*>(e);
		
		if(m!=NULL){
			int cant=m->cantMesas();
			
			if(pri){
				menor=cant;
				vago=m;
				pri=false;
			}
			if(cant<menor){
				menor=cant;
				vago=m;
			}
		}
		it->next();
	}
	return vago;
}

//Verificaciones

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

bool Sistema::productoFacturado(int idprod){
	
		IKey * k = new IntKey(idprod);
		Producto * p = (Producto*)this->productos->find(k);
		if(p==NULL){
			delete k;
			throw "### EL PRODUCTO NO EXISTE EN EL SISTEMA ###";
		}
		IIterator * it = ventas->getIterator();
		while(it->hasCurrent()){
			Venta * v = (Venta *) it->getCurrent();
			if(!this->ventaFacturada(v->getCodigo()) && v->buscarProd(p)){
				return false;
			}
			it->next();
		}
		return true;
	
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

bool Sistema::check_cliente(int telefono){
	IKey * k = new IntKey(telefono);
	bool ck;
	if(this->clientes->find(k)){
		ck=true;
	}
	else{
		ck=false;
	}
	return ck;
}


bool Sistema::check_mesa_menu(int idmesa){
	IKey * k = new IntKey(idmesa);
	Mesa * m = (Mesa*) this->mesas->find(k);
	if(m==NULL){
		delete k;
		throw "### NO SE ENCONTRO LA MESA ###";
	}
	Venta * v = m->getVenta();
	if(v==NULL){
		throw "### LA MESA NO TIENE VENTA ASIGNADA ###";
	}
	delete k;
	return v->tieneMenu();
}


//Facturacion de una venta

DtFactura * Sistema::emitirFactura(int idmesa, float descuento){
	IKey * k1 = new IntKey(idmesa);
	Mesa * m = (Mesa *) this->mesas->find(k1);
	if(m==NULL){
		throw "### LA MESA INGRESADA NO EXISTE ###";
	}
	Vlocal * v = m->getVenta();
	
	if(v==NULL){
		return NULL;
	}
	Mozo * mozo = v->getMozo(); 
	mozo->borrarMesas(v);
	m->setVenta(NULL);
	IKey * k3 = new IntKey(v->getCodigo());
	v->setEstado("Facturada");
	if(!facturas->member(k3)){
		if(v->tieneMenu()){
			descuento=0;
		}
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

//Agregar producto a una venta

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

//Informacion de un producto

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
		if((this->ventaFacturada(v->getCodigo()))){
			total = total + v->getCantidadProd(p);
		}
		
		it->next();
	}
	dp->setCantidad(total);
	return dp;
}


ICollection * Sistema::mostrarRepartidores(){
	IIterator * it = empleados->getIterator();
	ICollection * dtr = new List();
	while(it->hasCurrent()){
		Repartidor * r1 = dynamic_cast<Repartidor*>(it->getCurrent());
		if(r1!=NULL){
			DtEmpleado * dt = new DtRepartidor(r1->getId(),r1->getNombre(),r1->getMedio());
			dtr->add(dt);
		}
		it->next();
	}
	return dtr;
}

void Sistema::ingresarProducto(int idprod, int cant){
	if(!this->check_prod_sistema(idprod)){
		
		throw "### EL PRODUCTO INGRESADO NO EXISTE ###";
	}
	InsertEnd(this->temp,idprod);
	InsertEnd(this->temp,cant);
}


//	IKey * k2 = new IntKey(repartidor);
//	Empleado * e = (Empleado*)this->empleados->find(k2);
//	Repartidor * r = dynamic_cast<Repartidor*>(e);
//	if(r==NULL){
//		this->liberarMemoria();
//		throw "### NO SE ENCONTRO EL REPARTIDOR ###";
//	}


DtFactura * Sistema::crearVdomicilio(int repartidor, int telefono){
		IKey * k = new IntKey(telefono);
		Cliente * c = (Cliente*)this->clientes->find(k);
		if(c==NULL){
			this->liberarMemoria();
			throw "### NO EXISTE EL CLIENTE SELECCIONADO ###";
		}
		IKey * k2 = new IntKey(repartidor);
		Empleado * e = (Empleado*)this->empleados->find(k2);
		Repartidor * r = dynamic_cast<Repartidor*>(e);
		if(r==NULL){
			this->liberarMemoria();
			throw "### NO SE ENCONTRO EL REPARTIDOR ###";
		}
		int dia, mes, anio;  
		time_t tiempo = time (NULL);  
		struct tm *fecha = localtime (&tiempo); 
		dia=fecha->tm_mday;
		mes=fecha->tm_mon+1;
		anio= fecha->tm_year+1900;		
		DtFecha * fecha_actual = new DtFecha(anio,mes,dia);
		DtDireccion * dir = c->getDireccion();
		Venta * v = new Vdomicilio(new List(),fecha_actual,"Preparandose",dir,c->getNombre(),c->getTelefono(),r,c);
		IKey * k3 = new IntKey(v->getCodigo());
		Lista p = this->temp;
	
		while(p!=NULL && p->sig!=NULL){
			IKey * k4 = new IntKey(p->info);
			Producto * p1 = (Producto *) this->productos->find(k4);
			if(p1==NULL){
				this->liberarMemoria();
				throw "### NO SE ENCONTRO EL PRODUCTO ###";
			}
			
			p=p->sig;
			int cant = p->info;
			if(v->buscarProd(p1)){
				v->setNuevaCantidad(p1,cant,"suma");
			}
			else{
				v->agregarProd(p1,cant);	
			}
			p=p->sig;
			
		}
		
		Vdomicilio * vd = (Vdomicilio *) v;
		Factura * f = new Factura(vd,0);
		IKey * kf = new IntKey(v->getCodigo());
		this->facturas->add(kf,f);
		DtFactura * df = f->getDatos();
		this->ventas->add(k3,v);
		r->agregarVenta(v);
		return df;
}


void Sistema::cambiarEstado(int idventa, int opc, int rep){
	IKey * k = new IntKey(rep);
	Empleado *e = (Empleado *) this->empleados->find(k);
	Repartidor * r = dynamic_cast<Repartidor*>(e);
	delete k;
	if(r==NULL){
		throw "### NO SE ENCONTRO EL REPARTIDOR ###";
	}
	
	IKey * k2 = new IntKey(idventa);
	Venta * v =(Venta *) this->ventas->find(k2);
	Vdomicilio * v1 = dynamic_cast<Vdomicilio*>(v);
	delete k2;
	
	if(v1==NULL){
		throw "### NO SE ENCONTRO LA VENTA ###";
	}
	if(v1->esRepartidor(r)){
		if(opc==2){
			if(v->getEstado()=="En camino"){
				throw "### LA VENTA YA ESTA EN CAMINO ###";
			}
			if(v->getEstado()=="Entregada"){
				throw "### LA VENTA YA HA SIDO ENTREGADA ###";
			}
			v->setEstado("En camino");
			}
		if(opc==1){
			if(v->getEstado()=="Entregada"){
				throw "### LA VENTA YA HA SIDO ENTREGADA ###";
			}
			if(v->getEstado()=="Preparandose"){
				throw "### LA MESA AUN NO ESTA EN VIAJE ###";
			}
			v->setEstado("Entregada");
		}
	}
	else{
		throw "### LA VENTA INGRESADA NO CORRESPONDE AL REPARTIDOR SELECCIONADO ###";
	}
	
}


ICollection * Sistema::getPedidos(int idrep){
	IKey * k = new IntKey(idrep);
	Empleado *e = (Empleado *) this->empleados->find(k);
	Repartidor * r = dynamic_cast<Repartidor*>(e);
	if(r==NULL){
		throw "### NO SE ENCONTRO EL REPARTIDOR ###";
	}
	IDictionary * ventas = r->getVentas();
	IIterator * it = ventas->getIterator();
	if(!it->hasCurrent()){
		throw "### EL REPARTIDOR NO TIENE VENTAS INCOMPLETAS ###";
	}
	ICollection * dtventas = new List();
	while(it->hasCurrent()){
		Venta * v = (Venta *) it->getCurrent();
		if(v->getEstado()!="Entregada"){
			DtVenta * dv = new DtVenta(v->getCodigo(),v->getProductos(),v->getFecha(),v->getEstado());
			dtventas->add(dv);
		}
		
		it->next();
	}
	delete k, it;
	return dtventas;
	
	
}


//Alta empleado

int Sistema::ingresarMozo(string nombre){
	Mozo * m = new Mozo(nombre,new ListDictionary());
	IKey * k = new IntKey(m->getId());
	this->empleados->add(k,m);
	return m->getId();
}

int Sistema::ingresarRepartidor(string nombre, string mt){
	Repartidor * r = new Repartidor(nombre,mt,new ListDictionary());
	IKey * k = new IntKey(r->getId());
	this->empleados->add(k,r);
	return r->getId();
}



ICollection * Sistema::mostrarMozos(){
	IIterator * it = empleados->getIterator();
	ICollection * mozos = new List();
	while(it->hasCurrent()){
		Empleado * e = (Empleado*)it->getCurrent();
		Mozo * m = dynamic_cast<Mozo*>(e);
		if(m!=NULL){
			DtMozo * dm = new DtMozo(m->getId(),m->getNombre(),m->getDTMesa());
			mozos->add(dm);
		}
		it->next();
	}
	return mozos;
}

void Sistema::liberarMemoria(){
	eliminarLista(this->temp);
}


