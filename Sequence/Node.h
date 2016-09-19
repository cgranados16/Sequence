#ifndef NODE_H
#define NODE_H
#include <cstddef>
//=======================
//Templates
#include "Player.h"
#include "cardbutton.h"
#include "MyQGraphicsScene.h"
//#include "game.h"
//=======================
using namespace std;
template<typename E>

class Node{
    public:
        Node(E value, Node<E>* next=NULL);
        Node(Node<E>* next=NULL);
        virtual ~Node();
        E getValue();
        void setValue();
        Node<E>* getNext();
        void setNext(Node<E>* next);

    protected:
        E value;
        Node<E>* next;
    private:


};

#endif // NODE_H
