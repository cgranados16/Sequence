#include "CardDeck.h"
#define CARDDECK_SIZE 52

CardDeck::CardDeck():ArrayStack<Card*>(CARDDECK_SIZE)
{
    //Crea un mazo con todas las cartas
    id=0;
    for (int i=1;i<14;i++){
        Card* miCarta = new Card();
        miCarta->setType("Hearts");
        miCarta->setValue(i);
        miCarta->setId(id++);
        miCarta->setSide(0);
        this->append(miCarta);
    }
    for (int i=1;i<14;i++){
        Card* miCarta = new Card();
        miCarta->setType("Spades");
        miCarta->setValue(i);
        miCarta->setId(id++);
        miCarta->setSide(0);
        this->append(miCarta);
    }
    for (int i=1;i<14;i++){
        Card* miCarta = new Card();
        miCarta->setType("Diamonds");
        miCarta->setValue(i);
        miCarta->setId(id++);
        miCarta->setSide(0);
        this->append(miCarta);
    }
    for (int i=1;i<14;i++){
        Card* miCarta = new Card();
        miCarta->setType("Clubs");
        miCarta->setValue(i);
        miCarta->setId(id++);
        miCarta->setSide(0);
        this->append(miCarta);
    }
}



Matriz<Card*> *CardDeck::defaultBoard(){
    Matriz<Card*>* defaultBoard = new Matriz<Card*>(10,10);
    //Fila1
    Card* comodin = new Card();
    comodin->setType("Comodin");
    comodin->setValue(0);
    comodin->setSide(1);
    defaultBoard->setValue(0,0,comodin);
    defaultBoard->setValue(0,1,elements[31]);   //6Diamonds
    defaultBoard->setValue(0,2,elements[32]);   //7Diamonds
    defaultBoard->setValue(0,3,elements[33]);   //8Diamonds
    defaultBoard->setValue(0,4,elements[34]);   //9Diamonds
    defaultBoard->setValue(0,5,elements[35]);   //10Diamonds
    defaultBoard->setValue(0,6,elements[37]);   //QDiamonds
    defaultBoard->setValue(0,7,elements[38]);   //KDiamonds
    defaultBoard->setValue(0,8,elements[26]);   //ADiamonds
    defaultBoard->setValue(0,9,comodin);

    //Fila2
    defaultBoard->setValue(1,0,elements[30]);  //5Diamonds
    defaultBoard->setValue(1,1,elements[2]);   //3Hearts
    defaultBoard->setValue(1,2,elements[1]);   //2Hearts
    defaultBoard->setValue(1,3,elements[14]);  //2Spades
    defaultBoard->setValue(1,4,elements[15]);  //3Spades
    defaultBoard->setValue(1,5,elements[16]);  //4Spades
    defaultBoard->setValue(1,6,elements[17]);  //5Spades
    defaultBoard->setValue(1,7,elements[18]);  //6Spades
    defaultBoard->setValue(1,8,elements[19]);  //7Spades
    defaultBoard->setValue(1,9,elements[39]);  //AClubs


    //Fila 3
    defaultBoard->setValue(2,0,elements[29]);  //4Diamonds
    defaultBoard->setValue(2,1,elements[3]);   //4Hearts
    defaultBoard->setValue(2,2,elements[38]);  //KDiamonds
    defaultBoard->setValue(2,3,elements[25]);  //ADiamonds
    defaultBoard->setValue(2,4,elements[26]);  //ASpades
    defaultBoard->setValue(2,5,elements[51]);  //AClubs
    defaultBoard->setValue(2,6,elements[50]);  //QClubs
    defaultBoard->setValue(2,7,elements[48]);  //10Clubs
    defaultBoard->setValue(2,8,elements[20]);  //8Spades
    defaultBoard->setValue(2,9,elements[51]);  //KClubs

    //Fila 4
    defaultBoard->setValue(3,0,elements[28]);  //3Diamonds
    defaultBoard->setValue(3,1,elements[4]);   //5Hearts
    defaultBoard->setValue(3,2,elements[37]);  //QDiamonds
    defaultBoard->setValue(3,3,elements[11]);  //QHearts
    defaultBoard->setValue(3,4,elements[9]);  //10Hearts
    defaultBoard->setValue(3,5,elements[8]);  //9Hearts
    defaultBoard->setValue(3,6,elements[7]);  //8Hearts
    defaultBoard->setValue(3,7,elements[47]);  //9Clubs
    defaultBoard->setValue(3,8,elements[21]);  //9Spades
    defaultBoard->setValue(3,9,elements[24]);  //QClubs


    //Fila 5
    defaultBoard->setValue(4,0,elements[27]);  //2Diamonds
    defaultBoard->setValue(4,1,elements[5]);   //6Hearts
    defaultBoard->setValue(4,2,elements[35]);  //10Diamonds
    defaultBoard->setValue(4,3,elements[12]);  //KHearts
    defaultBoard->setValue(4,4,elements[2]);  //3Hearts
    defaultBoard->setValue(4,5,elements[1]);  //2Hearts
    defaultBoard->setValue(4,6,elements[6]);  //7Hearts
    defaultBoard->setValue(4,7,elements[46]);  //8Clubs
    defaultBoard->setValue(4,8,elements[22]);  //10Spades
    defaultBoard->setValue(4,9,elements[48]);  //10Clubs


    //Fila 6
    defaultBoard->setValue(5,0,elements[13]);  //ASpades
    defaultBoard->setValue(5,1,elements[6]);   //7Hearts
    defaultBoard->setValue(5,2,elements[34]);  //9Diamonds
    defaultBoard->setValue(5,3,elements[0]);  //AHearts
    defaultBoard->setValue(5,4,elements[3]);  //4Hearts
    defaultBoard->setValue(5,5,elements[4]);  //5Hearts
    defaultBoard->setValue(5,6,elements[5]);  //6Hearts
    defaultBoard->setValue(5,7,elements[45]);  //7Clubs
    defaultBoard->setValue(5,8,elements[24]);  //QSpades
    defaultBoard->setValue(5,9,elements[47]);  //9Clubs

    //Fila 7
    defaultBoard->setValue(6,0,elements[25]);  //KSpades
    defaultBoard->setValue(6,1,elements[7]);   //8Hearts
    defaultBoard->setValue(6,2,elements[33]);  //8Diamonds
    defaultBoard->setValue(6,3,elements[40]);  //2Clubs
    defaultBoard->setValue(6,4,elements[41]);  //3Clubs
    defaultBoard->setValue(6,5,elements[42]);  //4Clubs
    defaultBoard->setValue(6,6,elements[43]);  //5Clubs
    defaultBoard->setValue(6,7,elements[44]);  //6Clubs
    defaultBoard->setValue(6,8,elements[25]);  //KSpades
    defaultBoard->setValue(6,9,elements[46]);  //8Clubs

    //Fila 8
    defaultBoard->setValue(7,0,elements[24]);  //QSpades
    defaultBoard->setValue(7,1,elements[8]);   //9Hearts
    defaultBoard->setValue(7,2,elements[32]);  //7Diamonds
    defaultBoard->setValue(7,3,elements[31]);  //6Diamonds
    defaultBoard->setValue(7,4,elements[30]);  //5Diamonds
    defaultBoard->setValue(7,5,elements[29]);  //4Diamonds
    defaultBoard->setValue(7,6,elements[28]);  //3Diamonds
    defaultBoard->setValue(7,7,elements[27]);  //2Diamonds
    defaultBoard->setValue(7,8,elements[13]);  //ASpades
    defaultBoard->setValue(7,9,elements[45]);  //7Clubs


    //Fila 9
    defaultBoard->setValue(8,0,elements[22]);  //10Spades
    defaultBoard->setValue(8,1,elements[9]);   //10Hearts
    defaultBoard->setValue(8,2,elements[11]);   //QHearts
    defaultBoard->setValue(8,3,elements[12]);   //KHearts
    defaultBoard->setValue(8,4,elements[0]);   //AHearts
    defaultBoard->setValue(8,5,elements[40]);   //2Clubs
    defaultBoard->setValue(8,6,elements[41]);   //3Clubs
    defaultBoard->setValue(8,7,elements[42]);   //4Clubs
    defaultBoard->setValue(8,8,elements[43]);   //5Clubs
    defaultBoard->setValue(8,9,elements[44]);   //6Clubs


    //Fila 10
    defaultBoard->setValue(9,0,comodin);
    defaultBoard->setValue(9,1,elements[21]);   //9Spades
    defaultBoard->setValue(9,2,elements[20]);   //8Spades
    defaultBoard->setValue(9,3,elements[19]);   //7Spades
    defaultBoard->setValue(9,4,elements[18]);   //6Spades
    defaultBoard->setValue(9,5,elements[17]);   //5Spades
    defaultBoard->setValue(9,6,elements[16]);   //4Spades
    defaultBoard->setValue(9,7,elements[15]);   //3Spades
    defaultBoard->setValue(9,8,elements[14]);   //2Spades
    defaultBoard->setValue(9,9,comodin);

    return defaultBoard;
}

Matriz<Card *>* CardDeck::randomBoard(){
    random(false);
    Matriz<Card*>* randomBoard = defaultBoard();
    return randomBoard;

}


void CardDeck::swap(int pos, int swapPos){
    Card* temp = elements[pos];
    elements[pos]=elements[swapPos];
    elements[swapPos]=temp;
}

void CardDeck::random(bool jacks){
    srand((int) time(0));
    for (int i=0;i<size;i++){
        int random = (rand() % size);
        if (!jacks){
            while (random ==10 ||random==23||random==36||random==49){
                random = (rand() % size);
            }
        }
        swap(i,random);
    }
}

ArrayStack<Card*>* CardDeck::getStack(){
   ArrayStack<Card*>* stack = new ArrayStack<Card*>(CARDDECK_SIZE);
   this->random();
   for (int i=0;i<CARDDECK_SIZE;i++){
       this->gotoPos(i);
       stack->append(this->getValue());
   }
   return stack;
}

CardDeck::~CardDeck(){
    while (this->getSize()!=0){
        this->remove();
    }
    id=0;
}
