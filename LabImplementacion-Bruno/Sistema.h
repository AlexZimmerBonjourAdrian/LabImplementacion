#include "./colecciones/ListDictionary.cpp"
#include "./iterators/ListDiterator.cpp"
#include "./clases/Mozo.cpp"
#include "./colecciones/List.cpp"
#include "./clases/Vlocal.cpp"
#include "./clases/Vdomicilio.cpp"
#include "./clases/Factura.cpp"
#include "./Datatypes/DtFactura.cpp"
#include "./Datatypes/DtFecha.cpp"
#include "./clases/Comun.cpp"
#include "./clases/Menu.cpp"
#include "./clases/Repartidor.cpp"
#include "./clases/Cliente.cpp"
#include "./Datatypes/DtMesa.cpp"
#include "./Datatypes/DtCliente.cpp"
#include "./Datatypes/DtVenta.cpp"
#include "./Datatypes/DtRepartidor.cpp"

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
    
    while(L != NULL) {
        cout<<"Mesa # "<<L->info<<endl;
        L = L->sig;
        
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
		IDictionary * clientes;
		Lista temp;
		Mozo * mozoVago();
		bool cond;
		
	
	public:
		//Instancia
		
		void cargarDatos();
		static Sistema * getInstance();
		
		//Informacion
		
		ICollection * getEmpleados();
		ICollection * getFacturas();
		ICollection * getMesas();
		ICollection * getVentas();
		ICollection * mostrarClientes();
		ICollection * mostrarProductos();
		ICollection * mostrarMozos();
		ICollection * mostrarProdVenta(int);
		ICollection * getPedidos(int);
		ICollection * getTodosPedidos(int);
		ICollection * getPedidosCliente(int);
		ICollection * getFacturasFecha(DtFecha*);
		ICollection * mostrarRepartidores();
		
		//Verificaciones
		
		bool check_prod_sistema(int);
		bool productoFacturado(int idprod);
		bool ventaFacturada(int);
		bool check_mesa_menu(int);
		bool check_prod_venta(int);
		bool mesaAsignada(Mesa*);
		bool check_cliente(int);
		
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
		
		void agregarProducto(int,string,float);
		void agregarProdMenu(int,int);
		void agregarMenu(int,string);
		
		//Caso de uso Baja Producto
		
		void eliminarProducto(int);
		
		
		//Caso de uso  Agregar producto a una venta
		
		void ingresarMesa(int);
		void agregarProductoVenta(int,int);
		void modificarCantidad(int,int,string);
		
		//Caso de uso Alta empleado

		int ingresarRepartidor(string,string);
		int ingresarMozo(string);
		
		
		//Informacion de un producto
		
		DtProducto * mostrarProducto(int);  
		
		//Agregar mesas a mozos
		
		void agregarMesaMozo(int idmesa, int idmozo);
		void asignarMesasAutomatico();
		int cantMesas();
		int cantMozos();

		
		//Caso de uso Alta cliente
		
		void crearCliente(string,int,string,int);
		
		//Venta a domicilio	
		
		DtFactura * crearVdomicilio(int repartidor,int telefono);
		void ingresarProducto(int, int);
		void cambiarEstado(int,int,int);

		
	
};
