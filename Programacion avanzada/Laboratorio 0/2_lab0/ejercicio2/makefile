GPP = g++
ARCHIVO_SALIDA = laboratorio_0_grupo_2
OBJS = a.o b.o c.o

###############################################################################################
all: main.o $(OBJS)
	$(GPP) -o $(ARCHIVO_SALIDA) main.o $(OBJS)

main.o: main.cpp

a.o: a.cpp

b.o: b.cpp

c.o: c.cpp

###############################################################################################

# limpiadores
cleanAll: cleanObjs cleanEjecutable

cleanObjs:
	rm -f *.o

cleanEjecutable:
	rm -f $(ARCHIVO_SALIDA)



