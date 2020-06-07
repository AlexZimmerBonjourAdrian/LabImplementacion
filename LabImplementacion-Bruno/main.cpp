#include "Sistema.cpp"
#include "./colecciones/List.cpp"
#include<iostream>
#include<stdio.h>

using namespace std;

main(){
	Mesa * mesa1 = new Mesa(1);
	Mesa * mesa2 = new Mesa(2);
	Mesa * mesa3 = new Mesa(3);

	Mozo * m1 = new Mozo(1, new List());
	m1->agregarMesa(mesa1);
	m1->agregarMesa(mesa2);
	m1->agregarMesa(mesa3);
	ColMozos * mozos = new ColMozos(new List());
	mozos->add(m1);
	MozoIterator * it = mozos->getIterator();
	while(it->hasCurrent()){
		ICollectible * i = it->getCurrent();
		Mozo * m = (Mozo *) i;
		cout << m->getidmozo() << endl;
		ICollection * mesasMozo=m->getMesa();
		IIterator * itm =mesasMozo->getIterator();
		cout << "MESAS" << endl;
		while(itm->hasCurrent()){
			ICollectible * mesa = itm->getCurrent();
			Mesa * me = (Mesa *) mesa;
			cout << me->getid() << endl; 
			itm->next();
		}
		
		it->next();
	}

	system("PAUSE");
}
