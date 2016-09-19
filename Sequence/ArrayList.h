#ifndef ARRAYLIST_H
#define ARRAYLIST_H
#include "Card.h"
#include <ctime>
#define MAX_DEFAULT_SIZE 1024

using namespace std;

template<typename E>
class ArrayList
{
    public:
        ArrayList(int pMax = MAX_DEFAULT_SIZE);
        E getValue();
        int getPos();
        int getSize();
        void gotoStart();
        void gotoPos(int pos = NULL);
        void gotoEnd();
        void previous();
        void next();
        void append(E pElement);
        void insert(E pElement);
        E remove();
        int secuencial(int value);
        virtual ~ArrayList();
        void insertionSort();     
        void clear();
        void swap(int pos, int swapPos);
        void random();
protected:
        int size;
        int max;
        int pos;
        E* elements;
    private:

};

#endif // ARRAYLIST_H
