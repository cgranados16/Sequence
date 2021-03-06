#include "LinkedList.h"
#include "game.h"
#include <stdexcept>
#include <iostream>
#include <QDebug>

using namespace std;

template<typename E>
LinkedList<E>::LinkedList(){
    first=new Node<E>();
    last=first;
    curr=first;
    size=0;
}

template<typename E>
int LinkedList<E>::getSize(){
    return size;
}

template<typename E>
int LinkedList<E>::getPos(){
    int i=0;
    Node<E>* temporal;
    temporal=first;
    while(temporal != curr){
        temporal=temporal->getNext();
        i++;
    }
    return i;
}

template<typename E>
void LinkedList<E>::gotoStart(){
    curr=first;
}

template<typename E>
void LinkedList<E>::gotoEnd(){
    curr=last;
}

template<typename E>
void LinkedList<E>::Next(){
    curr=curr->getNext();
}

template<typename E>
void LinkedList<E>::insert(E element){
    if (curr==last){
        append(element);
    }else{
    Node<E>* newNode=new Node<E>(element,NULL);
    newNode->setNext(curr->getNext());
    curr->setNext(newNode);
    size++;
    }
}
template<typename E>
void LinkedList<E>::append(E element){
    Node<E>* newNode=new Node<E>(element, NULL);
    last->setNext(newNode);
    last=newNode;
    size++;
}

template<typename E>
E LinkedList<E>::remove(){
    if (size==0){
        throw runtime_error("Empty List");
    }
    Node<E>* node=curr->getNext();
    if (curr->getNext() == last){last=curr;};
    if (node->getNext()!=NULL){
        curr->setNext(node->getNext());
    }
    size--;
    return node->getValue();

}

template<typename E>
void LinkedList<E>::reversedList(){
    Node<E>* temporal, *tempFirst=first;
    gotoEnd();
    while(curr!=tempFirst){
        temporal=tempFirst;
        while(temporal->getNext() != curr){
            temporal=temporal->getNext();
        }
        curr->setNext(temporal);
        curr=temporal;
    }
    first=curr;
    first->setNext(last);
}

template<typename E>
void LinkedList<E>::clear(){
    Node<E> a=first;
    for(int i=0;i<size;i++){
        first=a.getNext();
        delete first;
    }
    size=0;
}

template<typename E>
E LinkedList<E>::getElement(){
    if (this->curr==this->first){
        this->curr=this->curr->getNext();
    }
    return this->curr->getValue();
}

template<typename E>
LinkedList<E>::~LinkedList(){
    clear();
}

template class LinkedList<Player*>;
template class LinkedList<Card*>;
template class LinkedList<CardButton*>;


