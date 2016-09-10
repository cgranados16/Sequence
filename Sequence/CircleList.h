#ifndef CIRCLELIST_H
#define CIRCLELIST_H
#include "LinkedList.h"
template<typename E>

class CircleList:public LinkedList<E>{
    public:
        CircleList();
        virtual ~CircleList();
        void insert(E element);
        void gotoEnd();
        void reversedList();
        E remove();

    protected:

    private:
};

#endif // CIRCLELIST_H
