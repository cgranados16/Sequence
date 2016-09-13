#ifndef DCIRCLELIST_H
#define DCIRCLELIST_H
#include "DLinkedList.h"
template<typename E>
class DCircleList:public DLinkedList<E>{
    public:
        DCircleList();
        virtual ~DCircleList();
    protected:

    private:
};

#endif // DCIRCLELIST_H
