#include "game.h"
#include "Card.h"
#include "CircleList.h"
#include "ArrayStack.h"
#include <ctime>
#include <QDebug>

extern CircleList<Player> Jugadores;

Game::Game()
{
    this->scene = new QGraphicsScene();
    scene->setSceneRect(0, 0, 1360, 700);
    scene->setBackgroundBrush(Qt::gray); // cambia el color de fondo de la pantalla

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff); // no crear scroll horizontal
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff); // no crear scroll vertical

    setFixedSize(1360, 700); // le da un tamano fijp al view
    setScene(this->scene); // cambia la escena por defecto a la que se eta creando


    Player actual = Jugadores.getElement();
    string actualName = actual.getName();
    QString text = ("Turno de: "+ QString::fromStdString(actualName));
    QGraphicsTextItem* item2 = new QGraphicsTextItem(text);
    item2->setDefaultTextColor(Qt::white);
    item2->setPos(30,500);
    scene->addItem(item2);


    ArrayList<Card> CardsDeck(54);
        int id=0;
        for (int i=1;i<14;i++){
            Card miCarta;
            miCarta.setType("Hearts");
            miCarta.setValue(i);
            miCarta.setId(id++);
            qDebug()<< QString::number(i)+"Corazon;"+QString::number(id);
            miCarta.setSide(0);
            CardsDeck.append(miCarta);
        }
        for (int i=1;i<14;i++){
            Card miCarta;
            miCarta.setType("Spades");
            miCarta.setValue(i);
            miCarta.setId(id++);
            qDebug()<< QString::number(i)+"Espada;"+QString::number(id);
            CardsDeck.append(miCarta);
        }
        for (int i=1;i<14;i++){
            Card miCarta;
            miCarta.setType("Diamonds");
            miCarta.setValue(i);
            miCarta.setId(id++);
            qDebug()<< QString::number(i)+"Rombo;"+QString::number(id);
            CardsDeck.append(miCarta);
        }
        for (int i=1;i<14;i++){
            Card miCarta;
            miCarta.setType("Clubs");
            miCarta.setValue(i);
            miCarta.setId(id++);
            qDebug()<< QString::number(i)+"Trebol;"+QString::number(id);
            CardsDeck.append(miCarta);
        }


    ArrayStack<Card> Mazo1(54);
        srand((int) time(0));
        while (Mazo1.getSize()!=CardsDeck.getSize()){
            int r = (rand() % CardsDeck.getSize());
            int que;
            for (int i=0;i<CardsDeck.getSize();i++){
                que=Mazo1.secuencial(r);
                if (que==-1){

                CardsDeck.gotoPos(r);
                Card insertar=CardsDeck.getValue();
                Mazo1.push(insertar);
                insertar.toString();

                }
       }
    }

    ArrayStack<Card> Mazo2(54);
        srand((int) time(0));
        while (Mazo2.getSize()!=CardsDeck.getSize()){
            int r = (rand() % CardsDeck.getSize());
            int que;
            for (int i=0;i<CardsDeck.getSize();i++){
                Card comp=Mazo2.getValue();
                que=Mazo2.secuencial(r);
                if (que==-1){
                    CardsDeck.gotoPos(r);
                    Card insertar=CardsDeck.getValue();
                    Mazo2.push(insertar);
                    insertar.toString();
                }
       }
    }

    int x = 260;
    int y = 10;

    for (int i=1;i<49;i++){
        Card miCarta;
        miCarta = Mazo1.pop();
        cardButton* caca = new cardButton(miCarta,x,y);
        if (x > 930){
            x=260;
            y += 70;
        }else{
            x += 80;
        }
        scene->addItem(caca);
    }
    qDebug() << Mazo1.getSize();

    for (int i=1;i<=51;i++){
        Card miCarta;
        miCarta = Mazo2.pop();
        cardButton* caca = new cardButton(miCarta,x,y);
        if (x > 930){
            x=260;
            y += 70;
        }else{
            x += 80;
        }

        scene->addItem(caca);
    }

    ArrayStack<Card> Baraja(54);
        srand((int) time(0));
        while (Baraja.getSize()!=CardsDeck.getSize()){
            int r = (rand() % CardsDeck.getSize());
            int que;
            for (int i=0;i<CardsDeck.getSize();i++){
                que=Baraja.secuencial(r);
                if (que==-1){
                    CardsDeck.gotoPos(r);
                    Card insertar=CardsDeck.getValue();
                    Baraja.push(insertar);
                    insertar.toString();
                }
       }
    }
        for (int i=1;i<49;i++){
            Card miCarta;
            miCarta = Baraja.pop();

            cardButton* caca = new cardButton(miCarta,30,500);
            caca->setMove();
            caca->setSize(1.6);

            scene->addItem(caca);
        }

    }


