#include "Sistema.cpp"
#include<iostream>
#include<stdio.h>
#include <windows.h>
#include <typeinfo>
#include<ctime>

using namespace std;
 

void gotoxy(int x, int y) //implementación de la función gotoxy
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}


void SetColor(int ForgC){
    WORD wColor;

     HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
     CONSOLE_SCREEN_BUFFER_INFO csbi;

                          //We use csbi for the wAttributes word.
    if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
    {
                    //Mask out all but the background attribute, and add in the forgournd color
         wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
         SetConsoleTextAttribute(hStdOut, wColor);
    }
    return;
}


int menu();
int menuMozo();
int menuAdministrador();
int menuCliente();
int menuRepartidor();
int menuConsultas();

bool checkNum(){
	if(!cin.good()){
		SetColor(12);
		cout << endl << "### EL VALOR SOLO PUEDE SER NUMERICO ###" << endl;
		SetColor(15);
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
	bool cargar = false;
	bool venta=false;
	bool datos=false;
		string opc1,s1;
		Sistema * s = Sistema::getInstance();
		int id=1, descuento;
		int opc;
		int mozopc;
		bool back = false;
		do{
			back=false;
			system("cls");
			opc = menu();
			switch(opc){
				case 1:{
				
					do{
						try{
						
						system("cls");
						if(cargar==false){
							SetColor(12);
							cout << "### ADVERTENCIA ###" << endl;
							SetColor(15);
							cout << endl << "Si agrega datos antes de cargar los datos de prueba se pueden" << endl;
							cout << "producir errores en la consistencia de los datos" << endl;
							cout << endl << "\t Desea continuar?(si o no)" << endl;
							cin >> s1;
							if(s1=="si"||s1=="SI" || s1=="Si"){
								cargar=true;
								system("cls");
							}
							else{
								break;
							}
						}
						
						
						opc = menuAdministrador();
						
						switch(opc){
							case 1:{
								system("cls");
								
								
								cout << endl << "### ALTA PRODUCTO ###" << endl << endl;
								bool ck=false;
								cout << endl << "\t..DESEA AGREGAR UN PRODUCTO COMUN O UN MENU?(comun/menu)" << endl;
								string opcion;
								cin >> opcion;
								if(opcion!="menu" && opcion!="comun"){
									SetColor(12);
									cout << "### OPCION INCORRECTA ###" << endl;
									SetColor(15);
									system("PAUSE");
									break;
								}
								ICollection * p = s->mostrarProductos();
								IIterator * it = p->getIterator();
								if(!it->hasCurrent() && opcion=="menu"){
									SetColor(12);
									cout << "### NO HAY PRODUCTOS EN EL SISTEMA ###" << endl;
									SetColor(15);
									delete p,it;
									Sleep(2000);
									break;
								}
								do{
									system("cls");
									cout << "### DATOS ###" << endl << endl;
									cout << endl << "\t..Ingrese el codigo ";
									cin >> agregar;
									if(!checkNum()){
										system("cls");
										continue;
									}
									if(agregar==0){
										SetColor(12);
										cout << "### EL CODIGO NO PUEDE SER 0 ###" <<  endl;
										SetColor(15);
										system("PAUSE");
										system("cls");
										continue;
									}
									if(s->check_prod_sistema(agregar)){
										SetColor(12);
										cout << endl << endl << "### YA EXISTE UN PRODUCTO CON ESE CODIGO ###" << endl;
										SetColor(15);
										system("PAUSE");
										system("cls");
										continue;
									}
								
									ck=true;
									
								}while(ck==false);
								
								cout << endl << endl <<"\t..Ingrese la descripcion ";
								fflush(stdin);
							    getline(cin,s1);
									
			
								if(opcion=="comun" || opcion=="COMUN" || opcion=="Comun"){
								
								
									do{
										cout << endl << endl << "\t..Ingrese el precio ";
										cin >> precio;
										if(!checkNum()){
											precio = 0;
											continue;
										}
										if(precio<=0){
											SetColor(12);
											cout << endl <<"### EL PRECIO DEBE SER MAYOR QUE 0 ###" << endl;
											SetColor(15);
										}
									}while(precio<=0);
									cout << endl << endl << "\t..Desea confirmar el alta?(si o no)";
									cin >> opc1;
									if(opc1=="si"){
										s->agregarProducto(agregar,s1,precio);
										SetColor(10);
										cout << endl << "### SE HA AGREGADO EL PRODUCTO ###"<< endl;
										SetColor(15);
									
										s->liberarMemoria();
									}
									else{
										SetColor(12);
										cout << "### NO SE CREO EL PRODUCTO ###" << endl;
										SetColor(15);
										s->liberarMemoria();
									}
									
								}
								else{
									if(opcion=="menu" || opcion=="MENU" || opcion=="Menu"){
									
									
										system("cls");
										cout << "### PRODUCTOS ###" << endl<< endl;
										
										while(it->hasCurrent()){
											DtProducto * dp = (DtProducto *) it->getCurrent();
											if(dp->getTipo()=="Comun"){					
												cout << "\t ..Codigo: " << dp->getCodigo() << endl;
												cout << "\t ..Nombre del Producto: " << dp->getDescripcion() << endl;
												cout << "\t ..Precio: " << dp->getPrecio() << endl;
												cout << endl << endl;							
											}
											delete dp;
											it->next();
										
										}
										delete p, it;
										cout << endl << endl << "### INGRESE LOS COMPONENTES ### " << endl;
										int cod;
										bool check;
										
										do{
											cout << endl << "\t..Ingrese el codigo (para finalizar escriba 0): ";
											cin >> cod;
											if(!checkNum()){
												break;
											}
											if(cod!=0)check=s->check_prod_sistema(cod);
											if(cod!=0 && !(check)){
												SetColor(12);
												cout << endl << endl << "### NO EXISTE PRODUCTO CON ESE CODIGO ###" << endl;
												SetColor(15);
												break;
											}
											if(cod!=0){
												int cant;
												do{
													cout << endl << endl << "\t..Ingrese la cantidad: ";
													
													cin >> cant;
													if(!checkNum()){
														cant = 0;
														continue;
													}
													if(cant<=0){
														SetColor(12);
														cout << "### LA CANTIDAD DEBE SER MAYOR QUE 0 ###" << endl;
														SetColor(15);
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
												SetColor(10);
												cout << endl << "### SE HA AGREGADO EL PRODUCTO ###"<< endl;
												SetColor(15);
											}
											else{
												SetColor(12);
												cout << endl << "### NO SE HA AGREGADO EL MENU ###" << endl;
												SetColor(15);
												system("PAUSE"); 
											}
											s->liberarMemoria();
										}
											
										}
										else{
											SetColor(12);
											cout << "### OPCION INCORRECTA ###" << endl;
											SetColor(15);
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
								IIterator * it = p->getIterator();
								if(!it->hasCurrent()){
									SetColor(12);
									cout << "### NO HAY PRODUCTOS EN EL SISTEMA ###" << endl;
									SetColor(15);
									delete it,p;
									system("PAUSE");
									break;
								}
								system("cls");
								cout <<"### BAJA PRODUCTO ###" <<endl;
								
									
								
								cout << endl << "\t..Seleccione el producto a eliminar de la lista" << endl << endl ;
								
								
								while(it->hasCurrent()){
									DtProducto * dp = (DtProducto *) it->getCurrent();
									cout <<endl << endl <<"\t ..Codigo: " << dp->getCodigo() << endl;
									cout << "\t ..Nombre del Producto: " << dp->getDescripcion() << endl;
									cout << "\t ..Precio: " << dp->getPrecio() << endl;
									delete dp;
									it->next();
								
								}
								delete it,p;
								int idprod=0;
								cin >> idprod;
								if(!checkNum()){
									break;
								}
								bool check;
								check=s->check_prod_sistema(idprod);
								if(!check){
									SetColor(12);
									cout << "### NO EXISTE UN PRODUCTO CON ESE CODIGO ###" << endl;
									SetColor(15);
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
									SetColor(10);
									cout << endl << "### SE HA ELIMINADO EL PRODUCTO ###" << endl;
									SetColor(15);
								}
								else{
									s->liberarMemoria();
									SetColor(12);
									cout << endl << "### NO SE HA ELIMINADO EL PRODUCTO ###" << endl;
									SetColor(15);
								}
								system("PAUSE");
								break;
							}
							case 3:{
							
							
								ICollection * prod = s->mostrarProductos();
								IIterator * it_p = prod->getIterator();
								if(!it_p->hasCurrent()){
									SetColor(12);
									cout << endl << "### NO HAY PRODUCTOS EN EL SISTEMA ###" << endl;
									SetColor(15);
									delete it_p,prod;
									Sleep(2000);
									break;
								}
								cout << endl << "### INFORMACION DE UN PRODUCTO ###" <<endl << endl;
								
								
								
								while(it_p->hasCurrent()){
									DtProducto * dp = (DtProducto *) it_p->getCurrent();
									cout << "\t ..Codigo: " << dp->getCodigo() << endl;
									cout << "\t ..Nombre del Producto: " << dp->getDescripcion() << endl;
									cout << endl << endl;
									delete dp;	
									it_p->next();
								}
								cout << "\tIngrese el codigo del producto (Si desea volver ingrese 0) ";
								delete it_p,prod;
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
										SetColor(12);
										cout << endl << endl << "###  CODIGO INCORRECTO ###" << endl;
										SetColor(15);
										cout << endl << "\tIngrese el codigo del producto nuevamente (Si desea cancelar ingrese 0) ";
									}
									
								}while(ch==false && cod!=0);
								if(cod==0){
									break;
								}
								DtProducto * dp = s->mostrarProducto(cod);
								if(ch==true){
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
										DtProducto * dc = (DtProducto*) it->getCurrent();
										cout << "\tCodigo: " << dc->getCodigo() << endl;
										cout << "\tDescripcion: " << dc->getDescripcion() << endl;
										cout << "\tPrecio: " << dc->getPrecio() << endl;
										cout << "\tCantidad: " <<dc->getCantidad() << endl << endl;
										it->next();
										//delete dc;
										
									}
									delete dp,it;
								}
								system("PAUSE");
								break;
							}
							case 4:{
								system("cls");
								cout << endl << "### INGRESAR EMPLEADO ###" << endl << endl << "\t..Ingrese el nombre: " ;
								string nombre;
								fflush(stdin);
								getline(cin,nombre);
								
								cout << "\t..El empleado es repartidor?(si/no)" << endl << endl;
								cin >> opc1;
								if(opc1 != "si" && opc1!="SI" && opc1!="NO" && opc1!="no"){
									SetColor(12);
									cout << "### OPCION INCORRECTA ###" << endl;
									SetColor(15);
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
												SetColor(12);
												cout << "### OPCION INCORRECTA ###" << endl;
												SetColor(15);
												m=false;
												break;
												
										}
										if(m){
											int mo= s->ingresarRepartidor(nombre,mt);
											SetColor(10);
											cout << "###EL EMPLEADO HA SIDO DADO DE ALTA CON EL IDENTIFICADOR: "<<mo<< " ###" << endl;
											SetColor(15); 
										}
								}
								else{
									int re=s->ingresarMozo(nombre);
									SetColor(10);
									cout << "###EL EMPLEADO HA SIDO DADO DE ALTA CON EL IDENTIFICADOR: "<<re<< " ###" << endl; 
									SetColor(15);
								}
	
								Sleep (2000);
								break;
							}							
							case 5:{
								system("cls");
								cout <<"### ALTA CLIENTE ###" <<endl << endl;
								cout << "\t..Ingrese el nombre: ";
								string nombre;
								fflush(stdin);
								getline(cin, nombre);
								cout << endl << endl << "\t..Ingrese el telefono: ";
								long int telefono;
								cin >> telefono;
								if(s->check_cliente(telefono)){
									SetColor(12);
									cout << "### YA EXISTE UN CLIENTE CON ESE NUMERO ###" << endl;
									SetColor(15);
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
								
								cout << endl << endl << "\t..Vive en un apartamento?(si o no)" << endl;
								string op;
								cin>>op;
								if(!checkNum()){
									break;
								}
								DtDireccion * dc = NULL;
								if(op=="Si" || op=="si" || op=="SI"){
									cout << endl << "\t..Ingrese el nombre del apartamento: ";
									string nombreAp;
									fflush(stdin);
									getline(cin,nombreAp);
									cout << endl << endl;
									cout << "\t..Ingrese el piso: ";
									int piso;
									cin>>piso;
									if(!checkNum()){
										break;
									}
									 dc = new DtApartamento(calle,nro,nombreAp,piso);
								}
								else{
									dc=new DtDireccion(calle,nro);
								}
								cout << endl << endl << "\t..Desea confirmar el alta?(si o no)" << endl;
								cin >> s1;
								if(s1=="Si" || s1=="si" || s1=="SI"){
									s->crearCliente(nombre,telefono,dc);
									SetColor(10);
									cout << endl << "### SE CREO EL CLIENTE ###" << endl;
									SetColor(15);
									Sleep(2000);
									
								}
								else{
									SetColor(12);
									cout << endl << "### NO SE CREO EL CLIENTE ###" << endl;
									SetColor(15);
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
								DtFecha * f = new DtFecha(anio,mes,dia,0,0);
								ICollection * facturas = s->getFacturasFecha(f);
								delete f;
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
								system("cls");
								ICollection * p = s->mostrarProductos();
								IIterator * itp = p->getIterator();
								if(!itp->hasCurrent()){
									SetColor(12);
									cout << "### NO EXISTEN PRODUCTOS EN EL SISTEMA ###" << endl;
									SetColor(15);
									system("PAUSE");
									break;
									
								}
								
								ICollection * clientes = s->mostrarClientes();
								IIterator * itc = clientes->getIterator();
								if(!itc->hasCurrent()){
									SetColor(12);
									cout << "### NO HAY CLIENTES EN EL SISTEMA ###" << endl;
									SetColor(15);
									system("PAUSE");
									delete itc, clientes;
									break;
								}
								
								cout <<"### VENTA A DOMICILIO ###" <<endl;
								
							
								cout << endl <<  "### Clientes ###" << endl;
								
								while(itc->hasCurrent()){
									DtCliente * dc = (DtCliente *) itc->getCurrent();
									cout << endl << "\t..Telefono: " << dc->getTelefono() << endl;
									cout << "\t..Nombre: " << dc->getNombre() << endl;
									DtDireccion * dd = dc->getDireccion();
									cout << "\t..Direccion: " << dd->getCalle() << "  " << dd->getNro() << endl << endl;
									cout << "          -------------------------" << endl;
									itc->next();
									
								}
								
								
								
								cout << endl << "\t..Ingresar telefono del cliente: ";
								int telefono=0;
								cin >> telefono;
								if(!checkNum()){
									
									break;
								}
								bool ck = s->check_cliente(telefono);
								if(ck==false){
									cout << endl << "\t.. El cliente ingresado no existe. Desea agregarlo? " << endl;
									cin>>s1;
									if(s1!="si" && s1!="no"){
										SetColor(12);
										cout << "### OPCION INCORRECTA ###" << endl;
										SetColor(15);
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
										
										cout << "\t..Vive en un apartamento?(si o no)" << endl;
										string op;
										cin>>op;
										if(!checkNum()){
											break;
										}
										DtDireccion * dc = NULL;
										if(op=="Si" || op=="si" || op=="SI"){
											cout << endl << "\t..Ingrese el nombre del apartamento: ";
											string nombreAp;
											getline(cin,nombreAp);
											cout << endl << endl;
											cout << "\t..Ingrese el piso: ";
											int piso;
											cin>>piso;
											if(!checkNum()){
												break;
											}
											 dc = new DtApartamento(calle,nro,nombreAp,piso);
										}
										else{
											dc=new DtDireccion(calle,nro);
										}
													
										
										cout << endl << endl << "\t..Desea confirmar el alta?(1 o 0)" << endl;
										cin >> opc;
										if(opc==1){
											s->crearCliente(nombre,telefono,dc);
											SetColor(10);
											cout << endl << "### SE CREO EL CLIENTE ###" << endl;
											SetColor(15);
											Sleep (2000);
										}
										else{
											SetColor(12);
											cout << endl << "### NO SE CREO EL CLIENTE ###" << endl;
											SetColor(15);
											Sleep (2000);
											break;
										}
									}
									else{
										SetColor(12);
										cout << "### NO SE AGREGO EL CLIENTE ###" << endl;
										SetColor(15);
										system("PAUSE");
										break;
									}
								}
								
								system("cls");
								cout << "\t..Seleccione los productos de la lista disponible" << endl << endl ;
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
											SetColor(12);
											cout << "### LA CANTIDAD DEBE SER MAYOR QUE 0 ###" << endl;
											SetColor(15);
											cout << "\t..Ingrese la cantidad:" << endl;
										}
									}while(cant<=0);
								
									
									cout << "\t..Desea confirmar?(1 , 0)" << endl;
									cin >> agregar;
									if(agregar==1){
										
										s->ingresarProducto(id,cant);
									
									}
									else{
										SetColor(12);
										cout << "### PRODUCTO NO AGREGADO ###" << endl;	
										SetColor(15);
									}
									cout << "\t..Ingrese el  producto(Ingrese 0 para terminar)" << endl;
									cin >> id;
							
						
								}while(id!=0);
							
								
								cout << endl << "### REPARTIDORES ###" << endl << endl;
								ICollection * emp = s->mostrarRepartidores();
								
								IIterator * it = emp->getIterator();
								if(!it->hasCurrent()){
									SetColor(12);
									cout << "### NO HAY REPARTIDORES EN EL SISTEMA ###" << endl;
									SetColor(15);
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
										s->crearVdomicilio(repartidor,telefono);
										SetColor(10);
										cout << "### SE CREO LA VENTA ###" << endl;
										SetColor(15);
										correct=true;
									}
									else{
										if(s1=="NO" || s1=="No" || s1=="no"){
											SetColor(12);
											cout << "### NO SE CREO LA VENTA ###" << endl;
											SetColor(15);
											correct=true;
										}
										else{
											SetColor(12);
											cout <<  "### OPCION INCORRECTA ###" << endl;
											SetColor(15);
										}
									}	
								
								}while(correct==false);
								
								s->liberarMemoria();
								
								
								system("Pause");
								
								
								break;
							}
							case 8:{
								system("cls");
								cout << "### CONSULTAR PEDIDOS DE UN REPARTIDOR ###" << endl;
								cout << endl << "\t..Ingresar el id del repartidor:" << endl;
								int rep;
								cin >>rep;
								ICollection * pedidos = s->getTodosPedidos(rep);
								IIterator * it = pedidos->getIterator();
								if(!it->hasCurrent()){
									SetColor(12);
									cout << "### EL REPARTIDOR NO TIENE ENTREGAS PENDIENTES ###" << endl;
									SetColor(15);	
									delete it,pedidos;
									system("PAUSE");
									break;
								}
								system("cls");
								cout << endl << "### VENTAS DEL REPARTIDOR ###" << endl;
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
									SetColor(10);
									cout << endl << "### MESA CREADA ###" << endl;
									SetColor(15);
									Sleep(2000);
									break;
								}catch(char const * msg){
										SetColor(12);
										cout << msg << endl;
										SetColor(15);
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
									SetColor(10);
									cout << endl << "### LA MESA SE A AGREGADO AL MOZO ###" << endl;
									SetColor(15);
									s->liberarMemoria();
									system("PAUSE");
									break;	
								
								
							}							
							case 11:{
								s->asignarMesasAutomatico();
								SetColor(10);
								cout << "### LAS MESAS HAN SIDO ASIGNADAS ###" << endl;
								SetColor(15);
								system("PAUSE");
								break;
							}
							
							case 12:
								back=true;
								break;
							default:
								SetColor(12);
								cout << "### OPCION INCORRECTA ###" << endl;
								SetColor(15);
								Sleep (2000);
								system("cls");
						}	
						
					}catch(char const * msg){
						SetColor(12);
						cout << msg  << endl;
						SetColor(15);
						system("PAUSE");
					}	
				}while((opc<13 || opc>0) && !back);
					break;
				}
				case 2:{
						do{
							try{
							system("cls");
							opc = menuMozo();
							switch(opc){
								case 1:{
									ICollection * mozos = s->mostrarMozos();
									IIterator * it = mozos->getIterator();
									if(!it->hasCurrent()){
										SetColor(12);
										cout << "### NO HAY MOZOS EN EL SISTEMA ###" << endl;
										SetColor(15);
										delete mozos,it;
										system("PAUSE");
										break;
									}
									cout << endl << "###INICIAR VENTA EN MESA###" << endl << endl;
									
								
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
									cout << endl << "\t..Seleccione en que mesas iniciar la venta. Para terminar ingrese 0" << endl << endl;
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
										SetColor(12);
										cout << endl << "### NO SE INICIO LA VENTA ###" << endl;
										SetColor(15);
									}
									else{
											
										int dia, mes, anio,hora,minutos;  
										time_t tiempo = time (NULL);  
										struct tm *fecha = localtime (&tiempo); 
										dia=fecha->tm_mday;
										mes=fecha->tm_mon+1;
										anio= fecha->tm_year+1900;	
										hora=fecha->tm_hour;
										minutos=fecha->tm_min;							
										s->confirmarSeleccion(selec,new DtFecha(anio,mes,dia,hora,minutos));
										s->liberarMemoria();
										SetColor(10);
										cout << endl << "### SE INICIO LA VENTA ###" << endl;
										SetColor(15);
									}	
									Sleep (2000);
									break;
								}
								
								case 2:{
										//Agregar Producto a una venta
									s->liberarMemoria();
									ICollection * p = s->mostrarProductos();
									IIterator * it = p->getIterator();
									if(!it->hasCurrent()){
										SetColor(12);
										cout << "### NO EXISTEN PRODUCTOS EN EL SISTEMA ###" << endl;
										SetColor(15);
										system("PAUSE");
										delete it, p;
										break;
									}
									
									ICollection * mes=s->mesasconVenta();
									IIterator * itm = mes->getIterator();
									if(!itm->hasCurrent()){
										SetColor(12);
										cout << "### NO EXISTEN MESAS CON VENTAS INICIADAS ###" << endl;
										SetColor(15);
										system("PAUSE");
										delete itm,it, mes,p;
										break;
									}
									cout << endl << "### INGRESAR PRODUCTO A UNA VENTA ###" << endl;
									cout << endl << "\t..Ingrese la mesa a agregar" << endl;
									while(itm->hasCurrent()){
										DtMesa * mesa = (DtMesa *) itm->getCurrent();
										cout << "Mesa #" << mesa->getId() << endl;
										itm->next();
										delete mesa;
									}
									delete itm, mes;
									
									
									cin>>opc;
									if(!checkNum()){
										break;
									}
									s->ingresarMesa(opc);
									cout << "\t..Seleccione los productos de la lista disponible" << endl << endl ;
									
									
									
									while(it->hasCurrent()){
									
										DtProducto * dp = (DtProducto *) it->getCurrent();
										cout << endl << endl << "\t ..Codigo: " << dp->getCodigo() << endl;
										cout << "\t ..Nombre del Producto: " << dp->getDescripcion() << endl;
										cout << "\t ..Precio: " << dp->getPrecio() << endl;
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
											SetColor(12);
											cout << "### LA CANTIDAD DEBE SER MAYOR QUE 0 ###";
											SetColor(15);
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
											SetColor(12);
											cout << "### PRODUCTO NO AGREGADO ###" << endl;	
											SetColor(15);
										}
										cout << "\t..Ingrese el  producto(Ingrese 0 para terminar)" << endl;
										cin >> id;
								
									}while(id!=0);
									s->liberarMemoria();
									break;
								}
									
								case 3:{
									
									ICollection * mes=s->mesasconVenta();
									IIterator * itm = mes->getIterator();
									if(!itm->hasCurrent()){
										SetColor(12);
										cout << "### NO EXISTEN MESAS CON VENTAS INICIADAS ###" << endl;
										SetColor(15);
										system("PAUSE");
										delete itm, mes;
										break;
									}
									
									cout << endl << "### QUITAR PRODUCTO A UNA VENTA ### "<<endl;
									cout << endl << "\t..Ingrese la mesa a quitar" << endl;
									
									
									while(itm->hasCurrent()){
										DtMesa * mesa = (DtMesa *) itm->getCurrent();
										cout << "Mesa #" << mesa->getId() << endl;
										itm->next();
										delete mesa;
									}
									delete itm, mes;
									
									
									cin>>opc;
									if(!checkNum()){
										break;
									}
									s->ingresarMesa(opc);
									ICollection * p = s->mostrarProdVenta(opc);
									IIterator * it = p->getIterator();
									if(!it->hasCurrent()){
										SetColor(12);
										cout << "### LA VENTA NO TIENE PRODUCTOS ###" << endl;
										SetColor(15);
										system("PAUSE");
										delete it,p;
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
									delete p, it;
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
										SetColor(12);
										cout << "### LA CANTIDAD DEBE SER MAYOR QUE 0 ###";
										SetColor(15);
										break;
									}
									bool ch = s->check_prod_venta(id);
									
									cout << "\t..Desea confirmar?(1 , 0)" << endl;
									cin >> agregar;
									if(agregar==1){
										if(ch==true){
											s->modificarCantidad(id,cant,"resta");
											SetColor(10);
											cout << "### SE HA ELIMINADO EL PRODUCTO DE LA VENTA ###" << endl;
											SetColor(15);
										}
										
										else{
											SetColor(12);
											cout << "### EL PRODUCTO SELECCIONADO NO SE ENCUENTRA EN LA VENTA ###" << endl;
											SetColor(15);
										}
										
										Sleep(2000);
										
									}
									else{
										SetColor(12);
										cout << "### NO SE HA QUITADO EL PRODUCTO ###" << endl;
										SetColor(15);
									}
									
							
									break;
								}
								case 4:{
									ICollection * mes=s->mesasconVenta();
									IIterator * itm = mes->getIterator();
									if(!itm->hasCurrent()){
										SetColor(12);
										cout << "### NO EXISTEN MESAS CON VENTAS INICIADAS ###" << endl;
										SetColor(15);
										system("PAUSE");
										delete itm, mes;
										break;
									}
									cout << endl << "### EMITIR FACTURA ###" << endl;
									cout << endl << "\t..Ingrese la mesa a facturar" << endl;
									
									while(itm->hasCurrent()){
										DtMesa * mesa = (DtMesa *) itm->getCurrent();
										cout << "Mesa #" << mesa->getId() << endl;
										itm->next();
										delete mesa;
									}
									delete itm, mes;
									
									
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
										SetColor(12);
										cout << endl << "### LA MESA NO TIENE UNA VENTA EN CURSO O YA HA SIDO FACTURADA ###" << endl;
										SetColor(15);
									}
									system("Pause");
									break;
								}
									
								
									
								case 5:
									back=true;
									break;
								default:
									SetColor(12);
									cout << endl <<"### OPCION INCORRECTA ###" << endl;
									SetColor(15);
									Sleep (2000);
									system("cls");
							}
						}catch(char const * msg){
							SetColor(12);
							cout << msg << endl;
							SetColor(15);
							system("PAUSE");
						}		
					}while((opc<6 || opc>0) && !back);
					
					break; 
				}
				case 3:{
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
										SetColor(12);
										cout << "### EL REPARTIDOR NO TIENE ENTREGAS PENDIENTES ###" << endl;
										SetColor(15);
										delete pedidos,it;
										system("PAUSE");
										break;
									}
									cout << endl << "\t..Seleccione el pedido a modificar:(numero de venta)" << endl;
									
									
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
									DtFactura * df = s->cambiarEstado(id,opc,rep);
									SetColor(10);
									cout << "### SE HA ACTUALIZADO EL ESTADO ###" << endl;
									SetColor(15);
									
									if(df!=NULL){
										SetColor(10);
										cout << endl <<"### SE HA CREADO LA FACTURA CON LOS DATOS ###" << endl << endl;
										SetColor(15);
										
										
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
									system("PAUSE");
									break;
								}catch(char const * msg){
									SetColor(12);
									cout << msg << endl;
									SetColor(15);
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
				}
				case 4:{
					try{
					
						do{
							system("cls");
							opc = menuCliente();
							switch(opc){
								case 1:{
									ICollection * clientes = s->mostrarClientes();
									IIterator * itc = clientes->getIterator();
									if(!itc->hasCurrent()){
										SetColor(12);
										cout << "### NO HAY CLIENTES EN EL SISTEMA ###" << endl;
										SetColor(15);
										system("PAUSE");
										delete itc, clientes;
										break;
									}
									
									cout << endl <<"### CONSULTAR ACTUALIZACIONES DE PEDIDOS A DOMICILIO DE UN CLIENTE ###" <<endl << endl;
									
								
									cout << endl <<  "### Clientes ###" << endl;
									
									while(itc->hasCurrent()){
										DtCliente * dc = (DtCliente *) itc->getCurrent();
										cout << endl << "\t..Telefono: " << dc->getTelefono() << endl;
										cout << "\t..Nombre: " << dc->getNombre() << endl;
										DtDireccion * dd = dc->getDireccion();
										cout << "\t..Direccion: " << dd->getCalle() << "  " << dd->getNro() << endl << endl;
										cout << "          -------------------------" << endl;
										itc->next();
										
									}
									delete itc,clientes;
									
									cout << "\t..Ingrese el telefono del cliente a mostrar" << endl; 
									cin >> id;
									if(!checkNum){
										break;
									}
									ICollection * pedidos = s->getPedidosCliente(id);
									IIterator * it = pedidos->getIterator();
									if(!it->hasCurrent()){
										SetColor(12);
										cout << "### EL CLIENTE NO HA HECHO PEDIDOS ###" << endl;
										SetColor(15);
										delete pedidos,it;
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
											SetColor(12);
											cout << "### LA VENTA NO TIENE PRODUCTOS ###" << endl;
											SetColor(15);
											delete prods,itp;
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
											delete prods,itp;
												
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
					}catch(char const * msg){
						SetColor(12);
						cout << msg << endl;
						SetColor(15);
						system("PAUSE");
					}
						break;
				}				
				case 5:{
					if(venta){
						SetColor(12);
						cout << "### YA SE HAN CARGADO DATOS ###" << endl;
						SetColor(15);
						system("PAUSE");
						break;
					}
					if(datos){
						SetColor(12);
						cout << "### YA SE HAN CARGADO DATOS ###" << endl;
						SetColor(15);
						system("PAUSE");
						break;
					}
					s->cargarDatos("no");
					cargar=true;
					datos=true;
					break;
				}	
				case 6:{
					if(cargar){
						SetColor(12);
						cout << "### YA SE HAN CARGADO LOS DATOS SIN VENTAS, REINICIE EL SISTEMA ###" << endl;
						SetColor(15);
						system("PAUSE");
						break;
					}
					s->cargarDatos("si");
					SetColor(10);
					cout << "### SE HAN CARGADO LAS VENTAS EN EL SISTEMA ###" << endl;
					SetColor(15);
					cargar=true;
					venta=true;
					system("PAUSE");
					break;
				}
				case 7:{
					
						do{
							try{
								system("cls");
								opc = menuConsultas();
								switch(opc){
									case 1:{
										ICollection * facturas = s->getFacturas();
										IIterator * it = facturas->getIterator();
										if(!it->hasCurrent()){
											SetColor(12);
											cout << "### NO EXISTEN FACTURAS EN EL SISTEMA ###" << endl;
											SetColor(15);
											system("PAUSE");
											delete facturas,it;
											break;
										}
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
											cout << "Hora: " << dtf->getHora() << ":" << dtf->getMinutos() << endl << endl;
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
										ICollection * emp = s->getEmpleados();
										IIterator * it = emp->getIterator();
										if(!it->hasCurrent()){
											SetColor(12);
											cout << "### NO EXISTEN EMPLEADOS EN EL SISTEMA ###" << endl;
											SetColor(15);
											system("PAUSE");
											delete emp,it;
											break;
										}
										cout << "### EMPLEADOS ###" << endl << endl;
										
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
													cout << "          -------------------------" << endl;
													delete it_mesas; 
												}
												
											}
											else{
												cout << "Repartidor" << endl;
												cout << "\t..Medio de transporte: " << r1->getMedio() << endl;
												cout << "          -------------------------" << endl;
											}
											cout << endl << endl;
											it->next();
										}
										system("Pause");
										break;
									}
										
									case 3:{
										ICollection * mesas = s->getMesas();
										IIterator * it = mesas->getIterator();
										if(!it->hasCurrent()){
											SetColor(12);
											cout << "### NO EXISTEN MESAS EN EL SISTEMAS ###" << endl;
											SetColor(15);
											system("PAUSE");
											delete mesas,it;
											break;
										}
										cout << "### MESAS ###" << endl << endl;
										
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
										IIterator * it_p = prod->getIterator();
										if(!it_p->hasCurrent()){
											SetColor(12);
											cout << endl << "### NO EXISTEN PRODUCTOS EN EL SISTEMA ###" << endl;
											SetColor(15);
											system("PAUSE");
											delete prod, it_p;
											break;
										}
										
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
										ICollection * clientes = s->mostrarClientes();
										IIterator * it = clientes->getIterator();
										if(!it->hasCurrent()){
											SetColor(12);
											cout << "### NO HAY CLIENTES EN EL SISTEMA ###" << endl;
											SetColor(15);
											system("PAUSE");
											delete it, clientes;
											break;
										}
										cout << endl <<  "### Clientes ###" << endl;
										
										while(it->hasCurrent()){
											DtCliente * dc = (DtCliente *) it->getCurrent();
											cout << endl << "\t..Telefono: " << dc->getTelefono() << endl;
											cout << "\t..Nombre: " << dc->getNombre() << endl;
											DtDireccion * dd = dc->getDireccion();
											cout << "\t..Direccion: " << dd->getCalle() << "  " << dd->getNro() << endl << endl;
											
											DtApartamento * da = dynamic_cast<DtApartamento *>(dd);
											if(da!=NULL){
												cout << "\t..Edificio: " << da->getDpto() << endl << "\t..Piso: " << da->getPiso() << endl;
											}
											cout << "          -------------------------" << endl;
											it->next();
											
										}
										system("PAUSE");
										break;
									}
									
									case 6:{
										ICollection * ventas = s->getVentas();
										IIterator * it = ventas->getIterator();
										if(!it->hasCurrent()){
											SetColor(12);
											cout << endl << "### NO EXISTEN VENTAS EN EL SISTEMA ###" << endl;
											SetColor(15);
											delete it;
											delete ventas;
											system("PAUSE");
											break;
										}
										cout << endl << "### VENTAS ###" << endl;
										
										while(it->hasCurrent()){
											DtVenta * dv = (DtVenta*) it->getCurrent();
											ICollection * prods = dv->getProductos();
											DtCliente * dc = s->getCliente(dv->getCodigo());
										
											cout << endl << "Venta ";
											if(dc==NULL){
												cout << "(Local)";	
											}
											else{
												cout << "(Domicilio)";
											}
											cout <<" #" << dv->getCodigo() << endl;
											DtFecha * df = dv->getFecha();
											cout << "Fecha: " << df->getAnio() <<"-"<< df->getMes()<<"-" << df->getDia() << endl;
											cout << "Estado: " << dv->getEstado() << endl << endl;
											if(dc!=NULL){
												cout << "Cliente: " << dc->getNombre() << " -- Telefono: " << dc->getTelefono() << endl << endl;  
											}
											IIterator * itp = prods->getIterator();
											while(itp->hasCurrent()){
												DtProducto * dp = (DtProducto *) itp->getCurrent();
												cout << "\t ..Codigo: " << dp->getCodigo() << endl;
												cout << "\t ..Nombre del Producto: " << dp->getDescripcion() << endl;
												cout << "\t ..Precio: " << dp->getPrecio() << endl;
												cout << "\t ..Cantidad: " << dp->getCantidad() << endl;
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
								SetColor(12);
								cout << msg << endl;
								SetColor(15);
								system("PAUSE");
							}		
						}while((opc<8 || opc>0) && !back);
						break;
				
				}
				
				
				case 8:
					cout << "### Gracias por usar el sistema ###" << endl;
					return 0;
				default:
					cout << "Opcion incorrecta" << endl;
					Sleep (2000);
					system("cls");
			}
		}while(opc<9 || opc>0);
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
	cout << "6. Cargar ventas de prueba" << endl;
	cout << "7. Consultas" << endl;
	cout << "8. Salir" << endl << endl;
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
	cout << "3. Informacion de un producto" << endl;
	cout << "4. Alta empleado" << endl;
	cout << "5. Alta cliente" << endl;
	cout << "6. Resumen facturacion de 1 dia dada la fecha" << endl;
	cout << "7. Venta a domicilio" << endl;
	cout << "8. Consultar actualizaciones de pedidos a domicilio" << endl;
	cout << "9. Alta mesa" << endl;
	cout << "10. Agregar mozo a mesa" << endl;
	cout << "11. Asignar mozos a mesas automaticamente" << endl;
	cout << "12. Volver a menu anterior" << endl << endl;
	
	cout << "Ingrese la opcion:"; 
	cin >> opc;
	if(!checkNum()){
		return 0;
	}
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
	if(!checkNum()){
		return 0;
	}
	return opc;
}

int menuCliente(){
	int opc;
	cout << "\t **MENU CLIENTE***" << endl;
	cout << "1. Consultar actualizaciones de pedidos a domicilio" << endl;
	cout << "2. Volver a menu anterior" << endl << endl;
	cout << "Ingrese la opcion:"; 
	cin >> opc;
	if(!checkNum()){
		return 0;
	}
	return opc;
}

int menuRepartidor(){
	int opc;
	cout << "\t **MENU REPARTIDOR***" << endl;
	cout << "1. Modificar estado pedido" << endl;
	cout << "2. Volver a menu anterior" << endl << endl;
	cout << "Ingrese la opcion:"; 
	cin >> opc;
	if(!checkNum()){
		return 0;
	}
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
	if(!checkNum()){
		return 0;
	}
	return opc;
	
}

