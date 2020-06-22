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
		bool cond;
		
	
	public:
		void cargarDatos();
		static Sistema * getInstance();
		ICollection * getEmpleados();
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
		bool check_mesa_menu(int);
		//Caso de uso Alta Producto
		
		bool check_prod_sistema(int);
		void agregarProducto(int,string,float);
		void agregarProdMenu(int,int);
		void agregarMenu(int,string);
		
		//Caso de uso Baja Producto
		
		void eliminarProducto(int);
		bool productoFacturado(int idprod);
		
		//Caso de uso  Agregar producto a una venta
		
		void ingresarMesa(int);
		ICollection * mostrarProductos();
		bool check_prod_venta(int);
		void agregarProductoVenta(int,int);
		void modificarCantidad(int,int,string);
		
		//Caso de uso Alta empleado

		int ingresarRepartidor(string,string);
		int ingresarMozo(string);
		ICollection * mostrarMozos();
		
		//Informacion de un producto
		DtProducto * mostrarProducto(int);  
		
		//Agrgar mesas a mozos
		
		bool check_mesa_mozo(int,int);
		void agregarMesaMozo(int idmesa, int idmozo);
		void asignarMesasAutomatico();
		int cantMesas();
		int cantMozos();
		bool mesaAsignada(Mesa*);
		Mozo * mozoVago();
		ICollection * getMesas();
		
		ICollection * getTodosPedidos(int);
		
		ICollection * getVentas();
		//Caso de uso Alta cliente
		
		void crearCliente(string,int,string,int);
		
		//Utilidades
		ICollection * getPedidosCliente(int);
		bool ventaFacturada(int);
		ICollection * mostrarClientes();
		
		//Quitar producto a una venta
		
		ICollection * mostrarProdVenta(int);
		
		//Facturacion de 1 dia
		
		ICollection * getFacturasFecha(DtFecha*);
		
		//Venta a domicilio
		
		bool check_cliente(int);
		void agregarVdomicilio(int repartidor);
		ICollection * mostrarRepartidores();
		DtFactura * crearVdomicilio(int repartidor,int telefono);
		void ingresarProducto(int, int);
		Repartidor * check_repartidor();
		ICollection * getPedidos(int);
		void cambiarEstado(int,int,int);
		
};
