#include "./colecciones/ListDictionary.cpp"
#include "./iterators/ListDiterator.cpp"
#include "./clases/Mozo.cpp"
#include "./colecciones/List.cpp"

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

class Sistema {
	private:
		static Sistema * instance;
		Sistema();
		IDictionary * mozos;
		
	
	public:
		static Sistema * getInstance();
		IDictionary * getMozos();
		//Caso de uso Iniciar venta en mesa
		Lista listarMesasAsignadas(int idmozo);
		int seleccionarMesas(int);
		void confirmarSeleccion(Lista);
};
