/*#ifndef ARRAYQUEUE_H
#define ARRAYQUEUE_H
#include "ArrayList.h"
using namespace std;

template<typename E>

class ArrayQueue :public ArrayList<E>{
    public:
        ArrayQueue(int tamano);
        virtual ~ArrayQueue();
        void enqueue(int value);
        int dequeue();
        bool isFull();
        bool isEmpty();
        void print();
        int getValue();
    protected:

    private:
        int first;
        int last;
        int pos;
};

#endif // ARRAYQUEUE_H
