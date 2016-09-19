#include "Game.h"
#include "Card.h"
#include "CircleList.h"

#include <ctime>
#include <QDebug>
#include "CardDeck.h"

#include "MyQGraphicsScene.h"
#include "Token.h"

#define SCREEN_HEIGHT 1366
#define SCREEN_WIDHT 700
#define BOARD_DEFAULTX 300
#define MAXBOARD_X 960
#define CARDBOARD_SIZE 100
#define BOARD_DEFAULTY 10

extern CircleList<Player*>* Jugadores; //Lista de los jugadores
extern int TOTAL_PLAYERS; //Numero de jugadores
extern CardButton* cartaJugador; //Toma la carta de la mano del jugador
extern int boardType;

Game::Game()
{
    /*
     * Se inicializan los atributos
     * */
    //========================
    round = 1;
    HandButtons = new ArrayList<CardButton*>(SIZE_LIST);
    discartPile = new LinkedList<Card*>;
    sequenceCards = new LinkedList<Card*>;
    //==========================

    this->scene = new MyQGraphicsScene();
    scene->setSceneRect(0, 0, SCREEN_HEIGHT, SCREEN_WIDHT);
    setBackgroundBrush(QBrush(QImage(":/Resources/Resources/GameBackground.png"))); // agregar imagen de fondo

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff); // no crear scroll horizontal
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff); // no crear scroll vertical

    setFixedSize(SCREEN_HEIGHT, SCREEN_WIDHT); // le da un tamano fijp al view
    setScene(this->scene); // cambia la escena por defecto a la que se eta creando

    CardDeck cardDeck;
    board = cardDeck.defaultBoard();//Crea una matriz con el tablero
    if (boardType==0){
        board->random();
    }
    int x;
    int y = BOARD_DEFAULTY;
    for (int fila=0;fila<board->getRows();fila++){
        x = BOARD_DEFAULTX;
        for (int columna=0;columna<board->getColumns();columna++){
            Card * miCarta = new Card;
            miCarta = board->getValue(fila,columna);
            CardButton* miCartaButton = new CardButton(miCarta,x,y);
            miCartaButton->setRotation(90);
            x += CARDBOARD_SIZE-20;
            scene->addItem(miCartaButton);
        }
        y += CARDBOARD_SIZE-40;
    }

    Card* miCarta = new Card();
    miCarta->setType("Diamonds");
    miCarta->setValue(11);
    miCarta->setSide(0);
    miCarta->setSide(1);
    CardButton* DiscartButton = new CardButton(miCarta,50,100,150,150);
    scene->addItem(DiscartButton);


   Baraja = cardDeck.getStack(); //Crea la Baraja
   //Añade las cartas de los jugadores
   for (int i=0;i<Jugadores->getSize();i++){
       Player* actual = Jugadores->getElement();
        for (int i=0;i<SIZE_LIST;i++){
            Card* miCarta;
            miCarta = Baraja->pop();
            miCarta->setSide(0);
            actual->appendCard(miCarta);
        }
        Jugadores->Next();
    }

    //Añade la Baraja a la escena
    for (int i=0;i<Baraja->getSize();i++){
        Card* cartaBaraja;
        Baraja->gotoPos(i);
        cartaBaraja = Baraja->getValue();
        cartaBaraja->setSide(1);
        CardButton* cardButton = new CardButton(cartaBaraja,50,440,150,150);
        scene->addItem(cardButton);
    }


    Jugadores->gotoStart();
    showInfo(Jugadores->getElement());
    Button *backButton= new Button("Back","BackEnter",20,10);
    connect(backButton,SIGNAL(clicked()),this,SLOT(back()),Qt::UniqueConnection);
    scene->addItem(backButton);
    connect(scene,SIGNAL(endRound()),this,SLOT(nextPlayer()),Qt::UniqueConnection);

}

void Game::nextPlayer(){
    scene->removeItem(stringTurno);
    scene->removeItem(stringRound);
    if (TOTAL_PLAYERS==4){
        scene->removeItem(stringTeam);
    }
    if(secuenciaFilas() || secuenciaColumna() || secuenciaDiagonales()){
        checkWin();
    }
    moveToTrash();
    Jugadores->Next();
    actual = Jugadores->getElement();
    if (Jugadores->getPos()==1){
        round++;
    }
    HandButtons->gotoStart();
    for (int i=0;i<actual->getMano()->getSize();i++){
        CardButton* carta = HandButtons->remove();
        scene->removeItem(carta);
    }
    showInfo(actual);

}

//Muestra la informacion de Ronda y del jugador Actual
void Game::showInfo(Player* Jugador){
    actual = Jugadores->getElement();
    if (TOTAL_PLAYERS==4){
        QString text = ("Equipo:"+ QString::number(Jugadores->getElement()->getTurno()));
        stringTeam = new QGraphicsTextItem(text);
        //stringTurno->setDefaultTextColor(Qt::white);
        stringTeam->setPos(1100,10);
        scene->addItem(stringTeam);
    }
    string actualName = Jugador->getName(); //Muestra el nombre del Jugador actual
    QString text = ("Turno de:"+ QString::fromStdString(actualName));
    stringTurno = new QGraphicsTextItem(text);
    //stringTurno->setDefaultTextColor(Qt::white);
    stringTurno->setPos(SCREEN_HEIGHT/2.8,SCREEN_WIDHT-75);
    scene->addItem(stringTurno);
    QString roundText = ("Ronda:"+ QString::number(round));  //Muestra el numero de ronda actual
    stringRound= new QGraphicsTextItem(roundText);
    //stringRound->setDefaultTextColor(Qt::white);
    stringRound->setPos(SCREEN_HEIGHT/2.3 - 40,SCREEN_WIDHT-50);
    scene->addItem(stringRound);
    ArrayList<Card*>* manoJugadorActual = Jugador->getMano(); //Muestra la Mano del Jugador actual
    int x=1300, y=50;
    for (int i=0;i<manoJugadorActual->getSize();i++){
        Card* miCarta;
        manoJugadorActual->gotoPos(i);
        miCarta = manoJugadorActual->getValue();
        CardButton* carta = new CardButton(miCarta, x,y,150,150);
        //carta->setMove();
        carta->setRotation(90);
        HandButtons->append(carta);
        y+=80;
        scene->addItem(carta);
    }

    //Muestra la pila de Descarte
    if (discartPile->getSize()>0){
        discartPile->gotoEnd();
        Card* addtoDiscart = discartPile->getElement();
        CardButton* discartButton = new CardButton(addtoDiscart, 50,100,150,150);
        scene->addItem(discartButton);
    }

}

void Game::moveToTrash(){
    Player* actual = Jugadores->getElement();
    int handLenght = actual->getMano()->getSize();
    for (int i=0;i<handLenght;i++){
        actual->getMano()->gotoPos(i);
        Card* cartaMano = actual->getMano()->getValue();
        if (cartaJugador){
            if (cartaJugador->getCard()==cartaMano){
                Card* deleted = actual->removeCard(i);
                discartPile->append(deleted);
                cartaJugador = NULL;
            }
        }
    }
    Card* newCard = Baraja->pop();
    newCard->setSide(0);
    actual->appendCard(newCard);
}

bool Game::secuenciaFilas(){
    actual = Jugadores->getElement();
    int contador;
    for(int i = 0; i<10; i++){
        contador= 0;
        for(int j  = 0; j<10; j++){
            //Revisa si hay una secuencia en las Filas
            if(board->getValue(i,j)->hasToken()){
                if(board->getValue(i,j)->getToken()->getId()== actual->getTurno()){
                   contador+=1;
                    if(contador == 5){
                        return true;

                }
                }else{

                    contador=0;}
            }else{

                contador=0;}
            }
        }return false;
    }


    //Revisa si hay una secuencia en las columnas
bool Game::secuenciaColumna(){
    actual = Jugadores->getElement();
    int contador;
    for(int i = 0; i<10; i++){
        contador= 0;
        for(int j  = 0; j<10; j++){
            if(board->getValue(j,i)->hasToken()){
                if(board->getValue(j,i)->getToken()->getPlayer()== actual){

                    contador+=1;
                    if(contador == 5){
                        return true;

                        }

                    }
                    else{
                        contador=0;
                    }
                }
                else{
                    contador =0;
                }
            }
        }return false;
   }

//Funcion que revisa las secuencias de las diagonales
bool Game::secuenciaDiagonales(){
      Player* actual = Jugadores->getElement();
        int i = 0;
        int j= 0;
        int x = 0;
        int largo = 10;

        int contador = 0;
        while(x <= largo){
            for(int y = 0; y<=largo-1; y++){
                if(board->getValue(i,y)->hasToken()){
                    if(board->getValue(i,y)->getToken()->getPlayer()== actual){
                        contador+=1;
                        i+=1;
                        j+=1;

                        if(contador >=5){
                            return true;
                        }
                    }
                    else{
                        contador=0;
                        i+=1;
                        }
                }

                else{
                    contador =0;
                    i+=1;

                }
            }
            contador = 0;
            x+=1;
            largo -=1;

            i = x;

        }
    //triangulo superior carlos la chupa
        i = 0;
        j= 0;
        x = 0;
        largo = 10;

        int contador2 = 0;
        while(x <= largo){
            for(int y = 0; y<=largo-1; y++){
                if(board->getValue(y,j)->hasToken()){

                    if(board->getValue(y,j)->getToken()->getPlayer()== actual){

                        contador2+=1;
                        i+=1;
                        j+=1;

                        if(contador2 >=5){
                            return true;
                        }
                    }
                    else{
                        contador2=0;
                        i+=1;
                        }
                }

                else{
                    contador2 =0;
                    i+=1;

                }
            }
            contador2 = 0;
            x+=1;
            largo -=1;

            j = x;

        }
        //diagonales invertidas

        i = 0;
        j= 9;
        x = 0;
        largo = 10;
        int contador3 = 0;
        while(x <= largo){
            for(int y = 0; y<largo-1; y++){
                if(board->getValue(i,j)->hasToken()){

                    if(board->getValue(i,j)->getToken()->getPlayer()== actual){

                        contador3+=1;
                        i+=1;
                        j-=1;

                        if(contador3 >=5){
                           return true;
                        }
                    }
                    else{
                        contador3=0;
                        i+=1;
                        j-=1;
                        }
                }

                else{
                    contador3 =0;
                    i+=1;
                    j-=1;

                }
            }
            contador3 = 0;
            x+=1;
            largo -=1;
            j = 9;
            i = x;

        }


        j= 9;
        x = 0;
        largo = 10;
        int contador4 = 0;
        while(x <= largo){
            for(int y = 0; y<=largo-1; y++){
                if(board->getValue(y,j)->hasToken()){

                    if(board->getValue(y,j)->getToken()->getPlayer()== actual){
                        qDebug()<< QString::fromStdString("turno de"+actual->getName());
                        contador4+=1;

                        j-=1;
                        qDebug() << contador4;
                        if(contador4 >=5){
                            return true;
                        }
                    }
                    else{
                        contador4=0;

                        j-=1;
                        }
                }

                else{
                    contador4 =0;

                    j-=1;

                }
            }
            contador4 = 0;
            x+=1;
            largo -=1;
            j = largo-1;


        }return false;
    }

void Game::checkWin(){
winEvent();

}

void Game::winEvent(){
    QGraphicsTextItem* informationText = new QGraphicsTextItem("Gane :3");
    informationText->setPos(600,SCREEN_WIDHT/2);
    informationText->setScale(3);
    scene->addItem(informationText);
}

void Game::back(){
    round=0;
    delete Jugadores;
    delete Baraja;
    delete discartPile;
    delete HandButtons;
    delete board;
    //delete scene;
    //delete stringRound;
    delete stringTurno;
    delete actual;
    this->close();
    Control* menu = new Control();
    menu->show();
}

Game::~Game(){
    round=0;
    delete Jugadores;
    delete Baraja;
    delete discartPile;
    delete HandButtons;
    delete board;
    delete stringTurno;
    delete actual;
}

