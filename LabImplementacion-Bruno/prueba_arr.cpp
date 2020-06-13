#include<iostream>

using namespace std;


struct nodolista{
    int info;
    struct nodolista*sig;
};

typedef struct nodolista *Lista;

void InsertEnd(Lista &L,int valor) {
    Lista t,q = new nodolista;
    q->info = valor;
    q->sig = NULL;
    if(L == NULL) {
        L = q;
    } else {
        t = L;
        while(t->sig != NULL) {
            t = t->sig;
        }
        t->sig = q;
    }
}

void mostrarLista(Lista L) {
    int i = 0;
    while(L != NULL) {
        cout<<i+1<<")"<<L->info<<endl;
        L = L->sig;
        i++;
    }
}

void eliminarLista(Lista &L){
	if(L==NULL)return;
	if(L->sig==NULL){
		delete L;
		L=NULL;
		return;
	}
	eliminarLista(L->sig);
	L=NULL;
}


main(){
	
	Lista L=NULL;
	InsertEnd(L,1);
	InsertEnd(L,1);
	InsertEnd(L,1);
	InsertEnd(L,1);
	InsertEnd(L,1);
	InsertEnd(L,1);
	InsertEnd(L,1);
	eliminarLista(L);
	mostrarLista(L);
	if(L==NULL){
		cout << "LALALAL" << endl;
	}
	
	
	
}
