#include "Game.h"
#include "Card.h"
#include "CircleList.h"
#include "ArrayStack.h"
#include <ctime>
#include <QDebug>
#include "CardDeck.h"

extern CircleList<Player> Jugadores;
extern ArrayList<Card> CardsDeck;
extern QFont myFont;
extern int playersNum;

Game::Game()
{
    //========================
    round = 0;
    HandButtons = new ArrayList<CardButton*>(70);

    //==========================
    this->scene = new QGraphicsScene();
    scene->setSceneRect(0, 0, 1360, 700);
    setBackgroundBrush(QBrush(QImage(":/Buttons/Resources/boardBackground.jpg"))); // agregar imagen de fondo

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff); // no crear scroll horizontal
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff); // no crear scroll vertical

    setFixedSize(1360, 700); // le da un tamano fijp al view
    setScene(this->scene); // cambia la escena por defecto a la que se eta creando


    CardDeck *Mazo1 = new CardDeck;
    ArrayList<Card> caquita = Mazo1->defaultBoard();
    qDebug()<< caquita.getSize();
    int x = 260;
    int y = 10;
    for (int i=0;i<caquita.getSize();i++){
        caquita.gotoPos(i);
        Card cartaCaca = caquita.getValue();
        qDebug()<< QString::fromStdString(cartaCaca.toString());
    }

    for (int i=0;i<caquita.getSize();i++){
        Card miCarta;
        caquita.gotoPos(i);
        miCarta = caquita.getValue();
        CardButton* cardButton = new CardButton(miCarta,x,y);
        cardButton->setRotation(90);
        if (x > 930){
            x=260;
            y += 70;
        }else{
            x += 80;
        }
        scene->addItem(cardButton);
    }
/*
    CardDeck *Baraja = new CardDeck;
    Baraja->random();
    for (int i=largo;i>=0;i--){
        Card miCarta;
        Baraja->gotoPos(i);
        miCarta = Baraja->getValue();
        CardButton* cardButton = new CardButton(miCarta,100,500);
        cardButton->setSize(100,100);
        cardButton->setMove();
        scene->addItem(cardButton);
    }

    int i=0;
     playersNum =2;
    qDebug() << playersNum;
    while(i<playersNum){
        Player actual = Jugadores.getElement();
        for (int i=0;i<7;i++){
            Card miCarta;
            miCarta = Baraja->pop();
            actual.appendCard(miCarta);
        }
        Jugadores.Next();
        i++;
    }
    Jugadores.gotoStart();
    showInfo(Jugadores.getElement());
    Button *nextButton= new Button("Next","NextEnter",1180,650);
    connect(nextButton,SIGNAL(clicked()),this,SLOT(nextRound()));
    scene->addItem(nextButton);
    */
}

void Game::nextRound(){
    scene->removeItem(stringTurno);
    scene->removeItem(stringRound);
    Jugadores.Next();
    actual = Jugadores.getElement();
    round++;
    HandButtons->gotoStart();
    for (int i=0;i<7;i++){
        CardButton* carta = HandButtons->remove();
        scene->removeItem(carta);

    }
    showInfo(actual);




}

void Game::showInfo(Player Jugador){
    string actualName = Jugador.getName();
    QString text = ("Turno de:"+ QString::fromStdString(actualName));
    stringTurno = new QGraphicsTextItem(text);
    stringTurno->setDefaultTextColor(Qt::white);
    stringTurno->setPos(1060,20);
    scene->addItem(stringTurno);
    QString roundText = ("Ronda:"+ QString::number(round));
    stringRound= new QGraphicsTextItem(roundText);
    stringRound->setDefaultTextColor(Qt::white);
    stringRound->setPos(1130,50);
    scene->addItem(stringRound);
    ArrayList<Card>* caca2 = Jugador.getMano();

    int x=1200, y=100;
    for (int i=0;i<caca2->getSize();i++){
        Card miCarta;
        caca2->gotoPos(i);
        miCarta = caca2->getValue();
        CardButton* carta = new CardButton(miCarta,x,y);
        carta->setRotation(90);
        HandButtons->append(carta);
        y+=100;
        carta->setSize(100,100);
        //carta->setMove();
        scene->addItem(carta);
   }
}

void Game::test(){
    qDebug()<< QString("cardButton no sirve");
}
