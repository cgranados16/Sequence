#ifndef LINKEDQUEUE_H
#define LINKEDQUEUE_H
#include "LinkedList.h"
template<typename E>
class LinkedQueue : public LinkedList<E>
{
    public:
        LinkedQueue();
        virtual ~LinkedQueue();
        void enqueue(int value);
        int dequeue();
        int getValue();
        bool isEmpty();
    protected:

    private:
};

#endif // LINKEDQUEUE_H
