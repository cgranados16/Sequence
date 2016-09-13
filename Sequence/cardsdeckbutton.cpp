#include "cardsDeckButton.h"
#include "ArrayStack.h"
#include<QMessageBox>
#include <QDebug>

extern Control * game;
extern QGraphicsScene* scene;


cardsDeckButton::cardsDeckButton(Card card , int x, int y){
    this->button = new QGraphicsPixmapItem;
    this->card = card;
    string valor = card.toString();
    imagen = ":/Cards/Resources/Cards/BackCard.jpg";

    QPixmap ima(imagen);
    QPixmap newPixmap = ima.scaled(75,75,Qt::KeepAspectRatio,Qt::SmoothTransformation);
    //QPixmap newPixmap = ima.scaled(QSize(75,75),  Qt::KeepAspectRatio);
    setPixmap(newPixmap);
    setPos(x,y);
    this->move = true;
    this->setAcceptDrops(true);
    this->setAcceptHoverEvents(true);
}




void cardsDeckButton::setMove(){

    setFlag(QGraphicsItem::ItemIsMovable);
    setFlag(QGraphicsItem::ItemSendsGeometryChanges);
    this->setAcceptHoverEvents(false);
    //setFlag(QGraphicsItem::ItemIsSelectable);
    move = true;
}

bool cardsDeckButton::getMove(){
    return move;

}

void cardsDeckButton::setPos(int x, int y){
    this->QGraphicsItem::setPos(x,y);
}

void cardsDeckButton::setSize(double scale){
    this->setScale(scale);
}

void cardsDeckButton::hoverEnterEvent(QGraphicsSceneHoverEvent *event){

    this->setScale(1.6);
}

void cardsDeckButton::hoverLeaveEvent(QGraphicsSceneHoverEvent *event){
    this->setScale(1);


}

Card cardsDeckButton::getCard(){
    return this->card;
}


void cardsDeckButton::mousePressEvent(QGraphicsSceneMouseEvent *event)
  {
    int x = 1200;
     int y = 300;
    if (this->getMove()){

        setPos(x,y);
        update();
    }
     }

void cardsDeckButton::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event){

}

void cardsDeckButton::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
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

void cardsDeckButton::dragEnterEvent(QGraphicsSceneDragDropEvent *event)
{
        event->setAccepted(true);
        update();

}

void cardsDeckButton::dragLeaveEvent(QGraphicsSceneDragDropEvent *event)
{
    Q_UNUSED(event);
    update();
}


void cardsDeckButton::dropEvent(QGraphicsSceneDragDropEvent *event)
{
    QGraphicsItem::dropEvent(event); // move the item...
    qDebug() << QString("CACAC");
    //this->setPos(0,0);
}
void cardsDeckButton::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    string valor = card.toString();
    imagen = ":/Cards/Resources/Cards/Side/"+ QString::fromStdString(valor)+".png";
    QPixmap ima(imagen);
    QPixmap newPixmap = ima.scaled(75,75,Qt::KeepAspectRatio,Qt::SmoothTransformation);
    this->setPixmap(newPixmap);
}
