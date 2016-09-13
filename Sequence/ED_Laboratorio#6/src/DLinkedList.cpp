/*#include "DLinkedList.h"

#include<iostream>
using namespace std;

DLinkedList::DLinkedList(){
    first=new DNode();
    last=new DNode();
    first->setNext(last);
    last->setPrevious(first);
    curr=first;
    size=0;
}

void DLinkedList::insert(int element){
    if (curr==last){
        append(element);
    }else{
    DNode* newDNode=new DNode(element);
    curr->getNext()->setPrevious(newDNode);
    newDNode->setNext(curr->getNext());
    newDNode->setPrevious(curr);
    curr->setNext(newDNode);
    size++;
    }
}

void DLinkedList::append(int element){
    DNode* newDNode=new DNode(element,last,last->getPrevious());
    last->getPrevious()->setNext(newDNode);
    last->setPrevious(newDNode);
    size++;
}

int DLinkedList::remove(){
    DNode* temp=curr->getNext();
    curr->setNext(temp->getNext());
    temp->getNext()->setPrevious(curr);
    size--;
    return temp->getValue();
}

void DLinkedList::gotoStart(){
    curr=first;
}

void DLinkedList::gotoEnd(){
    curr=last;
}

void DLinkedList::gotoPos(int pos){
    int i=0;
    DNode* temporal;
    temporal=first;
    while(i != pos){
        temporal=temporal->getNext();
        i++;
    }
    curr=temporal;
}

void DLinkedList::Next(){
    curr=curr->getNext();
}

void DLinkedList::Previous(){
    curr=curr->getPrevious();
}

int DLinkedList::getPos(){
    int i=0;
    DNode* temporal;
    temporal=first;
    while(temporal != curr){
        temporal=temporal->getNext();
        i++;
    }
    return i;
}

int DLinkedList::getSize(){
    return size;
}

void DLinkedList::print(){
    curr=first;
    cout<<"[";
    for (int i=0;i<size;i++){
        curr=curr->getNext();
        cout<<curr->getValue();
        if (i!=(size-1)){cout<<",";}
    }
    cout<<"]"<<endl;
}

void DLinkedList::printBackward(){
    gotoEnd();
    cout<<"[";
    for (int i=0;i<size;i++){
        curr=curr->getPrevious();
        cout<<curr->getValue();
        if (i!=(size-1)){cout<<",";}
    }
    cout<<"]"<<endl;
}

void DLinkedList::clear(){
    DNode* a=first;
    for(int i=0;i>size;i++){
        first=a->getNext();
        delete first;
    }
    size=0;
}

DLinkedList::~DLinkedList()
{
    clear();
}
*/
