TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        datatypes/cpp/DateTime.cpp \
        datatypes/cpp/Direccion.cpp \
        datatypes/cpp/DtCine.cpp \
        datatypes/cpp/DtComentario.cpp \
        datatypes/cpp/DtFuncion.cpp \
        datatypes/cpp/DtPelicula.cpp \
        datatypes/cpp/DtSala.cpp \
        main.cpp

HEADERS += \
	datatypes/h/DateTime.h \
	datatypes/h/Direccion.h \
	datatypes/h/DtCine.h \
	datatypes/h/DtComentario.h \
	datatypes/h/DtFuncion.h \
	datatypes/h/DtPelicula.h \
	datatypes/h/DtSala.h
