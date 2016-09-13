/*#include "DCircleList.h"
template<typename E>
DCircleList<E>::DCircleList()
{
    first=new DNode<E>();
    last=new DNode<E>();
    first->setNext(last);
    first->setPrevious(last);
    last->setPrevious(first);
    last->setNext(first);
    curr=first;
    size=0;
}



DCircleList::~DCircleList(){
    DNode* a=first;
    for(int i=0;i>size;i++){
        first=a->getNext();
        delete first;
    }
    size=0;
}
*/
