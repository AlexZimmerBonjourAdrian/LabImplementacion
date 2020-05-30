#include <iostream>
#include <stdexcept>
using namespace std;

#define PAUSE "PAUSE"
#define CLEAR "CLS"

// include de Clases
#include "clases\h\Consulta.h"
#include "clases\h\Gato.h"
#include "clases\h\Mascota.h"
#include "clases\h\Perro.h"
#include "clases\h\Socio.h"
// include de DataTypes
#include "datatypes\h\DtConsulta.h"
#include "datatypes\h\DtFecha.h"
#include "datatypes\h\DtGato.h"
#include "datatypes\h\DtMascota.h"
#include "datatypes\h\DtPerro.h"
// enumerados (que en realidad son arrays constantes)
#include "enums\Enums.h"

void registrarSocio(string, string, const DtMascota &);
void eliminarSocio(string);
void agregarMascota(string, const DtMascota&);
void eliminarMascota(string, string);
DtMascota** obtenerMascotas(string, int&);
void ingresarConsulta(string motivo, string ci);
DtConsulta** verConsultasAntesDeFecha(const DtFecha&, string, int&);

Socio* socioExiste(string);


#define MAX_SOCIOS	100
Socio* socios[MAX_SOCIOS];
int cantSocios = 0;

/*
#############   COSAS A IMPLEMENTAR:   ############
Socio:	bool mascotaExiste(string nombre) devuelve true si ya existe una mascota con ese nombre
		bool puedeAgregarMascota() devuelve true si hay lugar en el array para agregar mas mascotas
		void agregarMascota(DtMascota) agrega mascota al array de mascotas
		void eliminarMascota(string nombre) busca el nombre de la mascota y la borra del array (reorganizandolo para que no queden huecos)
		DtMascota** obtenerMascotas(int& cantElem) devuelve un array de punteros DtMascota con los datos de las mascotas. cantMascotas se modificara segun la cantidad de elementos devueltos
		bool puedeAgregarConsulta() devuelve true si hay lugar en el array para agregar mas consultas
		void agregarConsulta(DtConsulta) agrega una consulta al array de consultas
		DtConsulta** obtenerConsultas(int& cantElem) devuelve un array de punteros DtConsulta con las consultas. cantMascotas se modificara segun la cantidad de elementos devueltos
		~Socio debe borrar las mascotas y consultas...
Consulta	
Mascota		
Gato		obtenerRacionDiaria() usa una constante que QUIZA deba declararse como #define o constante en el .h
Perro		obtenerRacionDiaria() usa una constante que QUIZA deba declararse como #define o constante en el .h

DtConsulta	sobrecarga de operador <<, mostrar con formato:
				Fecha: xx/xx/xxxx (el DtFecha ya posee la sobrecarga para mostrar en formato xx/xx/xxxx)
				Motivo: xxxxxxxxxxxxxxxxxxxx
DtMascota	
DtPerro		sobrecarga de operador <<, mostrar con formato: (se puede usar funciones mostrar de Enum.h)
				------ Perro ------
				Nombre: xxxx
				Género: xxxx
				Peso: xxxx kg
				Ración Diaria: xxx gramos.
				Tiene vacuna del Cachorro: Si / No
DtGato		sobrecarga de operador <<, mostrar con formato: (se puede usar funciones mostrar de Enum.h)
			------ Gato ------
			Nombre: xxxx
			Género: xxxx
			Peso: xxxx kg
			Ración Diaria: xxx gramos.
			Tipo de pelo: xxxx
DtFecha 	
########################################################
*/


int main() {
	string opcion;
	
	do{
		try{
			opcion = "";
			system(CLEAR);
			cout << "-------- Bienvenido --------"	<< endl;
			cout << "1- Alta de socio" 				<< endl;
			cout << "2- Baja de socio" 				<< endl;
			cout << "3- Alta de mascota de socio" 	<< endl;
			cout << "4- Baja de mascota de socio" 	<< endl;
			cout << "5- Ingresar consulta" 			<< endl;
			cout << "6- Listar consultas de socio" 	<< endl;
			cout << "7- Listar mascotas de socio" 	<< endl;
			cout << "0- Salir" 						<< endl;
			getline(cin, opcion);
			system(CLEAR);
			
			if (opcion == "1"){	// Alta de socio
				string ci, nombre, tipoMascota, nombreMascota, genero;
				float peso;
				
				cout << "---------- Alta de socio ----------"	<< endl;
				cout << "Ingrese los datos del nuevo socio" << endl;
				cout << "-CI: ";		getline(cin, ci);
				if (socioExiste(ci) != NULL ){	// verifica si el socio existe
					cout << "ERROR: El socio no existe" << endl;
					system(PAUSE);
					continue;
				}
				cout << "-Nombre: ";	getline(cin, nombre);
				
				cout << "Ingrese los datos de la mascota" << endl;
				do{	// solicita tipo de mascota hasta que la entrada sea valida
					cout << "Tipo de mascota (" << listaDeOpciones(eTipoMascota, CANT_TIPO_MASCOTA) << "): "; getline(cin, tipoMascota);
				}while(tipoMascotaValido(tipoMascota) == -1);
				
				cout << "-Nombre: ";	getline(cin, nombreMascota);
				
				do{	// solicita genero de mascota hasta que la entrada sea valida
					cout << "-Genero (" << listaDeOpciones(eGenero, CANT_GENERO) << "): "; getline(cin, genero);
				}while(generoValido(genero) == -1);
				
				do {
					cout << "-Peso: ";	cin >> peso;
					if (cin.fail()){	// si se ingresa algo que no es float
						cin.clear(); 
						cin.ignore(INT_MAX, '\n');
					}else{
						break;
					}
				}while(true);
				cin.ignore();
				
				// se piden los datos especificos segun el tipo de mascota
				if (tipoMascotaValido(tipoMascota) == tipoMascotaValido("gato")){	// si es gato
					string tipoPelo;
					
					do{	// solicita tipo de pelo de mascota hasta que la entrada sea valida
						cout << "-Tipo de pelo (" << listaDeOpciones(eTipoPelo, CANT_TIPO_PELO) << "): "; getline(cin, tipoPelo);
					}while(tipoPeloValido(tipoPelo) == -1);
					
					DtGato gato = DtGato(
						nombreMascota, 
						generoValido(genero), 
						 peso, 
						 tipoPeloValido(tipoPelo)
					);
					registrarSocio(ci, nombre, gato);
				}else
				if (tipoMascotaValido(tipoMascota) == tipoMascotaValido("perro")){	// si es perro
					string raza, sino;
					
					do{	// solicita raza de mascota hasta que la entrada sea valida
						cout << "-Raza (" << listaDeOpciones(eRazaPerro, CANT_RAZA_PERRO) << "): "; getline(cin, raza);
					}while(razaPerroValido(raza) == -1);
					
					do{	// solicita vacuna de mascota hasta que la entrada sea valida
						cout << "-Vacuna de cachorro (" << listaDeOpciones(eSiNo, CANT_SI_NO) << "): "; getline(cin, sino);
					}while(siNoValido(sino) == -1);
					
					DtPerro perro = DtPerro(
						nombreMascota, 
						generoValido(genero), 
						 peso, 
						razaPerroValido(raza), 
						siNoValido(sino)
					);
					registrarSocio(ci, nombre, perro);
				}
			}
			else if (opcion == "2"){	// Baja de socio
				string ci;
				
				cout << "---------- Baja de socio ----------"	<< endl;
				cout << "Ingrese los datos" << endl;
				cout << "-CI del socio: ";	getline(cin, ci);
				eliminarSocio(ci);
			}
			else if (opcion == "3"){	// Alta de mascota de socio
				string ci, nombre, tipoMascota, nombreMascota, genero;
				float peso;
				
				cout << "---------- Alta de mascota --------" 	<< endl;
				cout << "Ingrese los datos" << endl;
				cout << "-CI del socio: ";		getline(cin, ci);
				if (socioExiste(ci) == NULL ){	// verifica si el socio existe
					cout << "ERROR: El socio no existe" << endl;
					system(PAUSE);
					continue;
				}
				
				do{	// solicita tipo de mascota hasta que la entrada sea valida
					cout << "Tipo de mascota (" << listaDeOpciones(eTipoMascota, CANT_TIPO_MASCOTA) << "): "; getline(cin, tipoMascota);
				}while(tipoMascotaValido(tipoMascota) == -1);
				
				cout << "-Nombre: ";	getline(cin, nombreMascota);
				
				do{	// solicita genero de mascota hasta que la entrada sea valida
					cout << "-Genero (" << listaDeOpciones(eGenero, CANT_GENERO) << "): "; getline(cin, genero);
				}while(generoValido(genero) == -1);
				
				do {
					cout << "-Peso: ";	cin >> peso;
					if (cin.fail()){	// si se ingresa algo que no es float
						cin.clear(); 
						cin.ignore(INT_MAX, '\n');
					}else{
						break;
					}
				}while(true);
				cin.ignore();
				
				// se piden los datos especificos segun el tipo de mascota
				if (tipoMascotaValido(tipoMascota) == tipoMascotaValido("gato")){	// si es gato
					string tipoPelo;
					
					do{	// solicita tipo de pelo de mascota hasta que la entrada sea valida
						cout << "-Tipo de pelo (" << listaDeOpciones(eTipoPelo, CANT_TIPO_PELO) << "): "; getline(cin, tipoPelo);
					}while(tipoPeloValido(tipoPelo) == -1);
					
					DtGato gato = DtGato(
						nombreMascota, 
						generoValido(genero), 
						 peso, 
						 tipoPeloValido(tipoPelo)
					);
					registrarSocio(ci, nombre, gato);
				}else
				if (tipoMascotaValido(tipoMascota) == tipoMascotaValido("perro")){	// si es perro
					string raza, sino;
					do{	// solicita raza de mascota hasta que la entrada sea valida
						cout << "-Raza (" << listaDeOpciones(eRazaPerro, CANT_RAZA_PERRO) << "): "; getline(cin, raza);
					}while(razaPerroValido(raza) == -1);
					
					do{	// solicita vacuna de mascota hasta que la entrada sea valida
						cout << "-Vacuna de cachorro (" << listaDeOpciones(eSiNo, CANT_SI_NO) << "): "; getline(cin, sino);
					}while(siNoValido(sino) == -1);
					
					DtPerro perro = DtPerro(
						nombreMascota, 
						generoValido(genero), 
						 peso, 
						razaPerroValido(raza), 
						siNoValido(sino)
					);
					registrarSocio(ci, nombre, perro);
				}
			}
			else if (opcion == "4"){	// Baja de mascota de socio
				string ci, nombreMascota;
				
				cout << "--------- Baja de mascota ---------" 	<< endl;
				cout << "Ingrese los datos" << endl;
				cout << "-CI del socio: ";			getline(cin, ci);
				if (socioExiste(ci) == NULL ){	// verifica si el socio existe
					cout << "ERROR: El socio no existe" << endl;
					system(PAUSE);
					continue;
				}
				
				cout << "-Nombre de la mascota: ";	getline(cin, nombreMascota);
				
				eliminarMascota(ci, nombreMascota);
			}
			else if (opcion == "5"){	// Ingresar consulta
				string ci, motivo;
				
				cout << "------- Ingreso de consulta -------" 	<< endl;
				cout << "Ingrese los datos" << endl;
				cout << "-CI de socio: ";			getline(cin, ci);
				if (socioExiste(ci) == NULL ){	// verifica si el socio existe
					cout << "ERROR: El socio no existe" << endl;
					system(PAUSE);
					continue;
				}
				
				cout << "-Motivo de consulta: ";	getline(cin, motivo);
				
				ingresarConsulta(motivo, ci);
			}
			else if (opcion == "6"){	// Listar consultas de socio
				string ci;
				//DtFecha fecha;
				int dia, mes, anio, cantConsultas;
				DtConsulta** consultas;
				
				cout << "------ Listado de consultas -------" 	<< endl;
				cout << "Ingrese los datos" << endl;
				cout << "-CI de socio: ";	getline(cin, ci);
				if (socioExiste(ci) == NULL ){	// verifica si el socio existe
					cout << "ERROR: El socio no existe" << endl;
					system(PAUSE);
					continue;
				}
				
				do {	// solicita el dia hasta que sea valido
				cout << "-Dia: ";	cin >> dia;
					if (cin.fail()){	// si se ingresa algo que no es int
						cin.clear(); 
						cin.ignore(INT_MAX, '\n');
					}
					break;
				}while(true);
				
				do {	// solicita el mes hasta que sea valido
					cout << "-Mes: ";	cin >> mes;
					if (cin.fail()){	// si se ingresa algo que no es int
						cin.clear(); 
						cin.ignore(INT_MAX, '\n');
					}
					break;
				}while(true);
				do {	// solicita el anio hasta que sea valido
					cout << "-Anio: ";	cin >> anio;
					if (cin.fail()){	// si se ingresa algo que no es int
						cin.clear(); 
						cin.ignore(INT_MAX, '\n');
					}
					break;
				}while(true);
				
				consultas = verConsultasAntesDeFecha(DtFecha(dia, mes, anio), ci, cantConsultas);
				
				printf("Codigo comentado, main : 6, falta sobrecarga de DtConsulta");
				for (int i = 0; i < cantConsultas; i++){
					//cout << *consultas[i] << endl;
				}
			}
			else if (opcion == "7"){	// Listar mascotas de socio
				string ci;
				//DtMascota** mascotas;
				int cantMascotas;
				
				cout << "------- Listado de mascotas -------" 	<< endl;
				cout << "Ingrese los datos" << endl;
				cout << "-CI de socio: ";	getline(cin, ci);
				if (socioExiste(ci) == NULL ){	// verifica si el socio existe
					cout << "ERROR: El socio no existe" << endl;
					system(PAUSE);
					continue;
				}
				
				DtMascota** mascotas = obtenerMascotas(ci, cantMascotas);
				
				printf("Codigo comentado, main : 7, falta sobrecarga de DtPerro y DtGato");
				for (int i = 0; i < cantMascotas; i++){
					if (dynamic_cast<DtGato*>(mascotas[i])){
						cout << (DtGato*) mascotas[i] << endl;
					}else{
						cout << (DtPerro*) mascotas[i] << endl;
					}
				}
			}
			else if (opcion == "0"){	// Salir
				
			}
			
			// si hubo algun error al ingresar y convertir los datos
			if (cin.fail()){
				cin.clear();	// limpia los errores
				cin.ignore(INT_MAX, '\n');
				throw invalid_argument("Uno o mas datos ingresados no pudo ser procesado");
			}
		}catch(invalid_argument &ia) {
            cout << "ERROR: " << ia.what() << endl;
            system(PAUSE);
        }
        
        printf("borrar PAUSE al final del while\n");
        system(PAUSE);
	}while (opcion != "0");
	return 0;
}


void registrarSocio(string ci, string nombre, const DtMascota& dtMascota){
	// Registra un socio con su mascota. El valor el atributo racionDiaria se debe setear en 0
	if (cantSocios == MAX_SOCIOS)	throw invalid_argument("No se pueden agregar mas socios");
	
	Socio *s = socioExiste(ci);
	if (s != NULL)	throw invalid_argument("El socio ya esta registrado");
	
	socios[cantSocios] = new Socio(ci, nombre, DtFecha(), dtMascota);
	cantSocios++;
}


void eliminarSocio(string ci){
	// Elimina al socio, sus consultas y sus mascotas. Si no existe un socio registrado con esa cedula, se levanta una excepcion std::invalid_argument
	// verifica que el socio exista
	Socio* sEliminar = socioExiste(ci);
	if (sEliminar == NULL)	throw invalid_argument("El socio no existe");
	
	// s es la posicion del array que ocupa el socio a eliminar
	int s = 0;
	while (socios[s] != sEliminar)	s++;
	
	// como no importa el orden en que se agregaron los socios, pongo el ultimo donde esta s
	printf("Se invoca al destructor de socio que aun no esta hecho.\n Asi que si falla ahora, es normal\n");
	delete socios[s];
	socios[s] = socios[cantSocios-1];
	cantSocios--;
}


void agregarMascota(string ci, const DtMascota& dtMascota){
	// Agrega una nueva mascota a un socio ya registrado. Si no existe un socio registrado con esa cedula, se levanta una excepcion std::invalid_argument
	
	Socio *s = socioExiste(ci);
	if (s == NULL)	throw invalid_argument("El socio no existe");
	
	printf("lineas comentada: main : agregarMascota(..)\n");
	//if (!s->puedeAgregarMascota())	throw invalid_argument("El socio ya posee el maximo de mascotas");
	
	//s->agregarMascota(dtMascota);
}


void eliminarMascota(string ci, string nombreMascota){
	// elimina la mascota de nombre nombreMascota del socio con cedula ci
	Socio* s = socioExiste(ci);
	if (s == NULL)	throw invalid_argument("El socio no existe");
	
	printf("lineas comentada: main : eliminarMascota(..)\n");
	//if (!s->mascotaExiste)	throw invalid_argument("La mascota no existe");
	//s->eliminarMascota(nombreMascota);
	
}


DtMascota** obtenerMascotas(string ci, int& cantMascotas){
	// Devuelve un arreglo con las mascotas del socio. El largo del arreglo esta dado por el parametro cantMascotas. Si no existe un socio registrado con esa cedula, se levanta una excepcion std::invalid_argument
	Socio *s = socioExiste(ci);
	if (s == NULL)	throw invalid_argument("El socio no existe");
	
	printf("lineas comentada: main : obtenerMascotas(..)\n");
	//DtMascota** mascotas = s->obtenerMascotas(cantMascotas);
	DtMascota** mascotas = NULL;	// provisoio
	cantMascotas = 0;	// provisoio
	
	// mascotas[] tiene todas las mascotas
	return mascotas;
}


void ingresarConsulta(string motivo, string ci){
	// Crea una consulta con un motivo para un socio. Si no existe un socio registrado con esa cedula, se levanta una excepcion std::invalid_argument
	
	Socio *s = socioExiste(ci);
	if (s == NULL)	throw invalid_argument("El socio no existe");
	
	printf("lineas comentada: main : ingresarConsulta(..)\n");
	//if (!s->puedeAgregarConsulta())	throw invalid_argument("El socio ya posee el maximo de consultas");
	
	//s->agregarConsulta(obtenerFechaActual(), motivo);
}


DtConsulta** verConsultasAntesDeFecha(const DtFecha& fecha, string ci, int& cantConsultas){
	// Devuelve las consultas antes de cierta fecha. El largo del arreglo esta dadopor el parametro cantConsultas
	
	Socio *s = socioExiste(ci);
	if (s == NULL)	throw invalid_argument("El socio no existe");
	
	printf("lineas comentada: main : verConsultasAntesDeFecha(..)\n");
	//DtConsulta** consultas = s->obtenerConsultas(cantConsultas);
	DtConsulta** consultas = NULL;	// provisoio
	cantConsultas = 0;	// provisoio
	
	// consultas[] tiene todas las consultas, hay que  quedarse solo con las que cumplen la condicion de la fecha
	// Las consultas vienen ordenadas de antiguas a nuevas, i avanza hasta que encuentra la primera que esta pasada de fecha
	int i;
	for (i = 0; i < cantConsultas; i++){
		if (!(consultas[i]->getFecha() < fecha))	break;
	}
	// desde i hasta el final, hay que borrar las consultas porque no cumplen la consicion
	for (int aux = i; aux < cantConsultas; aux++){
		delete consultas[aux];
	}
	
	cantConsultas = i;
	return consultas;
}

//////////////////////////////////////////////////////////////////////////////////
Socio* socioExiste(string ci){
	// si el socio no existe devuelve NULL
	for (int i = 0; i < cantSocios; i++){
		if (ci == socios[i]->getCi())	return socios[i];
	}
	return NULL;
}










