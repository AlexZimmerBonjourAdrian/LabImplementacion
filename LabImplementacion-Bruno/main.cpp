#include "Sistema.cpp"
#include<iostream>
#include<stdio.h>
#include "./clases/Producto.cpp"
#include "./clases/Vlocal.cpp"
#include "./clases/Repartidor.cpp"
#include "./clases/Vdomicilio.cpp"
#include "./Datatypes/DtDireccion.cpp"
#include "./clases/Cliente.cpp"
#include "./clases/Factura.cpp"
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
	bool agregar = false;
	try{
		Sistema * s = Sistema::getInstance();
		Mozo * m1 = new Mozo(1,"juan",new ListDictionary());
		Vlocal * v1 = new Vlocal(new List(),m1);
		Mesa * me1 = new Mesa(1,new ListDictionary());
		s->agregarMozo(m1);
		m1->agregarMesa(me1);
		s->agregarMesa(me1);
		int id=1;
		
		
		//Iniciar Venta en mesa
		
		
		cout << "Ingrese el id del mozo" << endl;
		cin >> id;
		mostrarLista(s->listarMesasAsignadas(id));
		cout << "Seleccione en que mesas iniciar la venta. Para terminar ingrese 0" << endl;
		while(id!=0){
			cin >> id;
			if(id!=0)s->seleccionarMesas(id);
			
		}
		Lista selec = s->listarMesasSeleccionadas();
		mostrarLista(selec);
		cout << "Ingrese 1 para confirmar o 0 para cancelar" << endl;
		cin >>id;
		if(id==0){
			s->liberarMemoria();
			cout << "No se inicio la venta" << endl;
		}
		else{
			s->confirmarSeleccion(selec);
			s->liberarMemoria();
			cout << "Se inicio la venta" << endl;
		}
		
		//Facturacion de una venta
		
		
		
		
	}catch(const char * msg){
		cout << msg << endl;
	}
	
	

	system("PAUSE");
}
