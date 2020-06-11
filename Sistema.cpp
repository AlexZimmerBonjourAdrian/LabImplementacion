#include "Sistema.h"



typedef struct nodolista *Lista;

Sistema * Sistema::instance=NULL;

Sistema::Sistema() {

#pragma no funciona debido a que se crea el diccionario cada vez que se se nesesite en ves de taerlo
	mozos = new ListDictionary();
	#pragma endregion
	Productos = new ListIterator();
	ProductosDictionary= new ListDictionary();

	//this->Productos=NULL;
}

Sistema * Sistema::getInstance(){
	if(instance==NULL){
		instance = new Sistema(); 
	}
	return instance;
}

ICollection * Sistema::getProducto()
{
	return this->Productos;
}

ICollection * Sistema::listarProductos()
{

	IIterator * it = Productos->getIterator();
	ICollection * res = new Lista();
	
	while (it->hasCurrent())
	{
		DtProducto * p = dynamic_cast<DtProducto*>(it->getCurrent());
		IIterator *it2;
		for (it2 = c->getIterator();it2->hasCurrent();it2->next)	
		{
		 res->add(it2->getCurrent());
		}
		delete it2;
	}
	delete it;
}

DtProducto * Sistema::selecionaproducto(int codigoP,int cantidad)
{
	IKey * k = new IntKey(codigoP);
	Producto * proD = dynamic_cast<Producto*>ProductosDictionary->find(k);
	//ICollection * res= new ICollection; 
	res->add(proD);
	delete k;
	return proD->getDatos();	
	//	for (int i = 0; i <= cantidad; i++)
//	{
	
	//}
}

DtProducto * Sistema::agregarProducto(Producto * Producto)
{
	this->Productos->add(new IKey(Producto->getCodigo()),Producto);
}


#pragma region estas son las opraciones de mozos  y los casos de uso afiiados a estas dos clases
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
#pragma endregion
void Sistema::confirmarSeleccion(Lista L){
	
}
