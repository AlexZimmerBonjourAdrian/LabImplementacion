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
 


int menu();
int menuMozo();
int menuAdministrador();
int menuCliente();
int menuRepartidor();
int menuConsultas();

bool checkNum(){
	if(!cin.good()){
		cout << endl << "### EL VALOR SOLO PUEDE SER NUMERICO ###" << endl;
		system("PAUSE");
		cin.clear();
		fflush(stdin);
		return false;
	}
	else{
		return true;
	}
}

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
							
								cout << endl << "\t..DESEA AGREGAR UN PRODUCTO COMUN O UN MENU?(comun/menu)" << endl;
								cin >> opc1;
								if(opc1=="comun" || opc1=="COMUN" || opc1=="Comun"){
									cout << endl << "\t..Ingrese el codigo ";
									cin >> agregar;
									if(!checkNum()){
										break;
									}
									if(s->check_prod_sistema(agregar)){
										cout << endl << endl << "\t..Ya existe un producto con ese codigo" << endl;
										system("PAUSE");
										break;
									}
									cout << endl << endl <<"\t..Ingrese la descripcion ";
									fflush(stdin);
								    getline(cin,s1);
									
									do{
										cout << endl << endl << "\t..Ingrese el precio ";
										cin >> precio;
										if(!checkNum()){
											precio = 0;
											continue;
										}
										if(precio<=0){
											cout << "### EL PRECIO DEBE SER MAYOR QUE 0 ###" << endl;
										}
									}while(precio<=0);
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
									if(opc1=="menu" || opc1=="MENU" || opc1=="Menu"){
										ICollection * p = s->mostrarProductos();
										if(p==NULL){
											cout << "### NO HAY PRODUCTOS EN EL SISTEMA ###" << endl;
											Sleep(2000);
											break;
										}
										cout << endl << "\t..Ingrese el codigo ";
										cin >> agregar;
										if(!checkNum()){
											break;
										}
										if(s->check_prod_sistema(agregar)){
											cout << endl << endl << "### YA EXISTE UN PRODUCTO CON ESE CODIGO ###" << endl;
											system("PAUSE");
											break;
										}
										cout << endl << endl <<"\t..Ingrese la descripcion ";
										fflush(stdin);
										getline(cin,s1);
									
										cout << endl << endl;
									
										IIterator * it = p->getIterator();
										
										
										while(it->hasCurrent()){
											DtProducto * dp = (DtProducto *) it->getCurrent();
											if(dp->getTipo()=="Comun"){
												
												cout <<"Producto #" << dp->getCodigo() << "  " << dp->getDescripcion() << "  " << dp->getPrecio() << endl;
											}
											it->next();
										
										}
										cout << endl << endl << "\t..Ingrese los componentes del menu (para finalizar escriba 0) " << endl;
										int cod;
										bool check;
										
										do{
											cout << endl << "\t..Ingrese el codigo (para finalizar escriba 0)";
											cin >> cod;
											if(!checkNum()){
												break;
											}
											if(cod!=0)check=s->check_prod_sistema(cod);
											if(cod!=0 && !(check)){
												cout << endl << endl << "\t..No existe un producto con ese codigo" << endl;
												break;
											}
											if(cod!=0){
												int cant;
												do{
													cout << endl << endl << "\t..Ingrese la cantidad ";
													
													cin >> cant;
													if(!checkNum()){
														cant = 0;
														continue;
													}
													if(cant<=0){
														cout << "### LA CANTIDAD DEBE SER MAYOR QUE 0 ###" << endl;
													}
												}while(cant<=0);
											
											s->agregarProdMenu(cod,cant);
											}
										
										}while(cod!=0);
										if(check){
												
											cout << endl << endl << "\t..Desea confirmar el alta?(si o no)";
											cin >> opc1;
											if(opc1=="si"){
												s->agregarMenu(agregar,s1);
												cout << endl << "### SE HA AGREGADO EL PRODUCTO ###"<< endl;
											}
											else{
												cout << endl << "### NO SE HA AGREGADO EL MENU ###" << endl;
												system("PAUSE"); 
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
								
								ICollection * p = s->mostrarProductos();
								if(p==NULL){
									cout << "### NO HAY PRODUCTOS EN EL SISTEMA ###" << endl;
									Sleep(2000);
									break;
								}
								cout <<"### BAJA PRODUCTO ###" <<endl;
								
									
								
								cout << endl << "\t..Seleccione el producto a eliminar de la lista" << endl << endl ;
								IIterator * it = p->getIterator();
								
								while(it->hasCurrent()){
									DtProducto * dp = (DtProducto *) it->getCurrent();
									cout  << "\tProducto # "<< dp->getCodigo() << "  " << dp->getDescripcion() << "  " << dp->getPrecio() << endl;
									it->next();
								
								}
								int idprod=0;
								cin >> idprod;
								if(!checkNum()){
									break;
								}
								bool check;
								check=s->check_prod_sistema(idprod);
								if(!check){
									cout << "### NO EXISTE UN PRODUCTO CON ESE CODIGO ###" << endl;
									system("PAUSE");
									break;
								}
								cout << endl << "\t..Ingrese 1 para confirmar o 0 para cancelar" << endl;
								cin >> opc;
								if(!checkNum()){
									break;
								}
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
									cout << endl << endl;	
									it_p->next();
								}
								cout << "\tIngrese el codigo del producto (Si desea volver ingrese 0) ";
								
								int cod=1;
								bool ch=false;
								do{
									cin >> cod;
									if(!checkNum()){
										break;
									}
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
								fflush(stdin);
								getline(cin,nombre);
								
								cout << "\t..El empleado es repartidor?(si/no)" << endl << endl;
								cin >> opc1;
								if(opc1 != "si" && opc1!="SI" && opc1!="NO" && opc1!="no"){
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
										if(!checkNum()){
											break;
										}
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
											int mo= s->ingresarRepartidor(nombre,mt);
											cout << "###EL EMPLEADO HA SIDO DADO DE ALTA CON EL IDENTIFICADOR: "<<mo<< " ###" << endl; 
										}
								}
								else{
									int re=s->ingresarMozo(nombre);
									cout << "###EL EMPLEADO HA SIDO DADO DE ALTA CON EL IDENTIFICADOR: "<<re<< " ###" << endl; 
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
								if(s->check_cliente(telefono)){
									cout << "### YA EXISTE UN CLIENTE CON ESE NUMERO ###" << endl;
									system("PAUSE");
									break;
								}
								cout << endl << endl << "\t..Ingrese la calle: ";
								string calle;
								fflush(stdin);
								getline(cin,calle);
								cout << endl << endl << "\t..Ingrese el numero: ";
								int nro;
								cin >> nro;
								if(!checkNum()){
									break;
								}
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
								if(!checkNum()){
									break;
								}
								cout << endl << "\t..Mes: ";
								int mes;
								cin >> mes;
								if(!checkNum()){
									break;
								}
								cout << endl << "\t..Dia: ";
								int dia;
								cin >> dia;
								if(!checkNum()){
									break;
								}
								DtFecha * f = new DtFecha(anio,mes,dia);
								ICollection * facturas = s->getFacturasFecha(f);
								IIterator * it = facturas->getIterator();
								while(it->hasCurrent()){
									DtFactura * df =(DtFactura *) it->getCurrent();
									cout << endl <<"##Factura " << df->getCodigo() << " ##" << endl << "Subtotal: " << df->getSubtotal() << endl << " Descuento: "<< df->getDescuento()<< endl << endl;
									cout << endl <<"\t --Productos--" << endl << endl;
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
							case 7:{
								s->liberarMemoria();
								cout <<"### VENTA A DOMICILIO ###" <<endl;
								cout << endl << "\t..Ingresar telefono del cliente: ";
								int telefono=0;
								cin >> telefono;
								if(!checkNum()){
									cout << "### EL VALOR DEBE SER NUMERICO ###" << endl;
									system("PAUSE");
									break;
								}
								bool ck = s->check_cliente(telefono);
								if(ck==false){
									cout << endl << "\t.. El cliente ingresado no existe. Desea agregarlo? " << endl;
									cin>>s1;
									if(s1!="si" && s1!="no"){
										cout << "### OPCION INCORRECTA ###" << endl;
										break;
									}
									if(s1=="si"){
										cout << "\t..Ingrese el nombre: ";
										string nombre;
										fflush(stdin);
										getline(cin, nombre);
										cout << endl << endl << "\t..Ingrese la calle: ";
										string calle;
										fflush(stdin);
										getline(cin,calle);
										cout << endl << endl << "\t..Ingrese el numero: ";
										int nro;
										cin >> nro;
										if(!checkNum()){
											break;
										}
										cout << endl << endl << "\t..Desea confirmar el alta?(1 o 0)" << endl;
										cin >> opc;
										if(opc==1){
											s->crearCliente(nombre,telefono,calle,nro);
											cout << endl << "### SE CREO EL CLIENTE ###" << endl;
											Sleep (2000);
										}
										else{
											cout << endl << "### NO SE CREO EL CLIENTE ###" << endl;
											Sleep (2000);
											break;
										}
									}
									else{
										cout << "### NO SE AGREGO EL CLIENTE ###" << endl;
										system("PAUSE");
										break;
									}
								}
								
								ICollection * p = s->mostrarProductos();
								if(p==NULL){
									cout << "### NO EXISTEN PRODUCTOS EN EL SISTEMA ###" << endl;
									system("PAUSE");
									break;
									
								}
								cout << "\t..Seleccione los productos de la lista disponible" << endl << endl ;
								IIterator * itp = p->getIterator(); 
								while(itp->hasCurrent()){
									DtProducto * dp = (DtProducto *) itp->getCurrent();
									cout << "\t ..Codigo: " << dp->getCodigo() << endl;
									cout << "\t ..Nombre del Producto: " << dp->getDescripcion() << endl;
									cout << "\t ..Precio: " << dp->getPrecio() << endl;
									cout << endl << endl;
									itp->next();
								}
								
								cout << "\t..Ingrese el  producto(Ingrese 0 para terminar)" << endl;
								cin >> id;
								if(!checkNum()){
									break;
								}
								if(id==0){
									break;
								}
								do{
									
									
									cout << "\t..Ingrese la cantidad" << endl;
									int cant = 0;
									
									do{
										cin >> cant;
										if(!checkNum()){
											break;
										}	
										if(cant<=0){
											cout << "### LA CANTIDAD DEBE SER MAYOR QUE 0 ###" << endl;
											cout << "\t..Ingrese la cantidad:" << endl;
										}
									}while(cant<=0);
								
									
									cout << "\t..Desea confirmar?(1 , 0)" << endl;
									cin >> agregar;
									if(agregar==1){
										
										s->ingresarProducto(id,cant);
									
									}
									else{
										cout << "### PRODUCTO NO AGREGADO ###" << endl;	
									}
									cout << "\t..Ingrese el  producto(Ingrese 0 para terminar)" << endl;
									cin >> id;
							
						
								}while(id!=0);
							
								
								cout << endl << "### REPARTIDORES ###" << endl << endl;
								ICollection * emp = s->mostrarRepartidores();
								
								IIterator * it = emp->getIterator();
								if(!it->hasCurrent()){
									cout << "### NO HAY REPARTIDORES EN EL SISTEMA ###" << endl;
									s->liberarMemoria();
									break;
								}
								while(it->hasCurrent()){
									DtEmpleado * e = (DtEmpleado *) it->getCurrent();
									cout << "\t..Codigo: " << e->getId() << endl;
									cout << "\t..Nombre: " << e->getNombre() << endl;
									cout << "\t..Tipo: ";
									
									DtRepartidor * r1 = dynamic_cast<DtRepartidor*>(e);
									if(r1==NULL){
										cout << "Mozo" << endl;
									}
									else{
										cout << "Repartidor" << endl;
									}
									cout << endl << endl;
									it->next();
								}
								cout << endl << "\t..Ingrese el repartidor: ";
								int repartidor;
								cin >> repartidor;
								if(!checkNum()){
									break;
								}
								bool correct=false;
								do{
									cout << endl << "\t..Desea confirmar la venta?(si o no)" << endl;
									cin >> s1;
									if(s1=="SI" || s1=="Si" || s1=="si"){
										DtFactura * df = s->crearVdomicilio(repartidor,telefono);
										if(df!=NULL){
											cout << endl << "### SE CREO LA FACTURA CON LOS SIGUIENTES DATOS: ###" << endl << endl;
											cout << endl << "##Factura " << df->getCodigo() << " ##" << endl;
											cout << endl << "\t..Subtotal: " << df->getSubtotal() << endl ;
											cout << "\t..Descuento: "<< df->getDescuento()<< endl;
											cout << "\t..Monto total: " << df->getMonto()<< endl;
											cout << "\t..Monto total(IVA): " << df->gettotal_iva() << endl << endl;
											DtEmpleado * de = df->getTrabajador();
											cout << endl << "Empleado: " << de->getNombre() << endl << endl; 
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
										correct=true;
								}
								else{
									if(s1=="NO" || s1=="No" || s1=="no"){
										cout << "### NO SE CREO LA VENTA ###" << endl;
										correct=true;
									}
									else{
										cout <<  "### OPCION INCORRECTA ###" << endl;
									}
								}
								
							}while(correct==false);
								
								s->liberarMemoria();
								
								
								system("Pause");
								
								
								break;
							}
							case 8:{
								
								cout << "### CONSULTAR PEDIDOS DE UN REPARTIDOR ###" << endl;
								cout << endl << "\t..Ingresar el id del repartidor:" << endl;
								int rep;
								cin >>rep;
								ICollection * pedidos = s->getTodosPedidos(rep);
								IIterator * it = pedidos->getIterator();
								if(!it->hasCurrent()){
									cout << "### EL REPARTIDOR NO TIENE ENTREGAS PENDIENTES ###" << endl;
									system("PAUSE");
									break;
								}
								cout << endl << "\t..Seleccione el pedido a modificar:" << endl;
								
								
								while(it->hasCurrent()){
									DtVenta * dv = (DtVenta *) it->getCurrent();
									ICollection * prods = dv->getProductos();
									cout << endl << "Venta #" << dv->getCodigo() << endl;
									DtFecha * df = dv->getFecha();
									cout << "Fecha: " << df->getAnio() <<"-"<< df->getMes()<<"-" << df->getDia() << endl;
									cout << "Estado: " << dv->getEstado() << endl;
									it->next();
								}
							
								system("PAUSE");
								break;
							}
							case 9:{
								try{
									cout << endl << "### Alta mesa ###" << endl << endl;
									cout << "\t..Ingrese el id  de la mesa" << endl;
									cin >> id;
									if(!checkNum()){
										break;
									}
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
									if(!checkNum()){
										break;
									}
									cout << endl << "\t..Ingrese la mesa a agregar" << endl;
									cin >> descuento;
									if(!checkNum()){
										break;
									}
									s->agregarMesaMozo(descuento,id);
									cout << endl << "### LA MESA SE A AGREGADO AL MOZO ###" << endl;
									s->liberarMemoria();
									system("PAUSE");
									break;	
								
								
							}
							
							case 11:{
								s->asignarMesasAutomatico();
								cout << "### LAS MESAS HAN SIDO ASIGNADAS ###" << endl;
								system("PAUSE");
								break;
							}
							
							case 12:
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
				}while((opc<13 || opc>0) && !back);
					break;
				case 2:{
						do{
							try{
							system("cls");
							opc = menuMozo();
							switch(opc){
								case 1:{
									cout << endl << "###INICIAR VENTA EN MESA###" << endl << endl;
									
									ICollection * mozos = s->mostrarMozos();
									IIterator * it = mozos->getIterator();
									if(!it->hasCurrent()){
										cout << "### NO HAY MOZOS EN EL SISTEMA ###" << endl;
										system("PAUSE");
										break;
									}
									while(it->hasCurrent()){
										DtMozo * dm = (DtMozo*) it->getCurrent();
										cout << "Mozo #" << dm->getId() << " (" << dm->getNombre() << ")" << endl;
										it->next();
									}
									
									cout << endl << "\t..Ingrese el id del mozo" << endl << endl;
									cin >> id;
									if(!checkNum()){
										break;
									}
									Lista mesas=s->listarMesasAsignadas(id);
									cout << endl << endl << "### MESAS ASIGNADAS A ESTE MOZO ###" << endl << endl;
									mostrarLista(mesas); 
									cout << endl << "\t..Seleccione en que mesas iniciar la venta. Para terminar ingrese 0" << endl;
									cin >> id;
									bool pri=true;
									if(id==0){
										break;
									}
									while(id!=0){
										if(!pri)cin >> id;
										pri=false;
										if(id!=0 )s->seleccionarMesas(id);
										
									}
									if(!checkNum()){
										break;
									}
									cout << "\t..Las mesas seleccionadas son:" << endl << endl;
									Lista selec = s->listarMesasSeleccionadas();
									mostrarLista(selec);
									cout << endl << "\t..Ingrese 1 para confirmar o 0 para cancelar" << endl;
									cin >>id;
									if(!checkNum()){
										break;
									}
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
									if(!checkNum()){
										break;
									}
									s->ingresarMesa(opc);
									cout << "\t..Seleccione los productos de la lista disponible" << endl << endl ;
									
									
									IIterator * it = p->getIterator();
									while(it->hasCurrent()){
									
										DtProducto * dp = (DtProducto *) it->getCurrent();
										cout << "Producto #"<< dp->getCodigo() << "  " << dp->getDescripcion() << "  " << dp->getPrecio() << endl;
										it->next();
									
									}
									cout << "\t..Ingrese 0 para detenerse" << endl << endl;
									cin >> id;
									if(!checkNum()){
										break;
									}
									do{
										
										cout << "\t..Ingrese la cantidad" << endl;
										int cant = 0;
										cin >> cant;
										if(!checkNum()){
											break;
										}
										if(cant<=0){
											cout << "### LA CANTIDAD DEBE SER MAYOR QUE 0 ###";
											break;
										}
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
											
											
											
										}
										else{
											cout << "### PRODUCTO NO AGREGADO ###" << endl;	
										}
										cout << "\t..Ingrese el  producto(Ingrese 0 para terminar)" << endl;
										cin >> id;
								
									}while(id!=0);
									s->liberarMemoria();
									break;
								}
									
								case 3:{
								
									cout << endl << "### QUITAR PRODUCTO A UNA VENTA ### "<<endl;
									cout << endl << "\t..Ingrese la mesa a quitar" << endl;
									cin>>opc;
									if(!checkNum()){
										break;
									}
									s->ingresarMesa(opc);
									ICollection * p = s->mostrarProdVenta(opc);
									IIterator * it = p->getIterator();
									if(!it->hasCurrent()){
										cout << "### LA VENTA NO TIENE PRODUCTOS ###" << endl;
										break;
									}
									cout << "\t..Seleccione el producto de la lista disponible" << endl << endl ;
								
									while(it->hasCurrent()){
										DtProducto * dp = (DtProducto *) it->getCurrent();
										
										cout << "\t ..Codigo: " << dp->getCodigo() << endl;
										cout << "\t ..Nombre del Producto: " << dp->getDescripcion() << endl;
										cout << "\t ..Precio: " << dp->getPrecio() << endl;
										cout << "\t ..Cantidad: " << dp->getCantidad() << endl << endl << endl;
										
										it->next();
									
									}
									cin >> id;
									if(!checkNum()){
										break;
									}
									cout << "\t..Ingrese la cantidad" << endl;
									int cant = 0;
									cin >> cant;
									if(!checkNum()){
										break;
									}
								
									if(cant<=0){
										cout << "### LA CANTIDAD DEBE SER MAYOR QUE 0 ###";
										break;
									}
									bool ch = s->check_prod_venta(id);
									
									cout << "\t..Desea confirmar?(1 , 0)" << endl;
									cin >> agregar;
									if(agregar==1){
										if(ch==true){
											s->modificarCantidad(id,cant,"resta");
											cout << "### SE HA ELIMINADO EL PRODUCTO DE LA VENTA ###" << endl;
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
									if(!checkNum()){
										break;
									}
									if(!s->check_mesa_menu(id)){
										cout << endl << "\t..Ingrese el descuento a aplicar" << endl;
										cin >> descuento;
										if(!checkNum()){
											break;
										}
									}
									
									DtFactura * df = s->emitirFactura(id,descuento);
									
									if(df!=NULL){
										cout << endl << "### SE CREO LA FACTURA CON LOS SIGUIENTES DATOS: ###" << endl << endl;
											cout << endl << "##Factura " << df->getCodigo() << " ##" << endl << endl;
											cout << "\t..Subtotal: " << df->getSubtotal() << endl;
											cout << "\t..Descuento: "<< df->getDescuento()<< endl;
											cout << "\t..Monto total: " << df->getMonto()<< endl;
											cout << "\t..Monto total(IVA): " << df->gettotal_iva() << endl << endl;
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
							case 1:{
								try{
							
									cout << endl <<"### MODIFICAR ESTADO DEL PEDIDO ###" <<endl;
									cout << endl << "\t..Ingresar el id del repartidor:" << endl;
									int rep;
									cin >>rep;
									ICollection * pedidos = s->getPedidos(rep);
									IIterator * it = pedidos->getIterator();
									if(!it->hasCurrent()){
										cout << "### EL REPARTIDOR NO TIENE ENTREGAS PENDIENTES ###" << endl;
										system("PAUSE");
										break;
									}
									cout << endl << "\t..Seleccione el pedido a modificar:" << endl;
									
									
									while(it->hasCurrent()){
										DtVenta * dv = (DtVenta *) it->getCurrent();
										ICollection * prods = dv->getProductos();
										cout << endl << "Venta #" << dv->getCodigo() << endl;
										DtFecha * df = dv->getFecha();
										cout << "Fecha: " << df->getAnio() <<"-"<< df->getMes()<<"-" << df->getDia() << endl;
										cout << "Estado: " << dv->getEstado() << endl;
										it->next();
									}
									cin >> id;
									cout << "\t..Que cambio quiere hacer?(1 o 2)" << endl;
									cout << "\t..1- Confirmar ENTREGADA " << endl;
									cout << "\t..2- Confirmar EN CAMINO " << endl;
									cin >> opc;
									s->cambiarEstado(id,opc,rep);
									cout << "### SE HA ACTUALIZADO EL ESTADO ###" << endl;
									system("PAUSE");
									break;
								}catch(char const * msg){
									cout << msg << endl;
									system("PAUSE");
								}
							}
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
							case 1:{
			
								cout <<"### CONSULTAR ACTUALIZACIONES DE PEDIDOS A DOMICILIO DE UN CLIENTE ###" <<endl << endl;
								cout << "\t..Ingrese el telefono del cliente a mostrar" << endl; 
								cin >> id;
								if(!checkNum){
									break;
								}
								ICollection * pedidos = s->getPedidosCliente(id);
								IIterator * it = pedidos->getIterator();
								if(!it->hasCurrent()){
									cout << "### EL CLIENTE NO HA HECHO PEDIDOS ###" << endl;
									system("PAUSE");
									break;
								}
								while(it->hasCurrent()){
									DtVenta * dv = (DtVenta *) it->getCurrent();
									ICollection * prods = dv->getProductos();
									cout << endl << "Venta #" << dv->getCodigo() << endl;
									DtFecha * df = dv->getFecha();
									cout << "Fecha: " << df->getAnio() <<"-"<< df->getMes()<<"-" << df->getDia() << endl;
									cout << "Estado: " << dv->getEstado() << endl << endl;
									IIterator * itp = prods->getIterator();
									if(!it->hasCurrent()){
										cout << "### LA VENTA NO TIENE PRODUCTOS ###" << endl;
									}
									
									else{	
										while(itp->hasCurrent()){
										DtProducto * dp = (DtProducto *) itp->getCurrent();
										cout << "\t ..Codigo: " << dp->getCodigo() << endl;
										cout << "\t ..Nombre del Producto: " << dp->getDescripcion() << endl;
										cout << "\t ..Precio: " << dp->getPrecio() << endl;
										cout << endl << endl;	
										itp->next();
									}
											
									}
									it->next();
								}
								
								system("PAUSE");
								break;
								
								
								
							}
								
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
							try{
								system("cls");
								opc = menuConsultas();
								switch(opc){
									case 1:{
										ICollection * facturas = s->getFacturas();
										IIterator * it = facturas->getIterator();
										while(it->hasCurrent()){
											DtFactura * df =(DtFactura *) it->getCurrent();
											string tipo;
											DtEmpleado * e =df->getTrabajador();
											DtMozo * dm = dynamic_cast<DtMozo*>(e);
											if(dm==NULL){
												tipo="Repartidor";
											} 
											else{
												tipo="Mozo";
											}
											cout << endl << "##Factura " << df->getCodigo() << " ##" << endl << endl;
											cout << "Subtotal: " << df->getSubtotal() << endl;
											cout << "Descuento: "<< df->getDescuento()<< endl;
											cout << "Monto total: " << df->getMonto()<< endl;
											cout << "Monto total(IVA): " << df->gettotal_iva() << endl << endl;
											DtFecha * dtf = df->getFecha();
											cout << "Fecha: " << dtf->getAnio() << "-" << dtf->getMes() << "-" << dtf->getDia() << endl << endl; 
											DtEmpleado * de = df->getTrabajador();
											cout << "Empleado: " << de->getNombre() <<"  ("<<tipo <<") " <<endl << endl;
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
											it->next();
										}
										system("PAUSE");
										break;
									}
																
									case 2:{
										cout << "### EMPLEADOS ###" << endl << endl;
										ICollection * emp = s->getEmpleados();
										IIterator * it = emp->getIterator();
										while(it->hasCurrent()){
											DtEmpleado * e = (DtEmpleado *) it->getCurrent();
											cout << "\t..Codigo: " << e->getId() << endl;
											cout << "\t..Nombre: " << e->getNombre() << endl;
											cout << "\t..Tipo: ";
											
											DtRepartidor * r1 = dynamic_cast<DtRepartidor*>(e);
											if(r1==NULL){
												cout << "Mozo" << endl;
												DtMozo * m1 = dynamic_cast<DtMozo*>(e);
												ICollection * mesas = m1->getMesas();
												IIterator * it_mesas = mesas->getIterator();
												if(it_mesas->hasCurrent()==false){
													cout << endl << "\t### EL MOZO NO TIENE MESAS ASIGNADAS ###" << endl << endl;
													
												}
												else{
													cout << "\t### MESAS ASIGNADAS ###" << endl << endl;
													while(it_mesas->hasCurrent()){
														DtMesa * dtm = (DtMesa*)it_mesas->getCurrent();
														cout << "\t\tMesa #" << dtm->getId() << endl;
														it_mesas->next();
													}
													delete it_mesas; 
												}
												
											}
											else{
												cout << "Repartidor" << endl;
												cout << "\t..Medio de transporte: " << r1->getMedio() << endl;
											}
											cout << endl << endl;
											it->next();
										}
										system("Pause");
										break;
									}
										
									case 3:{
										cout << "### MESAS ###" << endl << endl;
										ICollection * mesas = s->getMesas();
										IIterator * it = mesas->getIterator();
										if(!it->hasCurrent()){
											cout << "### NO EXISTEN MESAS EN EL SISTEMAS ###" << endl;
											break;
										}
										while(it->hasCurrent()){
											DtMesa* m = (DtMesa *)it->getCurrent();
											cout << "Mesa #" << m->getId() << endl;
											it->next();
										}
										system("PAUSE");
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
										cout << endl << "### VENTAS ###" << endl;
										ICollection * ventas = s->getVentas();
										IIterator * it = ventas->getIterator();
										while(it->hasCurrent()){
											DtVenta * dv = (DtVenta*) it->getCurrent();
											ICollection * prods = dv->getProductos();
											cout << endl << "Venta #" << dv->getCodigo() << endl;
											DtFecha * df = dv->getFecha();
											cout << "Fecha: " << df->getAnio() <<"-"<< df->getMes()<<"-" << df->getDia() << endl;
											cout << "Estado: " << dv->getEstado() << endl << endl;
											IIterator * itp = prods->getIterator();
											while(itp->hasCurrent()){
												DtProducto * dp = (DtProducto *) itp->getCurrent();
												cout << "\t ..Codigo: " << dp->getCodigo() << endl;
												cout << "\t ..Nombre del Producto: " << dp->getDescripcion() << endl;
												cout << "\t ..Precio: " << dp->getPrecio() << endl;
												cout << endl << endl;	
												itp->next();
											}
											
											it->next();
										}
										system("PAUSE");
										break;
									}
									
									case 7:{
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
							}catch(char const * msg){
								cout << msg << endl;
								system("PAUSE");
							}		
						}while((opc<8 || opc>0) && !back);
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
	if(!checkNum()){
		return 0;
	}
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
	cout << "11. Asignar mozos a mesas automaticamente" << endl;
	cout << "12. Volver a menu anterior" << endl << endl;
	
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
	cout << "6. Consultar ventas" << endl;
	cout << "7. Volver a menu anterior" << endl;
	cin >> opc;
	return opc;
	
}


