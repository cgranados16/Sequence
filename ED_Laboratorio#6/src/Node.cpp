#include "Node.h"
#include "Player.h"
#include <iostream>
#include <stdexcept>

template<typename E>
Node<E>::Node(E value, Node<E>* next){
    this->value= value;
    this->next= next;
}

template<typename E>
Node<E>::Node(Node<E>* next){
    this->next= next;

}

template<typename E>
E Node<E>::getValue(){
    return value;
}

//setValue(){
template<typename E>
Node<E>* Node<E>::getNext(){
   return next;
}

template<typename E>
void  Node<E>::setNext(Node<E>* node){
    next=node;
}

template<typename E>
Node<E>::~Node(){
//Destructor
    //value=;
    //next=NULL;
}

template class Node<Player>;
