#include "Sistema.cpp"
#include<iostream>
#include<stdio.h>

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
		Mesa * mesa1 = new Mesa(1);
		Mesa * mesa2 = new Mesa(2);
		Mesa * mesa3 = new Mesa(3);
		Sistema * s = Sistema::getInstance();
		IDictionary * mozos = s->getMozos();
		Mozo * m1 = new Mozo(1, new ListDictionary());
		Mozo * m2 = new Mozo(2, new ListDictionary());
		Mozo * m3 = new Mozo(3, new ListDictionary());
		m1->agregarMesa(mesa1);
		m1->agregarMesa(mesa2);
		//m2->agregarMesa(mesa3);
		IKey * key = new IntKey(1);
		IKey * key2 = new IntKey(2);
		mozos->add(key,m1);
		mozos->add(key2,m2);
		//mostrarLista(s->listarMesasAsignadas(1));
		if(verificarMesaAtendida(s,mesa3)){
			cout << "LA MESA ESTA ATENDIDA" << endl;
		}
		else cout << "LA MESA NO ESTA ATENDIDA" << endl;
	//	bool agregar = true;
	//	Lista mesasselec = NULL;
	//	while(agregar){
	//		
	//		int idmesa = 0;
	//		cout << "Ingrese la mesa" << endl;
	//		cin >> idmesa;
	//		InsertEnd(mesasselec,s->seleccionarMesas(idmesa));
	//		cout << "¿Desea seguir agregando?" << endl;
	//		cin >> idmesa;
	//		if(idmesa!=1){
	//			mostrarLista(mesasselec);
	//			break;
	//		}
	//	}
	//	try{
	//		while(it->hasCurrent()){
	//			ICollectible * i = it->getCurrent();
	//			Mozo * m = (Mozo *) i;
	//			cout << m->getidmozo() << endl;
	//			ICollection * mesasMozo=m->getMesa();
	//			IIterator * itm =mesasMozo->getIterator();
	//			cout << "MESAS" << endl;
	//			while(itm->hasCurrent()){
	//				ICollectible * mesa = itm->getCurrent();
	//				Mesa * me = (Mesa *) mesa;
	//				cout << me->getid() << endl; 
	//				itm->next();
	//			}
	//			it->next();
	//	}
	//	ICollectible * i = it->getCurrent();
	//	Mozo *m = (Mozo*) i;
	//	cout << m->getidmozo() << endl;
	//	}catch(const char* msg){
	//		cout << msg << endl;
	//	}
	}catch(const char* msg){
		cout << msg << endl;
	}



	system("PAUSE");
}
