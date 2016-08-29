#ifndef ARRAYSTACK_H
#define ARRAYSTACK_H
#include "ArrayList.h"
using namespace std;
template<class E>
class ArrayStack:public ArrayList<E>{

    public:
        ArrayStack(int tamano);
        virtual ~ArrayStack();
        void clear();
        void push(E element);
        E pop();
        E topValue();

    protected:

    private:
        int top;

};

#endif // ARRAYSTACK_H
