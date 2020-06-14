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
	try{
		string opc1,s1;
		Sistema * s = Sistema::getInstance();
		Mesa * me1 = new Mesa(1,new ListDictionary());
		Producto * p1 = new Producto(1,"Cerveza", 150);
		int id=1, descuento;
		

//		//Iniciar Venta en mesa
//		
//		
//		cout << "Ingrese el id del mozo" << endl;
//		cin >> id;
//		mostrarLista(s->listarMesasAsignadas(id));
//		cout << "Seleccione en que mesas iniciar la venta. Para terminar ingrese 0" << endl;
//		while(id!=0){
//			cin >> id;
//			if(id!=0)s->seleccionarMesas(id);
//			
//		}
//		Lista selec = s->listarMesasSeleccionadas();
//		mostrarLista(selec);
//		cout << "Ingrese 1 para confirmar o 0 para cancelar" << endl;
//		cin >>id;
//		if(id==0){
//			s->liberarMemoria();
//			cout << "No se inicio la venta" << endl;
//		}
//		else{
//			s->confirmarSeleccion(selec,new DtFecha(2018,12,01));
//			s->liberarMemoria();
//			cout << "Se inicio la venta" << endl;
//		}
//		
//		//Agregar Producto a una venta
//		cout << endl << "Ingrese la mesa a agregar" << endl;
//		s->ingresarMesa(1);
//		cout << "Seleccione los productos de la lista disponible" << endl ;
//		
//		ICollection * p = s->mostrarProductos();
//		IIterator * it = p->getIterator();
//		while(it->hasCurrent()){
//		
//			DtProducto * dp = (DtProducto *) it->getCurrent();
//			cout << dp->getCodigo() << "  " << dp->getDescripcion() << "  " << dp->getPrecio() << endl;
//			it->next();
//		
//		}
//		cout << "Ingrese 0 para detenerse" << endl << endl;
//		cin >> id;
//		do{
//			
//			cout << "Ingrese la cantidad" << endl;
//			int cant = 0;
//			cin >> cant;
//			bool ch = s->check_prod_venta(id);
//			cout << "Desea confirmar?(1 , 0)" << endl;
//			cin >> agregar;
//			if(agregar==1){
//				if(ch==true){
//					s->modificarCantidad(id,cant);
//				}
//				
//				else{
//					s->agregarProducto(id,cant);
//				}
//				cout << "Producto agregado" << endl;
//				s->liberarMemoria();
//			}
//			else{
//				s->liberarMemoria();
//			}
//			cin >> id;
//	
//		}while(id!=0);
//		cout << "LPM1" << endl;
//		ICollection * cant = v1->getCantidades();
//		if(cant==NULL)cout << "LPM" << endl;
//		IIterator * it2 = cant->getIterator();
//		while(it2->hasCurrent()){
//			
//			CantidadProd * c = (CantidadProd*) it2->getCurrent();
//			DtProducto * dt = c->getDtProducto();
//			cout << dt->getDescripcion() << endl;
//			it2->next();
//		}
//		
//		//Facturacion de una venta
//		
//		DtFactura * f = s->emitirFactura(1,10);
//		if(f!=NULL){
//			cout << f->getCodigo() << "   " << f->getNombreTrabajador() << "   " << f->getSubtotal() << "   " << f->getDescuento() << endl;
//		}

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
									if(s->check_prod_sistema(agregar)){
										cout << endl << endl << "\t..Ya existe un producto con ese codigo" << endl;
										system("PAUSE");
										break;
									}
									cout << endl << endl <<"\t..Ingrese la descripcion ";
									cin>>s1;
									cout << endl << endl << "\t..Ingrese el precio ";
									cin >> precio;
									cout << endl << endl << "\t..Desea confirmar el alta? ";
									cin >> opc1;
									if(opc1=="si"){
										s->agregarProducto(agregar,s1,precio);
										s->liberarMemoria();
									}
									else{
										s->liberarMemoria();
									}
									
								}
								else{
									cout << endl << "\t..Ingrese el codigo ";
									cin >> agregar;
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
									do{
										cout << endl << "\t..Ingrese el codigo ";
										cin >> cod;
										if(cod!=0 && !(s->check_prod_sistema(cod))){
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
									cout << endl << endl << "\t..Desea confirmar el alta? ";
									cin >> opc1;
									if(opc1=="si"){
										s->agregarMenu(agregar,s1,precio);
										s->liberarMemoria();
									}
									else{
										s->liberarMemoria();
									}
									}
								
								break;
							}
							case 2:
								cout <<"Baja producto no implementado" <<endl;
								Sleep (2000);
								break;
							case 3:
								cout <<"Infromación de un producto no implementado" <<endl;
								Sleep (2000);
								break;
							
							case 4:{
								cout << endl << "###INGRESAR EMPLEADO###" << endl << endl << "\t..Ingrese el nombre:" << endl;
								string nombre;
								cin >>nombre;
								cout << "\t..El empleado es repartidor?(si/no)" << endl << endl;
								cin >> opc1;
								if(opc1=="si"){
										cout << "\t..Seleccione un medio de transporte" << endl << endl;
										cout << "\t\t..--A pie" << endl;
										cout << "\t\t..--Bicicleta" << endl;
										cout << "\t\t..--Moto" << endl;
										string mt;
										cin >>mt;
										s->ingresarRepartidor(nombre,mt);
								}
								else{
									s->ingresarMozo(nombre);
								}
								
								cout << "###EL EMPLEADO HA SIDO DADO DE ALTA###" << endl; 
								
								Sleep (2000);
								break;
							}
							
							case 5:
								cout <<"Alta empleado no implementado" <<endl;
								Sleep (2000);
								break;
								
							case 6:
								cout <<"Resumen facturación de 1 día dada la fecha no implementado" <<endl;
								Sleep (2000);
								break;
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
								}catch(const char * msg){
										cout << msg << endl;
								}
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
								Sleep(2000);
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
					}while((opc<12 || opc>0) && !back);
					break;
				case 2:
					do{
						system("cls");
						opc = menuMozo();
						switch(opc){
							case 1:{
								cout << "###INICIAR VENTA EN MESA###" << endl << endl;
								
								cout << "\t..Ingrese el id del mozo" << endl << endl;
								cin >> id;
								cout << endl << endl << "### MESAS ASIGNADAS A ESTE MOZO ###" << endl << endl;
								mostrarLista(s->listarMesasAsignadas(id)); 
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
									s->confirmarSeleccion(selec,new DtFecha(2018,12,01));
									s->liberarMemoria();
									cout << endl << "### Se inicio la venta ###" << endl;
								}	
								Sleep (2000);
								break;
							}
							
							case 2:{
									//Agregar Producto a una venta
								
								break;
							}
								
							case 3:
								cout <<"Quitar producto a una venta no implementado" <<endl;
								Sleep (2000);
								break;
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
										cout << endl << endl;
										
									
									}
								}
								else{
									cout << endl << "LA MESA YA HA SIDO FACTURADA" << endl;
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
					}while((opc<6 || opc>0) && !back);
					break;
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
					cout << "Funcion Cargar datos de prueba no implementada" << endl;
					Sleep (2000);
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
									cout << "##Factura " << df->getCodigo() << " ##" << endl << "Subtotal: " << df->getSubtotal() << endl << " Descuento: "<< df->getDescuento()<< endl << endl;
									cout << "\t --Productos--" << endl << endl;
									ICollection * prod = df->getProductos();
									IIterator * it_p = prod->getIterator();
									while(it_p->hasCurrent()){
										DtProducto * dp = (DtProducto *) it_p->getCurrent();
										cout << "\t ..Codigo: " << dp->getCodigo() << endl;
										cout << "\t ..Nombre del Producto: " << dp->getDescripcion() << endl;
										cout << "\t ..Precio: " << dp->getPrecio() << endl;
										cout << endl << endl;
										
										it->next();
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
									cout << "\t..Tipo: " << endl << endl << endl;
									it->next();
								}
								system("Pause");
								break;
							}
								
							case 3:{
								break;
							}
								
							case 4:{
								cout << "\t --Productos--" << endl << endl;
								ICollection * prod = s->mostrarProductos();
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
					}while((opc<6 || opc>0) && !back);
					break;
				}
				
				
				case 7:
					cout << "Gracias por usar el sistema" << endl;
					return 0;
				default:
					cout << "Opcion incorrecta" << endl;
					Sleep (2000);
					system("cls");
			}
		}while(opc<8 || opc>0);
		return 0;
	
	}catch(const char * msg){
		cout << msg << endl;
	}
	
	

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
	cout << "3. Infromación de un producto" << endl;
	cout << "4. Alta empleado" << endl;
	cout << "5. Asignar mozos a mesas" << endl;
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
	cout << "5. Volver a menu anterior" << endl;
	cin >> opc;
	return opc;
	
}


