#include "ArrayStack.h"
#include "Card.h"

template<class E>
ArrayStack<E>::ArrayStack(int pMax):ArrayList<E>(pMax){
    this->top=0;
}

template<class E>
void ArrayStack<E>::push(E element){
    this->pos=this->size;
    ArrayList<E>::append(element);
    top++;
}

template<class E>
E ArrayStack<E>::pop(){
    this->pos=(this->size-1);
    E pop=ArrayList<E>::remove();
    return pop;
}

template<class E>
void ArrayStack<E>::clear(){
    this->size=0;
    top=0;
}

template<class E>
E ArrayStack<E>::topValue(){
    this->pos=this->size-1;
    return ArrayList<E>::getValue();
}


template<class E>
ArrayStack<E>::~ArrayStack()
{
    clear();
}

template class ArrayStack<Card*>;
