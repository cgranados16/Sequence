#ifndef DLINKEDLIST_H
#define DLINKEDLIST_H
#include "LinkedList.h"
#include "DNode.h"
template<typename E>
class DLinkedList:public LinkedList<E>{
    public:
        DLinkedList();
        virtual ~DLinkedList();
        void insert(int value);
        void append(int value);
        int remove();
        void gotoStart();
        void gotoEnd();
        void gotoPos(int pos);
        void Next();
        void Previous();
        int getPos();
        int getSize();
        void print();
        void printBackward();
        void clear();

    protected:
        DNode<E>* first;
        DNode<E>* last;
        DNode<E>* curr;
        int size;
    private:

};

#endif // DLINKEDLIST_H
