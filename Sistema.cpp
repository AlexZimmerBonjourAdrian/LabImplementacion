#include "Sistema.h"

Sistema * Sistema::getInstance(){
	return instance;
}

ColMozos * Sistema::getMozos(){
	return this->mozos;
}
