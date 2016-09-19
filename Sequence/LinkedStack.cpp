#include "LinkedStack.h"
#include <iostream>
#include <stdexcept>

template<class E>
LinkedStack<E>::LinkedStack(){
    top=new Node<E>();
    this->size=0;
}

template<class E>
void LinkedStack<E>::push(E value){
    Node<E>* newNode=new Node<E>(value,top);
    top=newNode;
    this->size++;
}

template<class E>
E LinkedStack<E>::pop(){
    if (top==NULL){
        throw runtime_error ("La lista esta vacia");
    }
    E frontValue=top->getValue();
    Node<E>* temp=top;
    top=top->getNext();
    delete temp;
    this->size--;
    return frontValue;
}

template<class E>
E LinkedStack<E>::topValue(){
    return top->getValue();
}

template<class E>
LinkedStack<E>::~LinkedStack()
{
    LinkedList<E>::clear();
}
