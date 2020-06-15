#include "./colecciones/ListDictionary.cpp"
#include "./iterators/ListDiterator.cpp"
#include "./clases/Mozo.cpp"
#include "./colecciones/List.cpp"
#include "./clases/Vlocal.cpp"
#include "./clases/Factura.cpp"
#include "./Datatypes/DtFactura.cpp"
#include "./Datatypes/DtFecha.cpp"
#include "./clases/Comun.cpp"
#include "./clases/Menu.cpp"
#include "./clases/Repartidor.cpp"
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

class Sistema {
	private:
		static Sistema * instance;
		Sistema();
		IDictionary * empleados;
		IDictionary * ventas;
		IDictionary * mesas;
		IDictionary * productos;
		IDictionary * facturas;
		Lista temp;
		bool cond;
		
	
	public:
		static Sistema * getInstance();
		IDictionary * getEmpleados();
		ICollection * getFacturas();
		
		//Caso de uso Iniciar venta en mesa
		
		void agregarMozo(Mozo * m);
		void agregarMesa(int);
	
		Lista listarMesasAsignadas(int idmozo);
		Lista listarMesasSeleccionadas();
		void seleccionarMesas(int);
		void confirmarSeleccion(Lista, DtFecha *);
		void liberarMemoria();
		
		//Caso de uso Facturacion de una venta
		
		DtFactura * emitirFactura(int, float);
		
		//Caso de uso Alta Producto
		
		bool check_prod_sistema(int);
		void agregarProducto(int,string,float);
		void agregarProdMenu(int,int);
		void agregarMenu(int,string,float);
		
		//Caso de uso  Agregar producto a una venta
		
		void ingresarMesa(int);
		ICollection * mostrarProductos();
		bool check_prod_venta(int);
		void agregarProductoVenta(int,int);
		void modificarCantidad(int,int);
		
		//Caso de uso Alta empleado
		
		void cargarDatos();
		
		
		void ingresarRepartidor(string,string);
		void ingresarMozo(string);
		
		//Agrgar mesas a mozos
		
		void agregarMesaMozo(int idmesa, int idmozo);
		
};
