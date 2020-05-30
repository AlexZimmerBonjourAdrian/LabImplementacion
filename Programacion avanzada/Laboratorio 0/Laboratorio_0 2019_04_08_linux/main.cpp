#include <iostream>
#include <stdexcept>
using namespace std;

//////////////////////////////////////////////////////////////////////////
#define PAUSE "PAUSE"
#define CLEAR "clear"
// include de Clases
#include "clases/h/Consulta.h"
#include "clases/h/Gato.h"
#include "clases/h/Mascota.h"
#include "clases/h/Perro.h"
#include "clases/h/Socio.h"
// include de DataTypes
#include "datatypes/h/DtConsulta.h"
#include "datatypes/h/DtFecha.h"
#include "datatypes/h/DtGato.h"
#include "datatypes/h/DtMascota.h"
#include "datatypes/h/DtPerro.h"
// enumerados (que en realidad son arrays constantes)
#include "enums/Enums.h"
//////////////////////////////////////////////////////////////////////////

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

void cargarDatosDePrueba(){
	// perros
	DtPerro p1 = DtPerro("perro_1", 0, 1.1, 0, 0);
	DtPerro p2 = DtPerro("perro_2", 1, 2.2, 1, 1);
	DtPerro p3 = DtPerro("perro_3", 0, 3.3, 2, 0);
	DtPerro p4 = DtPerro("perro_4", 1, 4.4, 3, 1);
	// gatos
	DtGato g1 = DtGato("gato_1", 0, 5.5, 0);
	DtGato g2 = DtGato("gato_2", 1, 6.6, 0);
	DtGato g3 = DtGato("gato_3", 0, 7.7, 1);
	DtGato g4 = DtGato("gato_4", 1, 8.8, 2);
	// consultas
	DtConsulta c1 = DtConsulta(DtFecha(1,3,2016), "consulta1");
	DtConsulta c2 = DtConsulta(DtFecha(2,6,2016), "consulta2");
	DtConsulta c3 = DtConsulta(DtFecha(3,5,2017), "consulta3");
	DtConsulta c4 = DtConsulta(DtFecha(4,9,2017), "consulta4");
	DtConsulta c5 = DtConsulta(DtFecha(5,2,2017), "consulta5");
	DtConsulta c6 = DtConsulta(DtFecha(6,4,2018), "consulta6");
	DtConsulta c7 = DtConsulta(DtFecha(7,7,2018), "consulta7");
	DtConsulta c8 = DtConsulta(DtFecha(8,9,2018), "consulta8");
	// creando un socio
	registrarSocio("1111", "socio1", p1);
	agregarMascota("1111", g2);
	agregarMascota("1111", p3);
	agregarMascota("1111", g4);
	socioExiste("1111")->agregarConsulta(c1);
	socioExiste("1111")->agregarConsulta(c2);
	socioExiste("1111")->agregarConsulta(c3);
	socioExiste("1111")->agregarConsulta(c4);
	socioExiste("1111")->agregarConsulta(c5);
	socioExiste("1111")->agregarConsulta(c6);
	socioExiste("1111")->agregarConsulta(c7);
	socioExiste("1111")->agregarConsulta(c8);
	// creando otro socio
	registrarSocio("2222", "socio2", g1);
	agregarMascota("2222", p2);
	agregarMascota("2222", g3);
	agregarMascota("2222", p4);
	socioExiste("2222")->agregarConsulta(c1);
	socioExiste("2222")->agregarConsulta(c2);
	socioExiste("2222")->agregarConsulta(c3);
	socioExiste("2222")->agregarConsulta(c4);
	socioExiste("2222")->agregarConsulta(c5);
	socioExiste("2222")->agregarConsulta(c6);
	socioExiste("2222")->agregarConsulta(c7);
	socioExiste("2222")->agregarConsulta(c8);
}


int main() {
	string opcion;
	
	try{
		cargarDatosDePrueba();
		cout << "Se han cargado datos de prueba" << endl;
	}catch(invalid_argument &ia) {
        cout << "ERROR: " << ia.what() << endl;
    }
	cout << "Presione una tecla para continuar..." << endl;
	cin.get();
	
	
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
			cout << "8- Listar socios" 	<< endl;
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
					cout << "Presione una tecla para continuar..." << endl;
					cin.get();
					continue;
				}
				cout << "-Nombre: ";	getline(cin, nombre);
				
				cout << "Ingrese los datos de la mascota" << endl;
				do{	// solicita tipo de mascota hasta que la entrada sea valida
					cout << "Tipo de mascota (" << listaDeOpciones(eTipoMascota, CANT_TIPO_MASCOTA) << "): ";
					getline(cin, tipoMascota);
				}while(tipoMascotaValido(tipoMascota) == -1);
				
				cout << "-Nombre: ";	getline(cin, nombreMascota);
				
				do{	// solicita genero de mascota hasta que la entrada sea valida
					cout << "-Genero (" << listaDeOpciones(eGenero, CANT_GENERO) << "): ";
					getline(cin, genero);
				}while(generoValido(genero) == -1);
				
				do {
					cout << "-Peso: ";	cin >> peso;
					if (cin.fail()){	// si se ingresa algo que no es float
						cin.clear();
						fflush(stdin);
					}else{
						fflush(stdin);
						break;
					}
				}while(true);
				
				// se piden los datos especificos segun el tipo de mascota
				if (tipoMascotaValido(tipoMascota) == tipoMascotaValido("gato")){	// si es gato
					string tipoPelo;
					
					do{	// solicita tipo de pelo de mascota hasta que la entrada sea valida
						cout << "-Tipo de pelo (" << listaDeOpciones(eTipoPelo, CANT_TIPO_PELO) << "): ";
						getline(cin, tipoPelo);
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
						cout << "-Raza (" << listaDeOpciones(eRazaPerro, CANT_RAZA_PERRO) << "): "; 
						getline(cin, raza);
					}while(razaPerroValido(raza) == -1);
					
					do{	// solicita vacuna de mascota hasta que la entrada sea valida
						cout << "-Vacuna de cachorro (" << listaDeOpciones(eSiNo, CANT_SI_NO) << "): ";
						getline(cin, sino);
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
					cout << "Presione una tecla para continuar..." << endl;
					cin.get();
					continue;
				}
				
				do{	// solicita tipo de mascota hasta que la entrada sea valida
					cout << "Tipo de mascota (" << listaDeOpciones(eTipoMascota, CANT_TIPO_MASCOTA) << "): "; 
					getline(cin, tipoMascota);
				}while(tipoMascotaValido(tipoMascota) == -1);
				
				cout << "-Nombre: ";	getline(cin, nombreMascota);
				
				do{	// solicita genero de mascota hasta que la entrada sea valida
					cout << "-Genero (" << listaDeOpciones(eGenero, CANT_GENERO) << "): "; 
					getline(cin, genero);
				}while(generoValido(genero) == -1);
				
				do {
					cout << "-Peso: ";	cin >> peso;
					if (cin.fail()){	// si se ingresa algo que no es float
						cin.clear(); 
						fflush(stdin);
					}else{
						fflush(stdin);
						break;
					}
				}while(true);
				
				// se piden los datos especificos segun el tipo de mascota
				if (tipoMascotaValido(tipoMascota) == tipoMascotaValido("gato")){	// si es gato
					string tipoPelo;
					
					do{	// solicita tipo de pelo de mascota hasta que la entrada sea valida
						cout << "-Tipo de pelo (" << listaDeOpciones(eTipoPelo, CANT_TIPO_PELO) << "): "; 
						getline(cin, tipoPelo);
					}while(tipoPeloValido(tipoPelo) == -1);
					
					DtGato gato = DtGato(
						nombreMascota, 
						generoValido(genero), 
						 peso, 
						 tipoPeloValido(tipoPelo)
					);
					agregarMascota(ci, gato);
				}else
				if (tipoMascotaValido(tipoMascota) == tipoMascotaValido("perro")){	// si es perro
					string raza, sino;
					do{	// solicita raza de mascota hasta que la entrada sea valida
						cout << "-Raza (" << listaDeOpciones(eRazaPerro, CANT_RAZA_PERRO) << "): "; 
						getline(cin, raza);
					}while(razaPerroValido(raza) == -1);
					
					do{	// solicita vacuna de mascota hasta que la entrada sea valida
						cout << "-Vacuna de cachorro (" << listaDeOpciones(eSiNo, CANT_SI_NO) << "): "; 
						getline(cin, sino);
					}while(siNoValido(sino) == -1);
					
					DtPerro perro = DtPerro(
						nombreMascota, 
						generoValido(genero), 
						 peso, 
						razaPerroValido(raza), 
						siNoValido(sino)
					);
					agregarMascota(ci, perro);
				}
			}
			else if (opcion == "4"){	// Baja de mascota de socio
				string ci, nombreMascota;
				
				cout << "--------- Baja de mascota ---------" 	<< endl;
				cout << "Ingrese los datos" << endl;
				cout << "-CI del socio: ";			getline(cin, ci);
				if (socioExiste(ci) == NULL ){	// verifica si el socio existe
					cout << "ERROR: El socio no existe" << endl;
					cout << "Presione una tecla para continuar..." << endl;
					cin.get();
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
					cout << "Presione una tecla para continuar..." << endl;
					cin.get();
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
					cout << "Presione una tecla para continuar..." << endl;
					cin.get();
					continue;
				}
				
				do {	// solicita el dia hasta que sea valido
				cout << "-Dia: ";	cin >> dia;
					if (cin.fail()){	// si se ingresa algo que no es int
						cin.clear(); 
						// para eliminar la basura que queda en el cin
						string s;
						cin >> s;
					}
					break;
				}while(true);
				
				do {	// solicita el mes hasta que sea valido
					cout << "-Mes: ";	cin >> mes;
					if (cin.fail()){	// si se ingresa algo que no es int
						cin.clear(); 
						// para eliminar la basura que queda en el cin
						string s;
						cin >> s;
					}
					break;
				}while(true);
				do {	// solicita el anio hasta que sea valido
					cout << "-Anio: ";	cin >> anio;
					if (cin.fail()){	// si se ingresa algo que no es int
						cin.clear(); 
						// para eliminar la basura que queda en el cin
						string s;
						cin >> s;
					}
					break;
				}while(true);
				
				consultas = verConsultasAntesDeFecha(DtFecha(dia, mes, anio), ci, cantConsultas);
				
				cout << "------- Lista de consulta ---------" 	<< endl;
				for (int i = 0; i < cantConsultas; i++){
					cout << *consultas[i] << endl;
					cout << "-----------------------------------" 	<< endl;
				}
				cout << "--------- Fin de lista ------------" 	<< endl;
				cout << "Presione una tecla para continuar..." 	<< endl;
				cin.get();
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
					cout << "Presione una tecla para continuar..." << endl;
					cin.get();
					continue;
				}
				
				DtMascota** mascotas = obtenerMascotas(ci, cantMascotas);
				
				cout << "-------- Lista de mascotas --------" 	<< endl;
				for (int i = 0; i < cantMascotas; i++){
					if (dynamic_cast<DtGato*>(mascotas[i])){
						cout << "------ Gato -------" << endl;
						cout << *((DtGato*) mascotas[i]) << endl;
					}else{
						cout << "------ Perro ------" << endl;
						cout << *((DtPerro*) mascotas[i]) << endl;
					}
				}
				cout << "---------- Fin de lista -----------" 	<< endl;
				cout << "Presione una tecla para continuar..." << endl;
				cin.get();
			}
			else if (opcion == "8"){	// listar socios
				cout << "-------- Listado de socios --------" 	<< endl;
				for (int i = 0; i < cantSocios; i++){
					cout << "CI: " << socios[i]->getCi() << " --------" << endl;
					cout << "Nombre: " << socios[i]->getNombre() << endl;
					cout << "Fecha de ingreso: " << socios[i]->getFechaIngreso() << endl;
					cout << "-----------------------------------" 	<< endl;
				}
				cout << "---------- Fin de lista -----------" 	<< endl;
				cout << "Presione una tecla para continuar..." << endl;
				cin.get();
			}
			else if (opcion == "0"){	// Salir
				// bye bye usuario
			}
			
			// si hubo algun error al ingresar y convertir los datos
			if (cin.fail()){
				cin.clear();	// limpia los errores
				// para eliminar la basura que queda en el cin
				string s;
				cin >> s;
				throw invalid_argument("Uno o mas datos ingresados no pudo ser procesado");
			}
		}catch(invalid_argument &ia) {
            cout << "ERROR: " << ia.what() << endl;
			cout << "Presione una tecla para continuar..." << endl;
			cin.get();
        }
	}while (opcion != "0");
	return 0;
}


void registrarSocio(string ci, string nombre, const DtMascota& dtMascota){
	// Registra un socio con su mascota. El valor el atributo racionDiaria se debe setear en 0
	if (cantSocios == MAX_SOCIOS)	throw invalid_argument("No se pueden agregar mas socios");
	
	Socio *s = socioExiste(ci);
	if (s != NULL)	throw invalid_argument("El socio ya esta registrado");
	
	// como el constructor de socio recibe 'DtMascota &' pero aca dtMascota es const, se convierte a variable
	DtMascota* m = const_cast<DtMascota*>(&dtMascota);
	
	socios[cantSocios] = new Socio(ci, nombre, DtFecha(), *m);
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
	delete socios[s];
	socios[s] = socios[cantSocios-1];
	cantSocios--;
}


void agregarMascota(string ci, const DtMascota& dtMascota){
	// Agrega una nueva mascota a un socio ya registrado. Si no existe un socio registrado con esa cedula, se levanta una excepcion std::invalid_argument
	
	Socio *s = socioExiste(ci);
	if (s == NULL)	throw invalid_argument("El socio no existe");
	
	if (s->puedeAgregarMascota()){
		// como la funcion recibe 'DtMascota &' pero aca dtMascota es const, se convierte a variable
		DtMascota* m = const_cast<DtMascota*>(&dtMascota);
		
		if (!s->mascotaExiste(m->getNombre())){
			s->agregarMascota(*m);
		}else{
			throw invalid_argument("El socio ya posee una mascota con ese nombre");
		}
	}else{
		throw invalid_argument("El socio ya posee el maximo de mascotas");
	}
}


void eliminarMascota(string ci, string nombreMascota){
	// elimina la mascota de nombre nombreMascota del socio con cedula ci
	Socio* s = socioExiste(ci);
	if (s == NULL)	throw invalid_argument("El socio no existe");
	
	if (s->mascotaExiste(nombreMascota)){
		if (s->puedeEliminarMascota()){
			s->eliminarMascota(nombreMascota);
		}else{
			throw invalid_argument("No se puede eliminar la unica mascota del socio");
		}
	}else{
		throw invalid_argument("La mascota no existe");
	}
}


DtMascota** obtenerMascotas(string ci, int& cantMascotas){
	// Devuelve un arreglo con las mascotas del socio. El largo del arreglo esta dado por el parametro cantMascotas. Si no existe un socio registrado con esa cedula, se levanta una excepcion std::invalid_argument
	Socio *s = socioExiste(ci);
	if (s == NULL)	throw invalid_argument("El socio no existe");
	
	DtMascota** mascotas = s->obtenerMascotas(cantMascotas);
	
	// el mascotas[] tiene todas las mascotas
	return mascotas;
}


void ingresarConsulta(string motivo, string ci){
	// Crea una consulta con un motivo para un socio. Si no existe un socio registrado con esa cedula, se levanta una excepcion std::invalid_argument
	
	Socio *s = socioExiste(ci);
	if (s == NULL)	throw invalid_argument("El socio no existe");
	
	if (s->puedeAgregarConsulta()){
		DtConsulta consulta = DtConsulta(DtFecha(), motivo);
		s->agregarConsulta(consulta);
	}else{
		throw invalid_argument("El socio ya posee el maximo de consultas");
	}
}


DtConsulta** verConsultasAntesDeFecha(const DtFecha& fecha, string ci, int& cantConsultas){
	// Devuelve las consultas antes de cierta fecha. El largo del arreglo esta dadopor el parametro cantConsultas
	
	Socio *s = socioExiste(ci);
	if (s == NULL)	throw invalid_argument("El socio no existe");
	
	DtConsulta** consultas = s->obtenerConsultas(cantConsultas);
	
	// el array consultas tiene todas las consultas, hay que  quedarse solo con las que cumplen la condicion de la fecha
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

























// aqui no hay ningun easter egg, el easter egg esta en la linea 23 de clases/cpp/Socio.cpp

