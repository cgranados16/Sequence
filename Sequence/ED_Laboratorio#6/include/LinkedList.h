#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "Node.h"
#include <cstddef>
using namespace std;

template<typename E>

class LinkedList{
    protected:
        Node<E>* first;
        Node<E>* last;
        Node<E>* curr;
        int size;

    public:
        LinkedList();
        virtual ~LinkedList();
        int getSize();
        int getPos();
        void gotoStart();
        void gotoEnd();
        void Next();
        void insert(E element);
        void append(E element);
        void clear();
        E remove();
        void reversedList();

};

#endif // LINKEDLIST_H
