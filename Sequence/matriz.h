#ifndef MATRIZ_H
#define MATRIZ_H
#include "Card.h"
template <typename E>

class Matriz
{
public:
    Matriz(int rows, int columns);
    E getValue(int pRow, int pColumn);
    virtual ~Matriz();
    void setValue(int pRow, int pColumn, E value);
    int getRows();
    int getColumns();
    int getSize();
    void random();
    void swap(int i, int j, int swapI, int swapJ);

public slots:
protected:
   int rows;
   int columns;
   int size;
   E** matrix;
};

#endif // MATRIZ_H
