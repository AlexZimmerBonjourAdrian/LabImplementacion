#include <iostream>
#include <string>
#include <time.h>
#include <windows.h>

using namespace std;

int menu();
int menuMozo();
int menuAdministrador();
int menuCliente();
int menuRepartidor();

int main(){
	int opc;
	//int mozopc;
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
						case 1:
							cout <<"Alta producto no implementado" <<endl;
							Sleep (2000);
							break;
						case 2:
							cout <<"Baja producto no implementado" <<endl;
							Sleep (2000);
							break;
						case 3:
							cout <<"Infromación de un producto no implementado" <<endl;
							Sleep (2000);
							break;
						case 4:
							cout <<"Alta empleado no implementado" <<endl;
							Sleep (2000);
							break;
						case 5:
							cout <<"Asignar mozos a mesas no implementado" <<endl;
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
						case 9:
							back=true;
							break;
						default:
							cout << "Opcion incorrecta" << endl;
							Sleep (2000);
							system("cls");
					}		
				}while((opc<10 || opc>0) && !back);
				break;
			case 2:
				do{
					system("cls");
					opc = menuMozo();
					switch(opc){
						case 1:
							cout <<"Iniciar venta mesa no implementado" <<endl;
							Sleep (2000);
							break;
						case 2:
							cout <<"Agregar producto a una venta no implementado" <<endl;
							Sleep (2000);
							break;
						case 3:
							cout <<"Quitar producto a una venta no implementado" <<endl;
							Sleep (2000);
							break;
						case 4:
							cout <<"Facturación de una venta no implementado" <<endl;
							Sleep (2000);
							break;
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
			case 6:
				cout << "Gracias por usar el sistema" << endl;
				return 0;
			default:
				cout << "Opcion incorrecta" << endl;
				Sleep (2000);
				system("cls");
		}
	}while(opc<7 || opc>0);
	return 0;
}

int menu(){
	int opc;
	cout << "\t ***MENU***" << endl;
	cout << "1. Administrador" << endl;
	cout << "2. Mozo" << endl;
	cout << "3. Repartidor" << endl;
	cout << "4. Cliente" << endl;
	cout << "5. Cargar datos de prueba" << endl;
	cout << "6. Salir" << endl << endl;
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
	cout << "9. Volver a menu anterior" << endl << endl;
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


