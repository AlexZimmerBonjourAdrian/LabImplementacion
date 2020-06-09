#include "Sistema.cpp"
#include<iostream>
#include<stdio.h>

using namespace std;
 
bool verificarMesaAtendida(Sistema * s, Mesa * m){
	ColMozos * mozos= s->getMozos();
	MozoIterator * it = mozos->getIterator();
	while(it->hasCurrent()){
		Mozo * mo = it->getCurrent();
		ICollection * mesas = mo->getMesa();
		IIterator * itme = mesas->getIterator();
		while(itme->hasCurrent()){
			ICollectible * i = itme->getCurrent();
			Mesa * m2 = (Mesa *) i;
			if(m==m2) return true;
			itme->next();
		} 
	it->next();
	}
	return false;
}


main(){
	Mesa * mesa1 = new Mesa(1);
	Mesa * mesa2 = new Mesa(2);
	Mesa * mesa3 = new Mesa(3);
	Sistema * s = Sistema::getInstance();
	ColMozos * mozos = s->getMozos();
	Mozo * m1 = new Mozo(1, new List());
	Mozo * m2 = new Mozo(2, new List());
	Mozo * m3 = new Mozo(3, new List());
	ICollection * mesasMozo=m1->getMesa();
	m1->agregarMesa(mesa1);
	m1->agregarMesa(mesa2);
	m1->agregarMesa(mesa3);
	mozos->add(m1);
	  if(verificarMesaAtendida(s,mesa1)){
		cout << "Esta atendida" << endl;
	}
	else cout << "No esta atendida" << endl;
	//mozos->add(m2);
	mostrarLista(s->listarMesasAsignadas(1));
	bool agregar = true;
	Lista mesasselec = NULL;
	while(agregar){
		
		int idmesa = 0;
		cout << "Ingrese la mesa" << endl;
		cin >> idmesa;
		InsertEnd(mesasselec,s->seleccionarMesas(idmesa));
		cout << "¿Desea seguir agregando?" << endl;
		cin >> idmesa;
		if(idmesa!=1){
			mostrarLista(mesasselec);
			break;
		}
	}
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


	system("PAUSE");
}
