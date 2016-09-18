#include "Matriz.h"
template <typename E>


Matriz<E>::Matriz(int rows, int columns){
       this->rows = rows;
       this->columns = columns;
       matrix = new E*[rows];
       for (int i = 0; i < rows; i++) {
           matrix[i] = new E[columns];
       }
   }


template <typename E>
E Matriz<E>::getValue(int pRow, int pColumn) {
    return matrix[pRow][pColumn];
   }


template <typename E>
void Matriz<E>::setValue(int pRow, int pColumn, E value) {
    matrix[pRow][pColumn] = value;
   }


template <typename E>
int Matriz<E>::getRows() {
    return rows;
   }


template <typename E>
int Matriz<E>::getColumns() {
   return columns;
}

template <typename E>
int Matriz<E>::getSize() {
   return rows*columns;
}


template <typename E>
Matriz<E>::~Matriz() {
    for (int i = 0; i < rows; i++) {
       delete [] matrix[i];
       }
    delete [] matrix;
   }

template class Matriz<Card*>;
