#include "cardbutton.h"
#include<QMessageBox>

extern Control * game;
extern QGraphicsScene* scene;
cardButton::cardButton(QString type, int value, int x, int y)
{
    this->button= new QGraphicsPixmapItem;
    this->type = type;
    this->value = value;
    setPixmap(QPixmap(":/images/Images/1Corazon.jpg"));
    setPos(x,y);
    setAcceptHoverEvents(true);
    setEnabled(true);
}
void cardButton::hoverLeaveEvent(QGraphicsSceneHoverEvent *event){
    if (type=="Corazon"){
        this->setPixmap(QPixmap(":/images/Images/1Corazon.jpg"));
    }
    if (type=="Espada"){
        this->setPixmap(QPixmap(":/images/Images/1Espada.jpg"));
    }
    if (type=="Trebol"){
        this->setPixmap(QPixmap(":/images/Images/1Trebol.jpg"));}
    if (type== "Diamante"){
            this->setPixmap(QPixmap(":/images/Images/1Corazon.jpg"));}
}


void cardButton::setPos(int x, int y){
    this->QGraphicsItem::setPos(x,y);
}
void cardButton::hoverEnterEvent(QGraphicsSceneHoverEvent *event){
    if (type=="Corazon"){
        this->setPixmap(QPixmap(":/images/Images/1Corazon.jpg"));
    }
    if (type=="Espada"){
        this->setPixmap(QPixmap(":/images/Images/1Espada.jpg"));
    }
    if (type=="Trebol"){
        this->setPixmap(QPixmap(":/images/Images/1Trebol.jpg"));}

    if(type == "Diamante"){
            this->setPixmap(QPixmap(":/images/Images/1Corazon.jpg"));}
}


void cardButton::mousePressEvent(QGraphicsSceneMouseEvent *event){
    if (type=="Start"){
       game->selectionWindow();

    }
    if (type=="End"){
        game->close();
    }
}
