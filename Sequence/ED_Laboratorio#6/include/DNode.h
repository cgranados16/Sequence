#ifndef DNODE_H
#define DNODE_H
#include "Node.h"
#include <cstddef>
template<typename E>
class DNode:public Node<E>{
    public:
        DNode(int value, DNode* next=NULL,DNode* previous=NULL);
        DNode(DNode* next=NULL,DNode* previous=NULL);
        virtual ~DNode();
        DNode* getNext();
        void setNext(DNode* node);
        DNode* getPrevious();
        void setPrevious(DNode* node);

    protected:
        DNode* next;
        DNode* previous;
    private:
        //int value;  Herencia, Ya existe en la clase Node

        //setters/getters
};

#endif // DNODE_H
