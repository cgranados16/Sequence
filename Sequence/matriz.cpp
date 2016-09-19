#include "Matriz.h"

#include <QDebug>

template <typename E>
Matriz<E>::Matriz(int rows, int columns){
       this->rows = rows;
       this->columns = columns;
       matrix = new E*[rows];
       for (int i = 0; i < rows; i++) {
           matrix[i] = new E[columns];
       }
       this->size = rows*columns;
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
void Matriz<E>::swap(int i,int j, int swapI, int swapJ){
    E temp = matrix[i][j];
    matrix[i][j]=matrix[swapI][swapJ];
    matrix[swapI][swapJ]=temp;
}

template <typename E>
void Matriz<E>::random(){
    srand((int) time(0));
    for (int i=0;i<rows;i++){
        for (int c=0;c<columns;c++){
            if((i!=0&&c!=0) && (i!=0&&c!=9) &&
                (i!=9&&c!=0) && (i!=9&&c!=9)){
                int randomI = (rand() % rows);
                int randomC = (rand() % columns);
                while ((randomI==0&&randomC==0) || (randomI==0&&randomC==9) ||
                       (randomI==9&&randomC==0) || (randomI==9&&randomC==9)){
                    randomI = (rand() % rows);
                    randomC = (rand() % columns);
                }
                swap(i,c,randomI,randomC);
            }
        }
    }
}


template <typename E>
Matriz<E>::~Matriz() {
    for (int i = 0; i < rows; i++) {
       delete [] matrix[i];
       }
    delete [] matrix;
   }

template class Matriz<Card*>;
