#include "Node.h"
#include <iostream>
#include <stdexcept>


template<class E>
Node<E>::Node(E value, Node<E>* next){
    this->value= value;
    this->next= next;
}

template<class E>
Node<E>::Node(Node<E>* next){
    this->next= next;

}

template<class E>
E Node<E>::getValue(){
    return value;
}

//setValue(){
template<class E>
Node<E>* Node<E>::getNext(){
   return next;
}

template<class E>
void  Node<E>::setNext(Node<E>* node){
    next=node;
}

template<class E>
Node<E>::~Node(){
//Destructor
    //value=;
    //next=NULL;
}

template class Node<Player*>;
template class Node<Card*>;
template class Node<CardButton*>;
//template class Node<Game*>;
