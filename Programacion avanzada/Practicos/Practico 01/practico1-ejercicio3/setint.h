// racional.h
#include <iostream>
#ifndef setint_h
#define setint_h

class SetInt{
	private:
		int **arr;
		int contador;
	public:
		SetInt(){	// por defecto
		      this->arr = new int*[1];
		      this->contador = 0;
		}
		
		
		SetInt(SetInt &si){	// por copia
			this->arr = new int*[si.cantidadElementos()];
			contador = 0;
			
			for (int i = 0; i < si.cantidadElementos(); i++){
				this->arr[contador] = new int(si.obtenerElemento(i));
				contador++;
			}
		}
		
		
		SetInt(int arr[], int largo){	// dado un array
			this->arr = new int*[largo];
			contador = 0;
			this->mostrar();	printf("\n");
			
			for (int i = 0; i < largo; i++){
			this->mostrar();	printf("\n");
				this->arr[contador] = new int(arr[i]);
				contador++;
			}
		}
		
		
		void agregar(int n){
			this->arr[contador] = new int(n);
			contador++;
		 }
		
		
		void remover(int pos){
			if (pos >= this->contador)	return;
			delete this->arr[pos];
			//---------------------------------------------------------------
		 }
		
		
		SetInt unionn(){
		     
		 }
		
		
		SetInt diferencia(){
		     
		 }
		
		
		SetInt interseccion(){
		     
		 }
		
		
		bool pertenece(int n){
		     for (int i = 0; i<contador; i++){
		     	if (*this->arr[i] == n)	return true;
			 }
			 return false;
		 }
		
		
		bool esVacio(){
		     return this->contador == 0;
		 }
		
		
		int cantidadElementos(){
		     return this->contador;
		 }
		
		
		bool esIgual(SetInt si){
			if (this->contador != si.cantidadElementos())	return false;
			if (this->contador == 0)	return true;
			for (int i = 0; i < this->contador; i++){
				if (this->obtenerElemento(i) != si.obtenerElemento(i))	return false;
			}
			return true;
		}
		
		
		int obtenerElemento(int e){
			if (e >= contador)	return 0;
			return *this->arr[e];
		}
		
		
		void mostrar(){
			for (int i = 0; i < contador; i++){
				printf("%d", *this->arr[i]);
				if (i+1 < contador)	printf(", ");
			}
		}
		
		

};





#endif

















