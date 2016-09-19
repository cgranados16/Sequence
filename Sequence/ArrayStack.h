#ifndef ARRAYSTACK_H
#define ARRAYSTACK_H
#include "ArrayList.h"
#define MAX_DEFAULT_SIZE 1024

using namespace std;
template<class E>
class ArrayStack:public ArrayList<E>{
    public:
        ArrayStack(int pMax = MAX_DEFAULT_SIZE );
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
