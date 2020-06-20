#include "Sistema.cpp"
#include<iostream>
#include<stdio.h>
#include "./clases/Producto.cpp"
#include "./clases/Repartidor.cpp"
#include "./clases/Vdomicilio.cpp"
#include "./Datatypes/DtDireccion.cpp"
#include "./clases/Cliente.cpp"
#include <windows.h>
#include <typeinfo>
#include<ctime>

using namespace std;
 
bool verificarMesaAtendida(Sistema * s, Mesa * m){
	IDictionary * mozos= s->getEmpleados();
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

int menu();
int menuMozo();
int menuAdministrador();
int menuCliente();
int menuRepartidor();
int menuConsultas();



main(){
	int agregar = 1;
	float precio=0;
	
		string opc1,s1;
		Sistema * s = Sistema::getInstance();
		Mesa * me1 = new Mesa(1,new ListDictionary());
		int id=1, descuento;
		int opc;
		int mozopc;
		bool back = false;
		do{
			back=false;
			system("cls");
			opc = menu();
			switch(opc){
				case 1:
					do{
						try{
						
						system("cls");
						opc = menuAdministrador();
						switch(opc){
							case 1:{
								cout << endl << "### ALTA PRODUCTO ###" << endl << endl;
							
								cout << endl << "\t..DESEA AGREGAR UN PRODUCTO COMUN O UN MENU?" << endl;
								cin >> opc1;
								if(opc1=="comun"){
									cout << endl << "\t..Ingrese el codigo ";
									cin >> agregar;
									if(!cin.good()){
										cout << endl << "### EL CODIGO SOLO PUEDE SER NUMERICO ###" << endl;
										system("PAUSE");
										cin.clear();
										fflush(stdin);
										break;
									}
									if(s->check_prod_sistema(agregar)){
										cout << endl << endl << "\t..Ya existe un producto con ese codigo" << endl;
										system("PAUSE");
										break;
									}
									cout << endl << endl <<"\t..Ingrese la descripcion ";
									cin>>s1;
									cout << endl << endl << "\t..Ingrese el precio ";
									cin >> precio;
									if(!cin.good()){
										cout << endl << "### EL CODIGO SOLO PUEDE SER NUMERICO ###" << endl;
										system("PAUSE");
										cin.clear();
										fflush(stdin);
										break;
									}
									cout << endl << endl << "\t..Desea confirmar el alta?(si o no)";
									cin >> opc1;
									if(opc1=="si"){
										s->agregarProducto(agregar,s1,precio);
										cout << endl << "### SE HA AGREGADO EL PRODUCTO ###"<< endl;
										s->liberarMemoria();
									}
									else{
										s->liberarMemoria();
									}
									
								}
								else{
									if(opc1=="menu"){
										
										cout << endl << "\t..Ingrese el codigo ";
										cin >> agregar;
										if(!cin.good()){
											cout << endl << "### EL CODIGO SOLO PUEDE SER NUMERICO ###" << endl;
											system("PAUSE");
											cin.clear();
											fflush(stdin);
											break;
										}
										if(s->check_prod_sistema(agregar)){
											cout << endl << endl << "\t..Ya existe un producto con ese codigo" << endl;
											system("PAUSE");
											break;
										}
										cout << endl << endl <<"\t..Ingrese la descripcion ";
										cin>>s1;
										cout << endl << endl << "\t..Ingrese el precio ";
										cin >> precio;
										cout << endl << endl;
										ICollection * p = s->mostrarProductos();
										if(p==NULL){
											cout << "### NO HAY PRODUCTOS EN EL SISTEMA ###" << endl;
											Sleep(2000);
											break;
										}
										IIterator * it = p->getIterator();
										
										int count=0;
										while(it->hasCurrent()){
											DtProducto * dp = (DtProducto *) it->getCurrent();
											if(dp->getTipo()=="Comun"){
												count++;
												cout <<count <<") " << dp->getCodigo() << "  " << dp->getDescripcion() << "  " << dp->getPrecio() << endl;
											}
											it->next();
										
										}
										cout << endl << endl << "\t..Ingrese los componentes del menu (para finalizar escriba 0) " << endl;
										int cod;
										bool check;
										
										do{
											cout << endl << "\t..Ingrese el codigo ";
											cin >> cod;
											if(cod!=0)check=s->check_prod_sistema(cod);
											if(!cin.good()){
												cout << "### EL CODIGO SOLO PUEDE SER NUMERICO ###" << endl;
												cin.clear();
     											cin.ignore();
											}
											if(cod!=0 && !(check)){
												cout << endl << endl << "\t..No existe un producto con ese codigo" << endl;
												break;
											}
											if(cod!=0){
												cout <<  endl <<"\t..Ingrese la cantidad ";
												int cant;
												cin >>cant;
												s->agregarProdMenu(cod,cant);
											}
										
										}while(cod!=0);
										if(check){
												
											cout << endl << endl << "\t..Desea confirmar el alta? ";
											cin >> opc1;
											if(opc1=="si"){
												s->agregarMenu(agregar,s1,precio);
												cout << endl << "### SE HA AGREGADO EL PRODUCTO ###"<< endl;
											}
											else{
												cout << endl << "### NO SE HA AGREGADO EL MENU ###" << endl; 
											}
											s->liberarMemoria();
										}
											
										}
										else{
											cout << "### OPCION INCORRECTA ###" << endl;
											system("PAUSE");
											s->liberarMemoria();
											break;
										}
								
									s->liberarMemoria();
									
								}
								system("PAUSE");
								break;
							}
							case 2:{
							
								cout <<"### BAJA PRODUCTO ###" <<endl;
								cout << endl << "\t..Seleccione el producto a eliminar de la lista" << endl << endl ;
									
								ICollection * p = s->mostrarProductos();
								if(p==NULL){
									cout << "### NO HAY PRODUCTOS EN EL SISTEMA ###" << endl;
									Sleep(2000);
									break;
								}
								IIterator * it = p->getIterator();
								
								while(it->hasCurrent()){
									DtProducto * dp = (DtProducto *) it->getCurrent();
									cout  << "\tProducto # "<< dp->getCodigo() << "  " << dp->getDescripcion() << "  " << dp->getPrecio() << endl;
									it->next();
								
								}
								int idprod=0;
								cin >> idprod;
								bool check;
								check=s->check_prod_sistema(idprod);
								if(!check){
									cout << "### NO EXISTE UN PRODUCTO CON ESE CODIGO ###" << endl;
									system("PAUSE");
									break;
								}
								cout << endl << "\t..Ingrese 1 para confirmar o 0 para cancelar" << endl;
								cin >> opc;
								if(opc==1){
									s->eliminarProducto(idprod);
									s->liberarMemoria();
									cout << endl << "### SE HA ELIMINADO EL PRODUCTO ###" << endl;
								}
								else{
									s->liberarMemoria();
									cout << endl << "### NO SE HA ELIMINADO EL PRODUCTO ###" << endl;
								}
								system("PAUSE");
								break;
							}
							case 3:{
						
								cout << endl << "### INFORMACION DE UN PRODUCTO ###" <<endl << endl;
								cout << "\tIngrese el codigo del producto (Si desea volver ingrese 0) ";
								
								int cod=1;
								bool ch=false;
								do{
									cin >> cod;
									if(cod==0){
										ch=false;
										break;
									}
									ch=s->check_prod_sistema(cod);
									if(ch==false){
										cout << endl << endl << "###  CODIGO INCORRECTO ###" << endl;
										cout << endl << "\tIngrese el codigo del producto nuevamente (Si desea cancelar ingrese 0) ";
									}
									
								}while(ch==false && cod!=0);
								DtProducto * dp = s->mostrarProducto(cod);
								if(ch==true){
									DtProducto * dp = s->mostrarProducto(cod);
									cout << endl << "### PRODUCTO ###" << endl << endl;
									cout << "\tCodigo: " << dp->getCodigo() << endl;
									cout << "\tDescripcion: " << dp->getDescripcion() << endl;
									cout << "\tPrecio: " << dp->getPrecio() << endl;
									cout << "\tCantidad de unidades vendidas: " <<dp->getCantidad() << endl;
								}
								if(dp->getTipo()=="Menu"){
									cout << endl << "### COMPONENTES ###" << endl << endl;
									DtMenu * dm = (DtMenu*) dp;
									ICollection * componentes= dm->getComponentes();
									IIterator * it = componentes->getIterator();
									while(it->hasCurrent()){
										DtProducto * dp = (DtProducto*) it->getCurrent();
										cout << "\tCodigo: " << dp->getCodigo() << endl;
										cout << "\tDescripcion: " << dp->getDescripcion() << endl;
										cout << "\tPrecio: " << dp->getPrecio() << endl;
										cout << "\tCantidad: " <<dp->getCantidad() << endl << endl;
										it->next();
									}
								}
								system("PAUSE");
								break;
						}
							case 4:{
								cout << endl << "### INGRESAR EMPLEADO ###" << endl << endl << "\t..Ingrese el nombre: " ;
								string nombre;
								cin >>nombre;
								cout << "\t..El empleado es repartidor?(si/no)" << endl << endl;
								cin >> opc1;
								if(opc1 != "si" && opc1!="no"){
									cout << "### OPCION INCORRECTA ###" << endl;
									break;
								}
								if(opc1=="si"){
										cout << "\t..Seleccione un medio de transporte" << endl << endl;
										cout << "\t\t1)..A pie" << endl;
										cout << "\t\t2)..Bicicleta" << endl;
										cout << "\t\t3)..Moto" << endl;
										int op;
										cin >>op;
										bool m=true;
										string mt;
										switch(op){
											case 1:
												mt="A pie";
												break;
											case 2:
												mt="Bicicleta";
												break;
											case 3:
												mt="Moto";
												break;
											default:
												cout << "### OPCION INCORRECTA ###" << endl;
												m=false;
												break;
												
										}
										if(m){
											s->ingresarRepartidor(nombre,mt);
											cout << "###EL EMPLEADO HA SIDO DADO DE ALTA###" << endl; 
										}
								}
								else{
									s->ingresarMozo(nombre);
									cout << "###EL EMPLEADO HA SIDO DADO DE ALTA###" << endl; 
								}
	
								Sleep (2000);
								break;
							}
							
							case 5:{
							
								cout <<"### ALTA CLIENTE ###" <<endl << endl;
								cout << "\t..Ingrese el nombre: ";
								string nombre;
								fflush(stdin);
								getline(cin, nombre);
								cout << endl << endl << "\t..Ingrese el telefono: ";
								long int telefono;
								cin >> telefono;
								cout << endl << endl << "\t..Ingrese la calle: ";
								string calle;
								fflush(stdin);
								getline(cin,calle);
								cout << endl << endl << "\t..Ingrese el numero: ";
								int nro;
								cin >> nro;
								cout << endl << endl << "\t..Desea confirmar el alta?(1 o 0)" << endl;
								cin >> opc;
								if(opc==1){
									s->crearCliente(nombre,telefono,calle,nro);
									
								}
								else{
									cout << endl << "### NO SE CREO EL CLIENTE ###" << endl;
									Sleep (2000);
								}
								
								break;
							}
							case 6:{
							
								cout << "### FACTURACION DE UN DIA ###" << endl;
								cout << endl << "\t..Ingrese la fecha a consultar:" << endl;
								cout << endl << "\t..Anio: ";
								int anio;
								cin>>anio;
								cout << endl << "\t..Mes: ";
								int mes;
								cin >> mes;
								cout << endl << "\t..Dia: ";
								int dia;
								cin >> dia;
								DtFecha * f = new DtFecha(anio,mes,dia);
								ICollection * facturas = s->getFacturasFecha(f);
								IIterator * it = facturas->getIterator();
								while(it->hasCurrent()){
									DtFactura * df =(DtFactura *) it->getCurrent();
									cout << endl <<"##Factura " << df->getCodigo() << " ##" << endl << "Subtotal: " << df->getSubtotal() << endl << " Descuento: "<< df->getDescuento()<< endl << endl;
									cout << "\t --Productos--" << endl << endl;
									ICollection * prod = df->getProductos();
									IIterator * it_p = prod->getIterator();
									while(it_p->hasCurrent()){
										DtProducto * dp = (DtProducto *) it_p->getCurrent();
										cout << "\t ..Codigo: " << dp->getCodigo() << endl;
										cout << "\t ..Nombre del Producto: " << dp->getDescripcion() << endl;
										cout << "\t ..Precio: " << dp->getPrecio() << endl;
										cout << endl << endl;
										it_p->next();
									}
									it->next();
								}
								system("PAUSE");
								Sleep (2000);
								break;
							}
							case 7:
								cout <<"Venta a domicilio no implementado" <<endl;
								Sleep (2000);
								break;
							case 8:
								cout <<"Consultar actualizaciones de pedidos a domicilio no implementado" <<endl;
								Sleep (2000);
								break;
								
							case 9:{
								try{
									cout << endl << "### Alta mesa ###" << endl << endl;
									cout << "\t..Ingrese el id  de la mesa" << endl;
									cin >> id;
									s->agregarMesa(id);
									cout << endl << "### Mesa creada ###" << endl;
									Sleep(2000);
									break;
								}catch(char const * msg){
										cout << msg << endl;
								}
								system("PAUSE");
								break;
							}	
							
							case 10:{
								
									cout << endl << "### Agregar mesa a un mozo ###" << endl;
									cout << endl << "\t..Ingrese el id del mozo" << endl;
									cin >> id;
									cout << endl << "\t..Ingrese la mesa a agregar" << endl;
									cin >> descuento;
									s->agregarMesaMozo(descuento,id);
									cout << endl << "### LA MESA SE A AGREGADO AL MOZO ###" << endl;
									s->liberarMemoria();
									system("PAUSE");
									break;	
								
								
							}
							
							case 11:
								back=true;
								break;
							default:
								cout << "Opcion incorrecta" << endl;
								Sleep (2000);
								system("cls");
						}	
						
					}catch(char const * msg){
						cout << msg << endl;
						system("PAUSE");
					}	
				}while((opc<12 || opc>0) && !back);
					break;
				case 2:{
						do{
							try{
							system("cls");
							opc = menuMozo();
							switch(opc){
								case 1:{
									cout << "###INICIAR VENTA EN MESA###" << endl << endl;
									
									cout << "\t..Ingrese el id del mozo" << endl << endl;
									cin >> id;
									Lista mesas=s->listarMesasAsignadas(id);
									cout << endl << endl << "### MESAS ASIGNADAS A ESTE MOZO ###" << endl << endl;
									mostrarLista(mesas); 
									cout << endl << "\t..Seleccione en que mesas iniciar la venta. Para terminar ingrese 0" << endl;
									while(id!=0){
										cin >> id;
										
										if(id!=0)s->seleccionarMesas(id);
										
									}
									cout << "\t..Las mesas seleccionadas son:" << endl << endl;
									Lista selec = s->listarMesasSeleccionadas();
									mostrarLista(selec);
									cout << endl << "\t..Ingrese 1 para confirmar o 0 para cancelar" << endl;
									cin >>id;
									if(id==0){
										s->liberarMemoria();
										cout << endl << "\t..No se inicio la venta" << endl;
									}
									else{
											
										int dia, mes, anio;  
										time_t tiempo = time (NULL);  
										struct tm *fecha = localtime (&tiempo); 
										dia=fecha->tm_mday;
										mes=fecha->tm_mon+1;
										anio= fecha->tm_year+1900;								
										s->confirmarSeleccion(selec,new DtFecha(anio,mes,dia));
										s->liberarMemoria();
										cout << endl << "### Se inicio la venta ###" << endl;
									}	
									Sleep (2000);
									break;
								}
								
								case 2:{
										//Agregar Producto a una venta
									cout << "### INGRESAR PRODUCTO A UNA VENTA ###" << endl;
									ICollection * p = s->mostrarProductos();
									if(p==NULL){
										cout << "### NO EXISTEN PRODUCTOS EN EL SISTEMA ###";
										break;
									}
									cout << endl << "\t..Ingrese la mesa a agregar" << endl;
									cin>>opc;
									s->ingresarMesa(opc);
									cout << "\t..Seleccione los productos de la lista disponible" << endl << endl ;
									
									
									IIterator * it = p->getIterator();
									int count=0;
									while(it->hasCurrent()){
										count++;
										DtProducto * dp = (DtProducto *) it->getCurrent();
										cout << count << ") "<< dp->getCodigo() << "  " << dp->getDescripcion() << "  " << dp->getPrecio() << endl;
										it->next();
									
									}
									cout << "\t..Ingrese 0 para detenerse" << endl << endl;
									cin >> id;
									do{
										
										cout << "\t..Ingrese la cantidad" << endl;
										int cant = 0;
										cin >> cant;
										bool ch = s->check_prod_venta(id);
										
										cout << "\t..Desea confirmar?(1 , 0)" << endl;
										cin >> agregar;
										if(agregar==1){
											if(ch==true){
												s->modificarCantidad(id,cant,"suma");
											}
											
											else{
												s->agregarProductoVenta(id,cant);
											}
											
											Sleep(2000);
											
										}
										else{
											cout << "### PRODUCTO NO AGREGADO ###" << endl;	
										}
										cin >> id;
								
									}while(id!=0);
									s->liberarMemoria();
									break;
								}
									
								case 3:{
								
									cout << endl << "### QUITAR PRODUCTO A UNA VENTA ### "<<endl;
									cout << endl << "\t..Ingrese la mesa a quitar" << endl;
									cin>>opc;
									s->ingresarMesa(opc);
									cout << "\t..Seleccione el producto de la lista disponible" << endl << endl ;
									ICollection * p = s->mostrarProdVenta(opc);
									IIterator * it = p->getIterator();
									while(it->hasCurrent()){
										DtProducto * dp = (DtProducto *) it->getCurrent();
										cout << dp->getCodigo() << "  " << dp->getDescripcion() << "  " << dp->getPrecio() << endl;
										it->next();
									
									}
									cin >> id;
								
									cout << "\t..Ingrese la cantidad" << endl;
									int cant = 0;
									cin >> cant;
									bool ch = s->check_prod_venta(id);
									
									cout << "\t..Desea confirmar?(1 , 0)" << endl;
									cin >> agregar;
									if(agregar==1){
										if(ch==true){
											s->modificarCantidad(id,cant,"resta");
										}
										
										else{
											cout << "### EL PRODUCTO SELECCIONADO NO SE ENCUENTRA EN LA VENTA ###" << endl;
										}
										
										Sleep(2000);
										
									}
									
							
									break;
								}
								case 4:{
									cout << endl << "### EMITIR FACTURA ###" << endl;
									cout << endl << "\t..Ingrese la mesa a facturar" << endl;
									cin >> id;
									cout << endl << "\t..Ingrese el descuento a aplicar" << endl;
									cin >> descuento;
									DtFactura * df = s->emitirFactura(id,descuento);
									if(df!=NULL){
										cout << endl << "### SE CREO LA FACTURA CON LOS SIGUIENTES DATOS: ###" << endl << endl;
											cout << endl << "##Factura " << df->getCodigo() << " ##" << endl << endl << "\t..Subtotal: " << df->getSubtotal() << endl << "\t..Descuento: "<< df->getDescuento()<< endl << endl;
											cout << "\t --Productos--" << endl << endl;
											ICollection * prod = df->getProductos();
											IIterator * it_p = prod->getIterator();
											while(it_p->hasCurrent()){
												DtProducto * dp = (DtProducto *) it_p->getCurrent();
												cout << "\t ..Codigo: " << dp->getCodigo() << endl;
												cout << "\t ..Nombre del Producto: " << dp->getDescripcion() << endl;
												cout << "\t ..Precio: " << dp->getPrecio() << endl;
												cout << "\t ..Cantidad: " << dp->getCantidad() << endl;
												cout << endl << endl;
												it_p->next();
										
										}
									}
									else{
										cout << endl << "### LA MESA NO TIENE UNA VENTA EN CURSO O YA HA SIDO FACTURADA ###" << endl;
									}
									system("Pause");
									break;
								}
									
								
									
								case 5:
									back=true;
									break;
								default:
									cout << "Opcion incorrecta" << endl;
									Sleep (2000);
									system("cls");
							}
						}catch(char const * msg){
							cout << msg << endl;
							system("PAUSE");
						}		
					}while((opc<6 || opc>0) && !back);
					
					break; 
				}
				case 3:
					do{
						system("cls");
						opc = menuRepartidor();
						switch(opc){
							case 1:
								cout <<"Modificar estado pedido no implementada" <<endl;
								Sleep (2000);
								break;
							case 2:
								back=true;
								break;
							default:
								cout << "Opcion incorrecta" << endl;
								Sleep (2000);
								system("cls");
						}		
					}while((opc<3 || opc>0) && !back);
					break;
				case 4:
					do{
						system("cls");
						opc = menuCliente();
						switch(opc){
							case 1:
								cout <<"Consultar actualizaciones de pedidos a domicilio no implementada" <<endl;
								Sleep (2000);
								break;
							case 2:
								back=true;
								break;
							default:
								cout << "Opcion incorrecta" << endl;
								Sleep (2000);
								system("cls");
						}		
					}while((opc<3 || opc>0) && !back);
					break;
				case 5:
					s->cargarDatos();
				
					break;
				
				case 6:{
					do{
						system("cls");
						opc = menuConsultas();
						switch(opc){
							case 1:{
								ICollection * facturas = s->getFacturas();
								IIterator * it = facturas->getIterator();
								while(it->hasCurrent()){
									DtFactura * df =(DtFactura *) it->getCurrent();
									cout << "##Factura " << df->getCodigo() << " ##" << endl << endl << "Subtotal: " << df->getSubtotal() << endl << "Descuento: "<< df->getDescuento()<< endl;
									DtFecha * dtf = df->getFecha();
									cout << "Fecha: " << dtf->getAnio() << "-" << dtf->getMes() << "-" << dtf->getDia() << endl << endl; 
									cout << "\t --Productos--" << endl << endl;
									ICollection * prod = df->getProductos();
									IIterator * it_p = prod->getIterator();
									while(it_p->hasCurrent()){
										DtProducto * dp = (DtProducto *) it_p->getCurrent();
										cout << "\t ..Codigo: " << dp->getCodigo() << endl;
										cout << "\t ..Nombre del Producto: " << dp->getDescripcion() << endl;
										cout << "\t ..Precio: " << dp->getPrecio() << endl;
										cout << endl << endl;
										it_p->next();
									}
									it->next();
								}
								system("PAUSE");
								break;
							}
														
							case 2:{
								cout << "### EMPLEADOS ###" << endl << endl;
								IDictionary * emp = s->getEmpleados();
								IIterator * it = emp->getIterator();
								while(it->hasCurrent()){
									Empleado * e = (Empleado *) it->getCurrent();
									cout << "\t..Codigo: " << e->getId() << endl;
									cout << "\t..Nombre: " << e->getNombre() << endl;
									cout << "\t..Tipo: ";
									
									Repartidor * r1 = dynamic_cast<Repartidor*>(e);
									if(r1==NULL){
										cout << "Mozo" << endl;
									}
									else{
										cout << "Repartidor" << endl;
									}
									cout << endl << endl;
									it->next();
								}
								system("Pause");
								break;
							}
								
							case 3:{
								break;
							}
								
							case 4:{
								cout << "### Productos ###" << endl << endl;
								ICollection * prod = s->mostrarProductos();
								if(prod==NULL){
									cout << endl << "### NO HAY PRODUCTOS EN EL SISTEMA ###" << endl;
									Sleep(2000);
									break;
								}
								IIterator * it_p = prod->getIterator();
								while(it_p->hasCurrent()){
									DtProducto * dp = (DtProducto *) it_p->getCurrent();
									cout << "\t ..Codigo: " << dp->getCodigo() << endl;
									cout << "\t ..Nombre del Producto: " << dp->getDescripcion() << endl;
									cout << "\t ..Precio: " << dp->getPrecio() << endl;
									cout << endl << endl;	
									it_p->next();
								}
								system("PAUSE");
								break;
							}
							
							
							case 5:{
								cout << endl <<  "### Clientes ###" << endl;
								ICollection * clientes = s->mostrarClientes();
								IIterator * it = clientes->getIterator();
								while(it->hasCurrent()){
									DtCliente * dc = (DtCliente *) it->getCurrent();
									cout << endl << "\t..Telefono: " << dc->getTelefono() << endl;
									cout << "\t..Nombre: " << dc->getNombre() << endl;
									DtDireccion * dd = dc->getDireccion();
									cout << "\t..Direccion: " << dd->getCalle() << "  " << dd->getNro() << endl << endl;
									cout << "          -------------------------" << endl;
									it->next();
									
								}
								system("PAUSE");
								break;
							}
							
							case 6:{
								back=true;
								break;
							}
							
							default:{
								cout << "Opcion incorrecta" << endl;
								Sleep (2000);
								system("cls");
								break;
							}
							
						}		
					}while((opc<7 || opc>0) && !back);
					break;
				}
				
				
				case 7:
					cout << "### Gracias por usar el sistema ###" << endl;
					return 0;
				default:
					cout << "Opcion incorrecta" << endl;
					Sleep (2000);
					system("cls");
			}
		}while(opc<8 || opc>0);
		return 0;
	


	
	system("PAUSE");
}


int menu(){
	int opc;
	cout << "\t ***MENU***" << endl;
	cout << "1. Administrador" << endl;
	cout << "2. Mozo" << endl;
	cout << "3. Repartidor" << endl;
	cout << "4. Cliente" << endl;
	cout << "5. Cargar datos de prueba" << endl;
	cout << "6. Consultas" << endl;
	cout << "7. Salir" << endl << endl;
	cout << "Ingrese la opcion:"; 
	cin >> opc;
	return opc;
}

int menuAdministrador(){
	int opc;
	cout << "\t **MENU ADMINISTRADOR***" << endl;
	cout << "1. Alta producto" << endl;
 	cout << "2. Baja producto" << endl;
	cout << "3. Información de un producto" << endl;
	cout << "4. Alta empleado" << endl;
	cout << "5. Alta cliente" << endl;
	cout << "6. Resumen facturación de 1 día dada la fecha" << endl;
	cout << "7. Venta a domicilio" << endl;
	cout << "8. Consultar actualizaciones de pedidos a domicilio" << endl;
	cout << "9. Alta mesa" << endl;
	cout << "10. Agregar mozo a mesa" << endl;
	cout << "11. Volver a menu anterior" << endl << endl;
	
	cout << "Ingrese la opcion:"; 
	cin >> opc;
	return opc;
}

int menuMozo(){
	int opc;
	cout << "\t **MENU MOZO***" << endl;
	cout << "1. Iniciar venta en mesa" << endl;
	cout << "2. Agregar producto a una venta" << endl;
	cout << "3. Quitar producto a una venta" << endl;
	cout << "4. Facturación de una venta" << endl;
	cout << "5. Volver a menu anterior" << endl << endl;
	cout << "Ingrese la opcion:"; 
	cin >> opc;
	return opc;
}

int menuCliente(){
	int opc;
	cout << "\t **MENU CLIENTE***" << endl;
	cout << "1. Consultar actualizaciones de pedidos a domicilio" << endl;
	cout << "2. Volver a menu anterior" << endl << endl;
	cout << "Ingrese la opcion:"; 
	cin >> opc;
	return opc;
}

int menuRepartidor(){
	int opc;
	cout << "\t **MENU REPARTIDOR***" << endl;
	cout << "1. Modificar estado pedido" << endl;
	cout << "2. Volver a menu anterior" << endl << endl;
	cout << "Ingrese la opcion:"; 
	cin >> opc;
	return opc;
}

int menuConsultas(){
	int opc;
	cout << "\t ***MENU CONSULTAS DEL SISTEMA***" << endl;
	cout << "1. Consultar Facturas" << endl;
	cout << "2. Consultar empleados" << endl;
	cout << "3. Consultar mesas" << endl;
	cout << "4. Consultar productos" << endl;
	cout << "5. Consultar cliente" << endl;
	cout << "6. Volver a menu anterior" << endl;
	cin >> opc;
	return opc;
	
}


