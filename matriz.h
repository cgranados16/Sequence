#ifndef MATRIZ_H
#define MATRIZ_H
#include "Card.h"
template <typename E>

class matriz
{
public:
    matriz(int rows, int columns);
    E getValue(int pRow, int pColumn);
    virtual ~matriz();
    void setValue(int pRow, int pColumn, E value);
    int getRows();
    int getColumns();

protected:
   int rows;
   int columns;
   E** matrix;
};

#endif // MATRIZ_H
