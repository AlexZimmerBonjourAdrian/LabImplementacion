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
	try{
		Repartidor * r1 = new Repartidor(1,"Juan","moto",new ListDictionary());
		DtDireccion * d1 = new DtDireccion("Herrera", 233);
		Cliente * c1 = new Cliente("098765213","Arturo",d1);
		Vdomicilio * v1 =new Vdomicilio(1,new List(),d1,"Arturo","121212",r1,c1);
		Factura * f1 = new Factura(1,"2019-12-01",new List(),221,12,209);
		
	}catch(const char* msg){
		cout << msg << endl;
	}



	system("PAUSE");
}
