#include "Button.h"
#include<QMessageBox>
#include "Game.h"
#include "CircleList.h"
#include <QDebug>

extern Game* board;
extern Control * game;
extern QLineEdit* playerNameBox;
extern CircleList<Player> Jugadores;
extern int playersNum;
int i=1;

const QString PATH = ":/Buttons/Resources/Buttons/";
const QString png = ".png";

Button::Button(QString id, QString image, int x, int y)
{
    this->button= new QGraphicsPixmapItem;
    this->id = id;
    setPixmap(QPixmap(PATH+image+png));
    setPos(x,y);
    setAcceptHoverEvents(true);
    setEnabled(true);
}

void Button::setImage(QString image){
    this->setPixmap(QPixmap(PATH+image+png));
}

void Button::setPos(int x, int y){
    this->QGraphicsItem::setPos(x,y);
}

void Button::setScale(int scale){
    this->QGraphicsItem::setScale(scale);
}

void Button::hoverEnterEvent(QGraphicsSceneHoverEvent*){
    if (id=="Start"){
        this->setPixmap(QPixmap(":/Buttons/Resources/Buttons/StartLeave.png"));
    }
    if (id=="End"){
        this->setPixmap(QPixmap(":/Buttons/Resources/Buttons/ExitLeave.png"));
    }
    if (id=="Next"){
        this->setPixmap(QPixmap(":/Buttons/Resources/Buttons/NextLeave.png"));
    }
    if (id=="Back"){
        this->setPixmap(QPixmap(":/Buttons/Resources/Buttons/BackLeave.png"));
    }
    if (id=="2Players"){
        this->setPixmap(QPixmap(":/Buttons/Resources/Buttons/2PlayersLeave.png"));
    }
    if (id=="3Players"){
        this->setPixmap(QPixmap(":/Buttons/Resources/Buttons/3PlayersLeave.png"));
    }
    if (id=="4Players"){
        this->setPixmap(QPixmap(":/Buttons/Resources/Buttons/4PlayersLeave.png"));
    }

}

void Button::hoverLeaveEvent(QGraphicsSceneHoverEvent*){
    if (id=="Start"){
        this->setPixmap(QPixmap(":/Buttons/Resources/Buttons/StartEnter.png"));
    }
    if (id=="End"){
        this->setPixmap(QPixmap(":/Buttons/Resources/Buttons/ExitEnter.png"));
    }
    if (id=="Next"){
        this->setPixmap(QPixmap(":/Buttons/Resources/Buttons/NextEnter.png"));
    }
    if (id=="Back"){
        this->setPixmap(QPixmap(":/Buttons/Resources/Buttons/BackEnter.png"));
    }
    if (id=="2Players"){
        this->setPixmap(QPixmap(":/Buttons/Resources/Buttons/2PlayersEnter.png"));
    }
    if (id=="3Players"){
        this->setPixmap(QPixmap(":/Buttons/Resources/Buttons/3PlayersEnter.png"));
    }
    if (id=="4Players"){
        this->setPixmap(QPixmap(":/Buttons/Resources/Buttons/4PlayersEnter.png"));
    }

}

void Button::mousePressEvent(QGraphicsSceneMouseEvent*){
    emit clicked();
/*    if (id=="2Players"){
        playersNum = 2;
    }
    if (id=="3Players"){
        playersNum = 3;


    }
    if (id=="4Players"){
        playersNum = 4;

    }

    if (id=="Next"){   
        qDebug()<< QString("Nombre de Jugador: ")+ playerNameBox->text();
        if (i<playersNum){
            if (playerNameBox->text()!=""){
                Player Jugador;
                QString name = playerNameBox->text();
                Jugador.setName(name.toStdString());
                Jugador.setTurno(i);
                Jugadores.gotoEnd();
                Jugadores.insert(Jugador);
                playerNameBox->clear();
                game->inputNames(++i);
            }else{
                game->inputNames(i);
            }
        }else{
            Player Jugador;
            QString name = playerNameBox->text();
            Jugador.setName(name.toStdString());
            Jugador.setTurno(i);
            Jugadores.gotoEnd();
            Jugadores.insert(Jugador);
            playerNameBox->clear();
            Jugadores.gotoStart();


            for (int i=0;i<Jugadores.getSize();i++){
                Player actual = Jugadores.getElement();
                Jugadores.Next();
            }
            game->close();
            board = new Game();
            board->show();
        }
    }*/
}

Button::~Button(){
    delete button;
    id = "";

}
