/*#include "ArrayQueue.h"
#include <iostream>
#include <stdexcept>
#include "ArrayList.h"

template<typename E>
ArrayQueue<E>::ArrayQueue(int tamano):ArrayList<E>(tamano+1){
    this->first=1;
    this->last=0;
    pos=first;
}

template<typename E>
void ArrayQueue<E>::enqueue(int value){
    if (isFull()){
        throw runtime_error("La cola esta llena");
    }
    size++;
    last=(last+1)%max;
    elements[last]=value;

}

int ArrayQueue::dequeue(){
    if (isEmpty()){
        throw runtime_error("La cola esta vacia");
    }
    int dequeue=ArrayList::remove();
    last--;
    return dequeue;

}

bool ArrayQueue::isFull(){
    if (size==max){
        return true;
    }else{
        return false;
    }
}

bool ArrayQueue::isEmpty(){
    if (size==0){
        return true;
    }else{
        return false;
    }
}



void ArrayQueue::print(){
    cout<<"[";
    for (int i=1; i<=size; i++){
        cout <<elements[i];
        if (i!=size){cout<<",";}
    }
    cout<<"]"<<endl;
}



int ArrayQueue::getValue(){
    return elements[first];
}
ArrayQueue::~ArrayQueue(){
    size=0;
    pos=0;
    delete[] elements;
}
*/
