#include <iostream>
#include <stdexcept>
using namespace std;

#define PAUSE "PAUSE"
#define CLEAR "CLS"


// include de Clases
#include "clases\h\Socio.h"
#include "clases\h\Consulta.h"
#include "clases\h\Mascota.h"
#include "clases\h\Perro.h"
#include "clases\h\Gato.h"
// include de DataTypes
#include "datatypes\h\DtConsulta.h"
#include "datatypes\h\DtFecha.h"
#include "datatypes\h\DtMascota.h"
#include "datatypes\h\DtPerro.h"
#include "datatypes\h\DtGato.h"

void registrarSocio(string, string, const DtMascota &);
void agregarMascota(string , const DtMascota&);
void ingresarConsulta(string motivo, string ci);
DtConsulta** verConsultasAntesDeFecha(const DtFecha&, string, int&);
void eliminarSocio(string);


/*
########################################################
Socio		no se puede verificar hasta tener DtMascota y sus derivadas
Consulta	.h .cpp syntax check ok		2/4/2019
Mascota		.h .cpp syntax check ok		2/4/2019
Gato		.h .cpp	syntax check ok		4/4/2019
Perro		.h .cpp	syntax check ok		4/4/2019

DtConsulta	.h .cpp syntax check ok		2/4/2019
DtMascota	sin implementar
DtPerro		sin implementar
DtGato		sin implementar
DtFecha 	.h .cpp parece estar listo	4/4/2019
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
			
			if (opcion == "1"){	// Alta de socio
				string ci, nombre, nombreMascota;
				DtFecha fecha;
				float peso;
				
				system(CLEAR);
				cout << "---------- Alta de socio ----------"	<< endl;
				cout << "Ingrese los datos del nuevo socio" << endl;
				cout << "-CI: ";		getline(cin, ci);
				cout << "-Nombre: ";	getline(cin, nombre);
				cout << "Ingrese los datos de la mascota" << endl;
				cout << "-Nombre: ";	getline(cin, nombreMascota);
				cout << "-Peso: ";		cin >> peso;
				
				// hay que rellenar la mascota y no se como
				
				
				//registrarSocio(ci, nombre, dtMascota);
			}
			else if (opcion == "2"){	// Baja de socio
				string ci;
				
				system(CLEAR);
				cout << "---------- Baja de socio ----------"	<< endl;
				cout << "Ingrese los datos" << endl;
				cout << "-CI del socio: ";	getline(cin, ci);
				
				// eliminarSocio(ci);
			}
			else if (opcion == "3"){	// Alta de mascota de socio
				string ci, nombre, nombreMascota;
				float peso;
				
				system(CLEAR);
				cout << "---------- Alta de mascota --------" 	<< endl;
				cout << "Ingrese los datos" << endl;
				cout << "-CI del socio: ";	getline(cin, ci);
				cout << "Ingrese los datos de la mascota" << endl;
				cout << "-Nombre: ";	getline(cin, nombreMascota);
				cout << "-Peso: ";		cin >> peso;
				
				
				// agregarMascota(ci, dtMascota);
			}
			else if (opcion == "4"){	// Baja de mascota de socio
				string ci, nombreMascota;
				
				system(CLEAR);
				cout << "--------- Baja de mascota ---------" 	<< endl;
				cout << "Ingrese los datos" << endl;
				cout << "-CI del socio: ";			getline(cin, ci);
				cout << "-Nombre de la mascota: ";	getline(cin, nombreMascota);
				
				
				
				
			}
			else if (opcion == "5"){	// Ingresar consulta
				string ci, motivo;
				
				system(CLEAR);
				cout << "------- Ingreso de consulta -------" 	<< endl;
				cout << "Ingrese los datos" << endl;
				cout << "-CI de socio: ";			getline(cin, ci);
				cout << "-Motivo de consulta: ";	getline(cin, motivo);
				
				// ingresarConsulta(motivo, ci);
			}
			else if (opcion == "6"){	// Listar consultas de socio
				string ci;
				//DtFecha fecha;
				int dia, mes, anio, cantConsultas;
				//DtConsulta** consultas;
				
				system(CLEAR);
				cout << "------ Listado de consultas -------" 	<< endl;
				cout << "Ingrese los datos" << endl;
				cout << "-CI de socio: ";	getline(cin, ci);
				cout << "-Anio: ";			cin >> anio;
				cout << "-Mes: ";			cin >> mes;
				cout << "-Dia: ";			cin >> dia;
				
				// consultas verConsultasAntesDeFecha(DtFecha(dia, mes, anio), ci, cantConsultas);
				
				
			}
			else if (opcion == "7"){	// Listar mascotas de socio
				string ci;
				//DtMascota** mascotas;
				int cantMascotas;
				
				system(CLEAR);
				cout << "------- Listado de mascotas -------" 	<< endl;
				cout << "Ingrese los datos" << endl;
				cout << "-CI de socio: ";	getline(cin, ci);
				
				// mascotas = obtenerMascotas(ci, cantMascotas);
			}
			else if (opcion == "0"){	// Salir
				
			}
			
			// si hubo algun error al ingresar y convertir los datos
			if (cin.fail()){
				cin.clear();	// limpia los errores
				throw invalid_argument("Uno o mas datos ingresados no pudo ser procesado");
			}
		}catch(invalid_argument &ia) {
            cout << "ERROR: " << ia.what() << endl;
            system(PAUSE);
        }
        
	}while (opcion != "0");
	return 0;
}


/*
//Test de la clase perro;
Perro p1 = Perro("Paco", Macho,25.0,Labrador,true);
cout << "Datos Perro 1 \nNombre:"<< p1.getNombre()<< endl
     << "Raza: " << p1.getRaza() << endl
     << "Peso: " << p1.getPeso() << endl
     << "Genero: " << p1.getGenero() << endl
     << "Vacunas: " << p1.getVacunaCachorro() <<endl<<endl;
//Test de los metodos seter para perro
p1.setRaza(Pekines);
p1.setPeso(30);
p1.setGenero(Hembra);
p1.setNombre("Cuqui");
p1.setVacunaCachorro(false);
cout << "Datos Perro 1 \nNombre:"<< p1.getNombre()<< endl
     << "Raza: " << p1.getRaza() << endl
     << "Peso: " << p1.getPeso() << endl
     << "Genero: " << p1.getGenero() << endl
     << "Vacunas: " << p1.getVacunaCachorro() <<endl<<endl;

//Test de la clase gato;
Gato g1 = Gato("Garfiel", Macho,5.0,Mediano);
cout << "Datos Gato 1 \nNombre:"<< g1.getNombre()<< endl
     << "Pelo: " << g1.getPelo() << endl
     << "Peso: " << g1.getPeso() << endl
     << "Genero: " << g1.getGenero() << endl << endl;

//Test de los metodos seter para gato
g1.setPeso(12);
g1.setGenero(Hembra);
g1.setNombre("Monitor");
g1.setPelo(Largo);
cout << "Datos Gato 1 \nNombre:"<< g1.getNombre()<< endl
     << "Pelo: " << g1.getPelo() << endl
     << "Peso: " << g1.getPeso() << endl
     << "Genero: " << g1.getGenero() << endl << endl;
*/


/*
void registrarSocio(string ci, string nombre, const DtMascota& dtMascota){
	// Registra un socio con su mascota. El valor el atributo racionDiaria se debe setear en 0
	if (cantSocios == MAX_SOCIOS)	throw invalid_argument("No se pueden agregar mas socios");
	
	Socio *s = socioExiste(ci);
	if (s != NULL)	throw invalid_argument("El socio ya esta registrado");
	
	socios[cantSocios] = new Socio(ci, nombre, obtenerFechaActual(), dtMascota);
	cantSocios++;
}

void agregarMascota(string ci, const DtMascota& dtMascota){
	// Agrega una nueva mascota a un socio ya registrado. Si no existe un socio registrado con esa cedula, se levanta una excepcion std::invalid_argument
	
	Socio *s = socioExiste(ci);
	if (s == NULL)	throw invalid_argument("El socio no existe");
	
	if (!s->puedeTenerMasMascotas())	throw invalid_argument("El socio ya posee el maximo de mascotas");
	
	s->agregarMascota(dtMascota);
}

void ingresarConsulta(string motivo, string ci){
	// Crea una consulta con un motivo para un socio. Si no existe un socio registrado con esa cedula, se levanta una excepcion std::invalid_argument
	
	Socio *s = socioExiste(ci);
	if (s == NULL)	throw invalid_argument("El socio no existe");
	
	if (!s->puedeTenerMasMascotas())	throw invalid_argument("El socio ya posee el maximo de consultas");
	
	s->agregarConsulta(obtenerFechaActual(), motivo);
}

DtConsulta** verConsultasAntesDeFecha(const DtFecha& fecha, string ci, int& cantConsultas){
	// Devuelve las consultas antes de cierta fecha. El largo del arreglo esta dadopor el parametro cantConsultas
	
	Socio *s = socioExiste(ci);
	if (s == NULL)	throw invalid_argument("El socio no existe");
	
	DtConsulta** consultas = s->getConsultas(cantConsultas);
	
	// consultas[] tiene todas las consultas, hay que  quedarse solo con las que cumplen la condicion de la fecha
	// Las consultas vienen ordenadas de antiguas a nuevas, i avanza hasta que encuentra la primera que esta pasada de fecha
	int i;	// cantidad de consultas a devolver
	for (i = 0; i < cantConsultas; i++){
		if (!(*consultas[i].getFecha < fecha))	break;
	}
	// desde i hasta el final, hay que borrar las consultas porque no cumplen la consicion
	for (int aux = i; aux < cantConsultas; aux++){
		delete consultas[aux];
	}
	
	cantConsultas = i;
	return consultas;
}

void eliminarSocio(string ci){
	// Elimina al socio, sus consultas y sus mascotas. Si no existe un socio registrado con esa cedula, se levanta una excepcion std::invalid_argument
	
}

DtMascota** obtenerMascotas(string ci, int& cantMascotas){
	// Devuelve un arreglo con las mascotas del socio. El largo del arreglo esta dado por el parametro cantMascotas. Si no existe un socio registrado con esa cedula, se levanta una excepcion std::invalid_argument
	
}


Socio* socioExiste(string ci){
	// si el socio no existe devuelve NULL
	for (int i = 0; i < cantSocios; i++){
		if (ci == socios[i]->getCi())	return socios[i];
	}
	return NULL;
}
*/



