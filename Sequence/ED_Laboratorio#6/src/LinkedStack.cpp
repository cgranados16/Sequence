#include "LinkedStack.h"
#include <iostream>
#include <stdexcept>
/*
LinkedStack::LinkedStack(){
    top=new Node();
    size=0;
}

void LinkedStack::push(int value){
    Node* newNode=new Node(value,top);
    top=newNode;
    size++;
}

int LinkedStack::pop(){
    if (top==NULL){
        throw runtime_error ("La lista esta vacia");
    }
    int frontValue=top->getValue();
    Node* temp=top;
    top=top->getNext();
    delete temp;
    size--;
    return frontValue;
}

void LinkedStack::print(){
    curr=top;
    cout<<"[";
    for (int i=0;i<size;i++){
        cout<<curr->getValue();
        curr=curr->getNext();
        if (i!=(size-1)){cout<<",";}
    }
    cout<<"]"<<endl;
}

int LinkedStack::topValue(){
    return top->getValue();
}

LinkedStack::~LinkedStack()
{
    LinkedList::clear();
}*/
