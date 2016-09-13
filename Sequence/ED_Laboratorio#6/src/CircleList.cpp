#include "CircleList.h"
#include "Player.h"
template<typename E>

CircleList<E>::CircleList(){
    first=new Node<E>();
    curr=first;
    first->setNext(first);
    size=0;
}

template<typename E>
void CircleList<E>::insert(E element){
    Node<E>* newNode=new Node<E>(element,curr->getNext());
    curr->setNext(newNode);
    size++;
}

template<typename E>
void CircleList<E>::gotoEnd(){
    LinkedList<E>::gotoStart();
    while (curr->getNext()!=first){
        curr=curr->getNext();
    }
}

template<typename E>
void CircleList<E>::reversedList(){
    Node<E>* temporal, *tempFirst=first, *last;
    gotoEnd();
    last=curr;
    while(curr!=tempFirst){
        temporal=tempFirst;
        while(temporal->getNext() != curr){
            temporal=temporal->getNext();
        }
        curr->setNext(temporal);
        curr=temporal;
    }
    first->setNext(last);
}

template<typename E>
CircleList<E>::~CircleList()
{
    LinkedList<E>::clear();
}

template class CircleList<Player>;
