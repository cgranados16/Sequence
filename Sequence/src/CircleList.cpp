#include "CircleList.h"
#include "Player.h"
#include <stdexcept>
template<typename E>

CircleList<E>::CircleList(){
    this->first=new Node<E>();
    this->curr=this->first;
    this->first->setNext(this->first);
    this->size=0;
}

template<typename E>
void CircleList<E>::insert(E element){
    Node<E>* newNode=new Node<E>(element,this->curr->getNext());
    this->curr->setNext(newNode);
    this->size++;
}

template<typename E>
E CircleList<E>::remove(){

    if (this->curr->getNext()==this->first){
        throw runtime_error ("No puede eliminar el primer nodo");
    }
    Node<E>* node=this->curr->getNext();
    this->curr->setNext(node->getNext());
    this->size--;
    delete node;
    return node->getValue();
}


template<typename E>
void CircleList<E>::gotoEnd(){
    LinkedList<E>::gotoStart();
    while (this->curr->getNext()!=this->first){
        this->curr=this->curr->getNext();
    }
}

template<typename E>
void CircleList<E>::reversedList(){
    Node<E>* temporal, *tempFirst=this->first, *last;
    gotoEnd();
    last=this->curr;
    while(this->curr!=tempFirst){
        temporal=tempFirst;
        while(temporal->getNext() != this->curr){
            temporal=temporal->getNext();
        }
        this->curr->setNext(temporal);
        this->curr=temporal;
    }
    this->first->setNext(last);
}

template<typename E>
CircleList<E>::~CircleList()
{
    LinkedList<E>::clear();
}

template class CircleList<Player>;
