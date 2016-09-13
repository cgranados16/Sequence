#ifndef LINKEDSTACK_H
#define LINKEDSTACK_H
#include "LinkedList.h"
using namespace std;
template<typename E>
class LinkedStack:public LinkedList<E>{
    public:
        LinkedStack();
        virtual ~LinkedStack();
        void push(int value);
        int pop();
        int topValue();
        void print();


    protected:

    private:
        Node<E>* top;
};

#endif // LINKEDSTACK_H
