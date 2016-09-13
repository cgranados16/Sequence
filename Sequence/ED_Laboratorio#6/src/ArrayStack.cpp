/*#include "ArrayStack.h"

ArrayStack::ArrayStack(int tamano):ArrayList(tamano){
    this->top=0;
}

void ArrayStack::push(int element){
    pos=size;
    ArrayList::append(element);
    top++;
}

int ArrayStack::pop(){
    pos=(size-1);
    int pop=ArrayList::remove();
    return pop;
}

void ArrayStack::clear(){
    size=0;
    top=0;
}

int ArrayStack::topValue(){
    pos=size-1;
    return ArrayList::getValue();
}
ArrayStack::~ArrayStack()
{
    clear();
    delete[] elements;
}
*/
