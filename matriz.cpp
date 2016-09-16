#include "matriz.h"
template <typename E>


matriz<E>::matriz(int rows, int columns){
       this->rows = rows;
       this->columns = columns;
       matrix = new E*[rows];
       for (int i = 0; i < rows; i++) {
           matrix[i] = new E[columns];
       }
   }


template <typename E>
E matriz<E>::getValue(int pRow, int pColumn) {
    return matrix[pRow][pColumn];
   }


template <typename E>
void matriz<E>::setValue(int pRow, int pColumn, E value) {
    matrix[pRow][pColumn] = value;
   }


template <typename E>
int matriz<E>::getRows() {
    return rows;
   }


template <typename E>
int matriz<E>::getColumns() {
   return columns;
   }


template <typename E>
matriz<E>::~matriz() {
    for (int i = 0; i < rows; i++) {
       delete [] matrix[i];
       }
    delete [] matrix;
   }

template class matriz<Card>;
