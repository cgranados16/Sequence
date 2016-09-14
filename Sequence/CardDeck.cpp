#include "CardDeck.h"
#define CARDDECK_SIZE 54
#include <QDebug>



CardDeck::CardDeck():ArrayStack<Card>(CARDDECK_SIZE)
{

    //Crea un mazo con todas las cartas
    id=0;
    for (int i=1;i<14;i++){
        Card miCarta;
        miCarta.setType("Hearts");
        miCarta.setValue(i);
        miCarta.setId(id++);
        miCarta.setSide(0);
        this->append(miCarta);
    }
    for (int i=1;i<14;i++){
        Card miCarta;
        miCarta.setType("Spades");
        miCarta.setValue(i);
        miCarta.setId(id++);
        this->append(miCarta);
    }
    for (int i=1;i<14;i++){
        Card miCarta;
        miCarta.setType("Diamonds");
        miCarta.setValue(i);
        miCarta.setId(id++);
        this->append(miCarta);
    }
    for (int i=1;i<14;i++){
        Card miCarta;
        miCarta.setType("Clubs");
        miCarta.setValue(i);
        miCarta.setId(id++);
        this->append(miCarta);
    }
}

void CardDeck::swap(int pos, int swapPos){
    Card temp = elements[pos];
    elements[pos]=elements[swapPos];
    elements[swapPos]=temp;
}

void CardDeck::random(){
    srand((int) time(0));
    for (int i=0;i<size;i++){
        int random = (rand() % size);
        swap(i,random);
    }
}

ArrayList<Card> CardDeck::defaultBoard(){
    ArrayList<Card> defaultBoard(100);

    //Fila1
    //comodin
    defaultBoard.append(elements[31]);   //6Diamonds
    defaultBoard.append(elements[32]);   //7Diamonds
    defaultBoard.append(elements[33]);   //8Diamonds
    defaultBoard.append(elements[34]);   //9Diamonds
    defaultBoard.append(elements[35]);   //10Diamonds
    defaultBoard.append(elements[37]);   //QDiamonds
    defaultBoard.append(elements[38]);   //KDiamonds
    defaultBoard.append(elements[26]);   //ADiamonds
    //comodin

    //Fila2
    defaultBoard.append(elements[30]);  //5Diamonds
    defaultBoard.append(elements[2]);   //3Hearts
    defaultBoard.append(elements[1]);   //2Hearts
    defaultBoard.append(elements[14]);  //2Spades
    defaultBoard.append(elements[15]);  //3Spades
    defaultBoard.append(elements[16]);  //4Spades
    defaultBoard.append(elements[17]);  //5Spades
    defaultBoard.append(elements[18]);  //6Spades
    defaultBoard.append(elements[19]);  //7Spades
    defaultBoard.append(elements[39]);  //AClubs

    //Fila 3
    defaultBoard.append(elements[29]);  //4Diamonds
    defaultBoard.append(elements[3]);   //4Hearts
    defaultBoard.append(elements[38]);  //KDiamonds
    defaultBoard.append(elements[25]);  //ADiamonds
    defaultBoard.append(elements[26]);  //ASpades
    defaultBoard.append(elements[51]);  //AClubs
    defaultBoard.append(elements[50]);  //QClubs
    defaultBoard.append(elements[48]);  //10Clubs
    defaultBoard.append(elements[20]);  //8Spades
    defaultBoard.append(elements[51]);  //KClubs

    //Fila 4
    defaultBoard.append(elements[28]);  //3Diamonds
    defaultBoard.append(elements[4]);   //5Hearts
    defaultBoard.append(elements[37]);  //QDiamonds
    defaultBoard.append(elements[11]);  //QHearts
    defaultBoard.append(elements[9]);  //10Hearts
    defaultBoard.append(elements[8]);  //9Hearts
    defaultBoard.append(elements[7]);  //8Hearts
    defaultBoard.append(elements[47]);  //9Clubs
    defaultBoard.append(elements[21]);  //9Spades
    defaultBoard.append(elements[24]);  //QClubs

    //Fila 5
    defaultBoard.append(elements[27]);  //2Diamonds
    defaultBoard.append(elements[5]);   //6Hearts
    defaultBoard.append(elements[35]);  //10Diamonds
    defaultBoard.append(elements[12]);  //KHearts
    defaultBoard.append(elements[2]);  //3Hearts
    defaultBoard.append(elements[1]);  //2Hearts
    defaultBoard.append(elements[6]);  //7Hearts
    defaultBoard.append(elements[46]);  //8Clubs
    defaultBoard.append(elements[22]);  //10Spades
    defaultBoard.append(elements[48]);  //10Clubs

    //Fila 6
    defaultBoard.append(elements[13]);  //ASpades
    defaultBoard.append(elements[6]);   //7Hearts
    defaultBoard.append(elements[34]);  //9Diamonds
    defaultBoard.append(elements[0]);  //AHearts
    defaultBoard.append(elements[3]);  //4Hearts
    defaultBoard.append(elements[4]);  //5Hearts
    defaultBoard.append(elements[5]);  //6Hearts
    defaultBoard.append(elements[45]);  //7Clubs
    defaultBoard.append(elements[24]);  //QSpades
    defaultBoard.append(elements[47]);  //9Clubs

    //Fila 7
    defaultBoard.append(elements[25]);  //KSpades
    defaultBoard.append(elements[7]);   //8Hearts
    defaultBoard.append(elements[33]);  //8Diamonds
    defaultBoard.append(elements[40]);  //2Clubs
    defaultBoard.append(elements[41]);  //3Clubs
    defaultBoard.append(elements[42]);  //4Clubs
    defaultBoard.append(elements[43]);  //5Clubs
    defaultBoard.append(elements[44]);  //6Clubs
    defaultBoard.append(elements[25]);  //KSpades
    defaultBoard.append(elements[46]);  //8Clubs

    //Fila 8
    defaultBoard.append(elements[24]);  //QSpades
    defaultBoard.append(elements[8]);   //9Hearts
    defaultBoard.append(elements[32]);  //7Diamonds
    defaultBoard.append(elements[31]);  //6Diamonds
    defaultBoard.append(elements[30]);  //5Diamonds
    defaultBoard.append(elements[29]);  //4Diamonds
    defaultBoard.append(elements[28]);  //3Diamonds
    defaultBoard.append(elements[27]);  //2Diamonds
    defaultBoard.append(elements[13]);  //ASpades
    defaultBoard.append(elements[45]);  //7Clubs

    //Fila 9
    defaultBoard.append(elements[22]);  //10Spades
    defaultBoard.append(elements[9]);   //10Hearts
    defaultBoard.append(elements[11]);   //QHearts
    defaultBoard.append(elements[12]);   //KHearts
    defaultBoard.append(elements[0]);   //AHearts
    defaultBoard.append(elements[40]);   //2Clubs
    defaultBoard.append(elements[41]);   //3Clubs
    defaultBoard.append(elements[42]);   //4Clubs
    defaultBoard.append(elements[43]);   //5Clubs
    defaultBoard.append(elements[44]);   //6Clubs

    //Fila 10
    //comodin
    defaultBoard.append(elements[21]);   //9Spades
    defaultBoard.append(elements[20]);   //8Spades
    defaultBoard.append(elements[19]);   //7Spades
    defaultBoard.append(elements[18]);   //6Spades
    defaultBoard.append(elements[17]);   //5Spades
    defaultBoard.append(elements[16]);   //4Spades
    defaultBoard.append(elements[15]);   //3Spades
    defaultBoard.append(elements[14]);   //2Spades
    //comodin






    return defaultBoard;




}

CardDeck::~CardDeck(){
    while (this->getSize()!=0){
        this->remove();
    }
    id=0;
}
