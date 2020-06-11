#ifndef SISTEMA_H
#define SISTEMA_H
#include "./colecciones/ListDictionary.cpp"
#include "./iterators/ListDiterator.cpp"
#include "./clases/Mozo.cpp"
#include "./colecciones/List.cpp"
#include "./structure/Producto.h"
//#include "./structure/Producto.h"

#pragma region class operations
class Producto;
class DtProducto;

#pragma endregion

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
        ICollection * Productos;
        IDictionary * ProductosDictionary;
		
	
	public:
		static Sistema * getInstance();
       
		#pragma region Productos Operaciones del sistema
            ICollection * getProducto();
            ICollection * ListarProductos();
         IDictionary selecionaproducto(int codigoP,int cantidad);
        void agregarProducto(Producto *);
        #pragma endregion
		int seleccionarMesas(int);
        IDictionary * getMozos();
		//Caso de uso Iniciar venta en mesa
		Lista listarMesasAsignadas(int idmozo);
       // List listarProductos();
     
		void confirmarSeleccion(Lista);
};

#endif
