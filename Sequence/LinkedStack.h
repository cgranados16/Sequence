#ifndef LINKEDSTACK_H
#define LINKEDSTACK_H
#include "LinkedList.h"
using namespace std;
template<class E>
class LinkedStack:public LinkedList<E>{
    public:
        LinkedStack();
        virtual ~LinkedStack();
        void push(E value);
        E pop();
        E topValue();
        void print();


    protected:

    private:
        Node<E>* top;
};

#endif // LINKEDSTACK_H
