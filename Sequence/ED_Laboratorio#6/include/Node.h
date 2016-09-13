#ifndef NODE_H
#define NODE_H
#include <cstddef>
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
