#include "Sistema.cpp"
#include<iostream>
#include<stdio.h>
#include "./clases/Producto.cpp"
#include "./clases/Vlocal.cpp"
using namespace std;
 
bool verificarMesaAtendida(Sistema * s, Mesa * m){
	IDictionary * mozos= s->getMozos();
	IIterator * it = mozos->getIterator();
	IKey * k = new IntKey(m->getid());
	while(it->hasCurrent()){
		Mozo * mo =(Mozo *) it->getCurrent();
		IDictionary * mesas = mo->getMesa();
		if(mesas->member(k)){
			return true;
		}
		it->next();
	}
	delete k;
	return false;
}


main(){
	try{
		Sistema * s = Sistema::getInstance();
		
		Mesa * mesa1 = new Mesa(1);
		Mesa * mesa2 = new Mesa(2);
		Mesa * mesa3 = new Mesa(3);
		
		IDictionary * mozos = s->getMozos();
		Mozo * m1 = new Mozo(1, new ListDictionary());
		Mozo * m2 = new Mozo(2, new ListDictionary());
		Mozo * m3 = new Mozo(3, new ListDictionary());
	
		m1->agregarMesa(mesa1);
		m1->agregarMesa(mesa2);
		m2->agregarMesa(mesa3);
		IKey * key = new IntKey(1)
		;
		IKey * key2 = new IntKey(2);
		mozos->add(key,m1);
		mozos->add(key2,m2);
		
		Producto * p1 = new Producto(1,"cerveza",150);
		Producto * p2 = new Producto(2,"milanesa",120);
		Producto * p3 = new Producto(3,"fritas",95);
		
		Vlocal * v1= new Vlocal(1,new List(),new ListDictionary());
		v1->agregarProd(p1,1);
		v1->agregarProd(p2,2);
		
		ICollection * prods = v1->getCantidades();
		IIterator * it = prods->getIterator();
	
		while(it->hasCurrent()){
			CantidadProd * c = (CantidadProd *) it->getCurrent();
			Producto * p = c->getProducto();
			DtProducto d = p->getDatos();
			cout << d.getDescripcion() << "     " << d.getPrecio() << endl;
			it->next();
		}
		
	}catch(const char* msg){
		cout << msg << endl;
	}



	system("PAUSE");
}
