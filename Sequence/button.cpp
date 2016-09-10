#include "button.h"
#include<QMessageBox>
#include "game.h"
#include "CircleList.h"
#include <QDebug>
extern Control * game;
extern Game* board;
extern QLineEdit* playerNameBox;
extern CircleList<Player> Jugadores;
extern int playersNum;
int i=1;
Button::Button(QString id, QString image, int x, int y)
{
    this->button= new QGraphicsPixmapItem;
    this->id = id;
    setPixmap(QPixmap(image));
    setPos(x,y);
    setAcceptHoverEvents(true);
    setEnabled(true);
}

void Button::setImage(QString image){
    this->setPixmap(QPixmap(image));
}

void Button::setPos(int x, int y){
    this->QGraphicsItem::setPos(x,y);
}

void Button::setScale(int scale){
    this->QGraphicsItem::setScale(scale);
}

void Button::hoverEnterEvent(QGraphicsSceneHoverEvent *event){
    if (id=="Start"){
        this->setPixmap(QPixmap(":/Buttons/Resources/Buttons/StartLeave.png"));
    }
    if (id=="End"){
        this->setPixmap(QPixmap(":/Buttons/Resources/Buttons/ExitLeave.png"));
    }
    if (id=="Next"){
        this->setPixmap(QPixmap(":/Buttons/Resources/Buttons/NextLeave.png"));
    }
    if (id=="Back1"){
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

void Button::hoverLeaveEvent(QGraphicsSceneHoverEvent *event){
    if (id=="Start"){
        this->setPixmap(QPixmap(":/Buttons/Resources/Buttons/StartEnter.png"));
    }
    if (id=="End"){
        this->setPixmap(QPixmap(":/Buttons/Resources/Buttons/ExitEnter.png"));
    }
    if (id=="Next"){
        this->setPixmap(QPixmap(":/Buttons/Resources/Buttons/NextEnter.png"));
    }
    if (id=="Back1"){
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

void Button::mousePressEvent(QGraphicsSceneMouseEvent *event){
    if (id=="Start"){
       game->selectionWindow();

    }
    if (id=="End"){
        game->close();
    }
    if (id=="Back1"){
       game->mainWindow();
    }

    if (id=="2Players"){
        playersNum = 2;
        game->inputNames(i);

    }
    if (id=="3Players"){
        playersNum = 3;
        game->inputNames(i);

    }
    if (id=="4Players"){
        playersNum = 4;
        game->inputNames(i);
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
                string yea = actual.getName();
                qDebug()<<"Jugadores "+ QString::number(Jugadores.getPos()) + QString::fromStdString(yea);
                Jugadores.Next();
            }
            game->close();
            board = new Game();
            board->show();
        }


    }
}

Button::~Button(){
    delete button;
    id = "";

}
