GPP = g++
ARCHIVO_SALIDA = laboratorio_0_grupo_2

# carpetas
CLASES_CPP = clases/cpp/
CLASES_H = clases/h/
DATATYPES_CPP = datatypes/cpp/
DATATYPES_H = datatypes/h/
ENUMS = enums/

OBJS = $(CLASES_CPP)Consulta.o $(CLASES_CPP)Gato.o $(CLASES_CPP)Mascota.o $(CLASES_CPP)Perro.o $(CLASES_CPP)Socio.o $(DATATYPES_CPP)DtConsulta.o $(DATATYPES_CPP)DtFecha.o $(DATATYPES_CPP)DtGato.o $(DATATYPES_CPP)DtMascota.o $(DATATYPES_CPP)DtPerro.o $(ENUMS)Enums.o 

###############################################################################################
all: main.o $(OBJS)
	$(GPP) -o $(ARCHIVO_SALIDA) main.o $(OBJS)

main.o: main.cpp

###############################################################################################
# compilacion de clases
clases: $(CLASES_CPP)Consulta.o $(CLASES_CPP)Gato.o $(CLASES_CPP)Mascota.o $(CLASES_CPP)Perro.o $(CLASES_CPP)Socio.o

$(CLASES_CPP)Consulta.o: 	$(CLASES_CPP)Consulta.cpp 	$(CLASES_H)Consulta.h
$(CLASES_CPP)Gato.o: 		$(CLASES_CPP)Gato.cpp 		$(CLASES_H)Gato.h
$(CLASES_CPP)Mascota.o: 	$(CLASES_CPP)Mascota.cpp 	$(CLASES_H)Mascota.h
$(CLASES_CPP)Perro.o: 		$(CLASES_CPP)Perro.cpp 		$(CLASES_H)Perro.h
$(CLASES_CPP)Socio.o: 		$(CLASES_CPP)Socio.cpp 		$(CLASES_H)Socio.h

#-----------------------------------------------------------------------------------------------
# compilacion de datatypes
datatypes: $(DATATYPES_CPP)DtConsulta.o $(DATATYPES_CPP)DtFecha.o $(DATATYPES_CPP)DtGato.o $(DATATYPES_CPP)DtMascota.o $(DATATYPES_CPP)DtPerro.o

$(DATATYPES_CPP)DtConsulta.o: 	$(DATATYPES_CPP)DtConsulta.cpp 	$(DATATYPES_H)DtConsulta.h
$(DATATYPES_CPP)DtFecha.o: 		$(DATATYPES_CPP)DtFecha.cpp 	$(DATATYPES_H)DtFecha.h
$(DATATYPES_CPP)DtGato.o: 		$(DATATYPES_CPP)DtGato.cpp 		$(DATATYPES_H)DtGato.h
$(DATATYPES_CPP)DtMascota.o: 	$(DATATYPES_CPP)DtMascota.cpp 	$(DATATYPES_H)DtMascota.h
$(DATATYPES_CPP)DtPerro.o: 		$(DATATYPES_CPP)DtPerro.cpp 	$(DATATYPES_H)DtPerro.h

#-----------------------------------------------------------------------------------------------
# compilacion de enums
enums: $(ENUMS)Enums.o

$(ENUMS)Enums.o: 	$(ENUMS)Enums.cpp 	$(ENUMS)Enums.h

###############################################################################################

# limpiadores
cleanAll: cleanClases cleanDatatypes cleanEnums cleanMain

cleanMain:
	rm -f main.o
	rm -f $(ARCHIVO_SALIDA)

cleanClases:
	rm -f $(CLASES_CPP)*.o

cleanDatatypes:
	rm -f $(DATATYPES_CPP)*.o

cleanEnums:
	rm -f $(ENUMS)*.o



