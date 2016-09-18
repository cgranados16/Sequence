#include "Game.h"
#include "Card.h"
#include "CircleList.h"
#include "ArrayStack.h"
#include <ctime>
#include <QDebug>
#include "CardDeck.h"

#include "MyQGraphicsScene.h"
#include "Token.h"

#define SCREEN_HEIGHT 1366
#define SCREEN_WIDHT 700
#define BOARD_DEFAULTX 300
#define MAXBOARD_X 960
#define BOARD_DEFAULTY 10
#define CARDBOARD_SIZE 100

extern CircleList<Player*> Jugadores;
extern ArrayList<Card> CardsDeck;
extern int playersNum;
extern LinkedList<CardButton*> Trash;
extern QRectF posi;

Game::Game()
{
    /*
     * Se inicializan los atributos
     * */
    //========================
    round = 0;
    HandButtons = new ArrayList<CardButton*>(SIZE_LIST);
    //Trash = new LinkedList<CardButton*>;
    //selectedCards = new LinkedList<CardButton*>;
    //==========================

    this->scene = new MyQGraphicsScene();
    scene->setSceneRect(0, 0, SCREEN_HEIGHT, SCREEN_WIDHT);
    setBackgroundBrush(QBrush(QImage(":/Resources/Resources/BoardBackground2.jpg"))); // agregar imagen de fondo

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff); // no crear scroll horizontal
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff); // no crear scroll vertical

    setFixedSize(SCREEN_HEIGHT, SCREEN_WIDHT); // le da un tamano fijp al view
    setScene(this->scene); // cambia la escena por defecto a la que se eta creando

    CardDeck cardDeck;
    Baraja = cardDeck.getStack(); //Crea la Baraja

    int i=0;
    while(i<Jugadores.getSize()){
        Player* actual = Jugadores.getElement();
        for (int i=0;i<SIZE_LIST;i++){
            Card* miCarta;
            miCarta = Baraja->pop();
            miCarta->setSide(0);
            actual->appendCard(miCarta);
        }
        Jugadores.Next();
        qDebug() << QString::fromStdString(Jugadores.getElement()->getName());
        i++;
    }

    //Añade la Baraja a la escena
    for (int i=0;i<Baraja->getSize();i++){
        Card* miCarta;
        Baraja->gotoPos(i);
        miCarta = Baraja->getValue();
        miCarta->setSide(1);
        CardButton* cardButton = new CardButton(miCarta,100,500);
        cardButton->setSize(150,150);
        scene->addItem(cardButton);
    }

    Jugadores.gotoStart();
    showInfo(Jugadores.getElement());
    Button *nextButton= new Button("Next","NextEnter",1180,650);
    connect(nextButton,SIGNAL(clicked()),this,SLOT(nextPlayer()),Qt::UniqueConnection);
    scene->addItem(nextButton);
    //connect(scene,SIGNAL(endRound()),this,SLOT(nextPlayer()),Qt::UniqueConnection);

    Button *randomButton= new Button("Next","NextEnter",100,650);
    connect(randomButton,SIGNAL(clicked()),this,SLOT(back()),Qt::UniqueConnection);
    scene->addItem(randomButton);

    /*QSignalMapper* signalMapper = new QSignalMapper (this) ;
    connect (randomButton, SIGNAL(clicked()), signalMapper, SLOT(map()));
    signalMapper -> setMapping (randomButton, 1) ;
    connect (signalMapper, SIGNAL(mapped(int)), this, SLOT(showBoard(int))) ;*/
    //Token* thisToken = new Token(Jugadores.getElement(),300.0,600.0);
    //scene->addItem(thisToken);

    showBoard(0);

}

void Game::nextPlayer(){

    scene->removeItem(stringTurno);
    scene->removeItem(stringRound);
    //moveToTrash();
    Jugadores.Next();
    actual = Jugadores.getElement();
    if (actual->getTurno()==1){
        round++;
    }
    HandButtons->gotoStart();
    for (int i=0;i<SIZE_LIST;i++){
        CardButton* carta = HandButtons->remove();
        scene->removeItem(carta);
    }

    showInfo(actual);

}

void Game::showInfo(Player* Jugador){
    //Muestra el nombre del Jugador actual
    string actualName = Jugador->getName();
    QString text = ("Turno de:"+ QString::fromStdString(actualName));
    stringTurno = new QGraphicsTextItem(text);
    //stringTurno->setDefaultTextColor(Qt::white);
    stringTurno->setPos(SCREEN_HEIGHT/2 - 75,SCREEN_WIDHT-75);
    scene->addItem(stringTurno);
    //Muestra el numero de ronda actual
    QString roundText = ("Ronda:"+ QString::number(round));
    stringRound= new QGraphicsTextItem(roundText);
    //stringRound->setDefaultTextColor(Qt::white);
    stringRound->setPos(SCREEN_HEIGHT/2,SCREEN_WIDHT-50);
    scene->addItem(stringRound);
    //Muestra la Mano del Jugador actual
    ArrayList<Card*>* caca2 = Jugador->getMano();
    int x=1300, y=50;
    for (int i=0;i<caca2->getSize();i++){
        Card* miCarta;
        caca2->gotoPos(i);
        miCarta = caca2->getValue();
        CardButton* carta = new CardButton(miCarta, x,y,150,150);
        //carta->setMove();
        carta->setRotation(90);
        HandButtons->append(carta);
        y+=80;
        scene->addItem(carta);
    }
    //Muestra la pila de Descarte
    for (int i=0;i<Trash.getSize();i++){
        Card* miCarta;
        miCarta = Trash.getElement()->getCard();
        CardButton* carta = new CardButton(miCarta,100,300,75,75);
        //carta->setMove();
        carta->setRotation(90);
        HandButtons->append(carta);
        scene->addItem(carta);
        Trash.Next();
    }
}

void Game::showBoard(int random){
    CardDeck cardDeck;
    Matriz<Card*>* board;
    if (random==1){
        board = cardDeck.randomBoard();//Crea una matriz con el tablero
    }else{
        board = cardDeck.defaultBoard();//Crea una matriz con el tablero
    }
    int x = BOARD_DEFAULTX;
    int y = BOARD_DEFAULTY;
    for (int fila=0;fila<board->getRows();fila++){
        for (int columna=0;columna<board->getColumns();columna++){
            Card * miCarta = new Card;
            miCarta = board->getValue(fila,columna);
            CardButton* miCartaButton = new CardButton(miCarta,x,y);
            miCartaButton->setRotation(90);
            if (x > MAXBOARD_X){
                x=BOARD_DEFAULTX;
                y += CARDBOARD_SIZE-40;
            }else{
                x += CARDBOARD_SIZE-20;
            }
            scene->addItem(miCartaButton);
        }
    }
    board->~Matriz();
}

void Game::moveToTrash(){
    qDebug() <<"Alo si";
    Trash.gotoEnd();
    Card* temp =Trash.getElement()->getCard();
    Player* actual = Jugadores.getElement();
    for (int i=0;i<actual->getMano()->getSize();i++){
        actual->getMano()->gotoPos(i);
        Card* cartaMano = actual->getMano()->getValue();
        qDebug() << QString::fromStdString(temp->toString());
        qDebug() << QString::fromStdString(cartaMano->toString());
        qDebug() << QString::number(temp->toString()==cartaMano->toString());
        if (temp->toString()==cartaMano->toString()){
            qDebug() <<"Yea";
            qDebug()<<actual->getMano()->getSize();
            qDebug()<<actual->getMano()->getPos();
            //actual.getMano()->remove();
            qDebug() <<"Boi";
            qDebug()<<actual->getMano()->getSize();
        }
    }
    Card* caca = Baraja->pop();
    qDebug() <<"Sirve";
    actual->appendCard(caca);

}

void Game::back(){
    this->close();
    Control* board = new Control();
    board->show();
    Jugadores.clear();
}

