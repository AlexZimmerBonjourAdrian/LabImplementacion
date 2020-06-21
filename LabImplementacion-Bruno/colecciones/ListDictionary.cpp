#include "ListDictionary.h"
#include "../iterators/ListDIterator.cpp"
#include<iostream>
#include<stdio.h>

#ifndef LISTDICTIONARY_CPP
#define LISTDICTIONARY_CPP

ListDictionary::ListDictionary(){
	this->head=NULL;
	this->size=0;
}

void ListDictionary::add(IKey * key, ICollectible * elem){
	 if(key == NULL || elem==NULL){
	 	throw "La clave y el elemento no pueden ser NULL";
	 }
	 if(head == NULL){ // list vacía; tamaño = 1
	 	IntKey * k = (IntKey *)key;
        head = new ListNodeDictionary(k,elem);
        size = 1;
        return;
    }
    
    ListNodeDictionary *current = head;
    ListNodeDictionary *previous;
    while(current != NULL && current->getElem() != elem){
        previous = current;
        current = current->getNext();
    }
    
    if(current == NULL){ // final de la lista, se agrega
        previous->setNext(new ListNodeDictionary((IntKey *)key,elem));
        ++size;
    }
}

bool ListDictionary::member(IKey * key) const{
	    IntKey * k = (IntKey *) key;
		for(ListNodeDictionary *current = head; current != NULL; current = current->getNext()){
			if(current->getKey()->getId() == k->getId()){
	   			return true;
			}	
	   }
      
    	return false;
        
}

void ListDictionary::remove(IKey * key){
	
	ListNodeDictionary *current = head;
    ListNodeDictionary *previous = NULL;
    IntKey * k = (IntKey *) key;
    while(current != NULL && current->getKey()->getId() != k->getId()){
        previous = current;
        current = current->getNext();
    }

    if(current == NULL){ // final de la lista, no estaba
        return;
    } else if(current->getKey()->getId() == k->getId()){ 
        --size;
        if(previous == NULL) {// se borra el primer elemento
            this->head = current->getNext();
    	}
		else{
			previous->setNext(current->getNext());
		}  
        delete current;
    }
}

ICollectible * ListDictionary::find(IKey * key) const{
	ListNodeDictionary * current = head;
	IntKey * k = (IntKey *) key;
	while(current!=NULL){
		if(current->getKey()->getId()==k->getId()){
			return current->getElem();
		}
		else current=current->getNext();
	}
	return NULL;
}

bool ListDictionary::isEmpty() const{
	return size==0;
}

int ListDictionary::getSize() const{
	return size;
}

IIterator * ListDictionary::getIterator(){
	IIterator * it = new ListDIterator(head);
	return it;
}

ListDictionary::~ListDictionary(){
	ListNodeDictionary *current = head;
    ListNodeDictionary *next;
    while (current != NULL) {
        next = current->getNext();
        delete current;
        current = next;
    }
}

#endif
