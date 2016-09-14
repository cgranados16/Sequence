#include "CardButton.h"
#include "ArrayStack.h"
#include<QMessageBox>
#include <QDebug>
extern Control * game;
extern QGraphicsScene* scene;

//Crea un boton de Carta
CardButton::CardButton(Card card , int x, int y ,int height, int width){
    this->Button = new QGraphicsPixmapItem;
    this->card = card; //Guarda la carta
    this->height=height;
    this->width=width;
    string valor = card.toString();
    if (card.getSide()==0){
        imagen = ":/Cards/Resources/Cards/"+ QString::fromStdString(valor)+".png";
    }else{
        imagen = ":/Cards/Resources/Cards/BackCard.jpg";
    }
    QPixmap ima(imagen);
    image = ima.scaled(height,width,Qt::KeepAspectRatio,Qt::SmoothTransformation);
    setPixmap(image);
    setPos(x,y);
    this->move = false;
    this->setAcceptDrops(true);
    this->setAcceptHoverEvents(true);
}




void CardButton::setMove(){
    setFlag(QGraphicsItem::ItemIsMovable);
    setFlag(QGraphicsItem::ItemSendsGeometryChanges);
    this->setAcceptHoverEvents(false);
    setFlag(QGraphicsItem::ItemIsSelectable);
    move = true;
}

bool CardButton::getMove(){
    return move;

}

void CardButton::setPos(int x, int y){
    this->QGraphicsItem::setPos(x,y);
}

void CardButton::setSize(int x, int y){
    string valor = card.toString();
    imagen = ":/Cards/Resources/Cards/"+ QString::fromStdString(valor)+".png";
    QPixmap ima(imagen);
    image = ima.scaled(x,y,Qt::KeepAspectRatio,Qt::FastTransformation);
    this->setPixmap(image);

}


void CardButton::hoverEnterEvent(QGraphicsSceneHoverEvent *){
    setZValue(1);
    setRotation(0);
    setSize(300,300);
}

void CardButton::hoverLeaveEvent(QGraphicsSceneHoverEvent*){
    setZValue(0);
    setRotation(90);
    setSize(height,width);
}

Card CardButton::getCard(){
    return this->card;
}


void CardButton::mousePressEvent(QGraphicsSceneMouseEvent*){
    emit clicked();
}

void CardButton::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *){
    /*if (card.getSide()==0){
         card.setSide(1);
         string valor = card.toString();
         imagen = ":/images/Images/Cards/"+ QString::fromStdString(valor)+".png";
         QPixmap ima(imagen);
         QPixmap newPixmap = ima.scaled(QSize(75,75),  Qt::KeepAspectRatioByExpanding);
         this->setPixmap(newPixmap);
    }else{
        card.setSide(0);
        imagen = ":/images/Images/Cards/BackCard.jpg";
        QPixmap ima(imagen);
        QPixmap newPixmap = ima.scaled(QSize(100,100),  Qt::KeepAspectRatio);
        this->setPixmap(newPixmap);
    }*/
}

void CardButton::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsItem::mouseMoveEvent(event); // move the item...

    // ...then check the bounds
    if (x() < 0)
        setPos(0, y());
    else if (x() >1250)
        setPos(1250, y());
    if (y() < 0)
        setPos(x(), 0);
    else if (y() > 700)
        setPos(x(), 700);


}


void CardButton::mouseReleaseEvent(QGraphicsSceneMouseEvent *)
{
    emit (selected());

}

