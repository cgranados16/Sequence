#include "ArrayList.h"

#include "Card.h"
#include <iostream>
#include <stdexcept>
#define default_max_size 1024
template<typename E>

ArrayList<E>::ArrayList(int pMax){
    max=pMax;
    size=0;
    pos=0;
    elements= new E[pMax];
}
template<typename E>
E ArrayList<E>::getValue(){
    if(pos < 0 || pos > size){
        throw runtime_error("List out of bounds");}
    return elements[pos];
}

template<typename E>
int ArrayList<E>::getPos(){
    return pos;
}


template<typename E>
int ArrayList<E>::getSize(){
    return size;
}

template<typename E>
void ArrayList<E>::gotoStart(){
    pos=0;
}

template<typename E>
void ArrayList<E>::gotoEnd(){
    pos=size;
}

template<typename E>
void ArrayList<E>::gotoPos(int pos){
    if (pos<0 || pos > size){
        throw runtime_error("List out of bounds");
    }
    this->pos=pos;
}

template<typename E>
void ArrayList<E>::previous(){
    if(pos>0){
        pos--;
    }
}
template<typename E>
void ArrayList<E>::next(){
    if(pos<size){
        pos++;
    }
}

template<typename E>
void ArrayList<E>::append(E pElement){
    if(size==max){
        throw runtime_error("List full");
    }
    elements[size]=pElement;
    size++;
}

//poner a pos a apuntar donde quiero inser invocando a gotopos()

template<typename E>
void ArrayList<E>::insert(E pElement){
    if (size==max){
        throw runtime_error("Full List");
    }
    for (int i=size; i>pos; i--){
        elements[i]=elements[i-1];
    }
    elements[pos]=pElement;
    size++;
}

//precondición pos apunta elemento a borrar
template<typename E>
E ArrayList<E>::remove(){
    if(size==0){
        throw runtime_error("Empty List");
    }
    E deletedElement=elements[pos];
    for(int i=pos; i<size; i++){
        elements[i]=elements[i+1];
    }
    size--;
    return (deletedElement);
}


/*template<typename E>
void ArrayList<E>::insertionSort(){
    for (int i=0;i<size;i++){
        int temp=i;
        while (temp>0){
            if (elements[temp]<elements[temp-1]){
                int hola= elements[temp];
                elements[temp]=elements[temp-1];
                elements[temp-1]=hola;
            }
            temp--;
        }
        pos++;
    }
}
*/



template<typename E>
ArrayList<E>::~ArrayList(){
    //destructor
    size=0;
    pos=0;
    delete[] elements;
}

template class ArrayList<Card>;
