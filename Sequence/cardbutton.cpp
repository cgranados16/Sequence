#include "cardbutton.h"
#include "ArrayStack.h"
#include<QMessageBox>
#include <QDebug>
extern Control * game;
extern QGraphicsScene* scene;


cardButton::cardButton(Card card , int x, int y){
    this->button = new QGraphicsPixmapItem;
    this->card = card;
    string valor = card.toString();
    if (card.getSide()==0){
        imagen = ":/Cards/Resources/Cards/Side/"+ QString::fromStdString(valor)+".png";
    }else{
        imagen = ":/Cards/Resources/Cards/BackCard.jpg";
    }
    QPixmap ima(imagen);
    QPixmap newPixmap = ima.scaled(75,75,Qt::KeepAspectRatio,Qt::SmoothTransformation);
    //QPixmap newPixmap = ima.scaled(QSize(75,75),  Qt::KeepAspectRatio);
    setPixmap(newPixmap);
    setPos(x,y);
    this->move = false;
    this->setAcceptDrops(true);
    this->setAcceptHoverEvents(true);
}




void cardButton::setMove(){

    setFlag(QGraphicsItem::ItemIsMovable);
    setFlag(QGraphicsItem::ItemSendsGeometryChanges);
    this->setAcceptHoverEvents(false);
    //setFlag(QGraphicsItem::ItemIsSelectable);
    move = true;
}

bool cardButton::getMove(){
    return move;

}

void cardButton::setPos(int x, int y){
    this->QGraphicsItem::setPos(x,y);
}

void cardButton::setSize(double scale){
    this->setScale(scale);
}

void cardButton::hoverEnterEvent(QGraphicsSceneHoverEvent *event){

    this->setScale(1.2);
 }

void cardButton::hoverLeaveEvent(QGraphicsSceneHoverEvent *event){
    this->setScale(1);


}

Card cardButton::getCard(){
    return this->card;
}


void cardButton::mousePressEvent(QGraphicsSceneMouseEvent *event){
    /*if (!(this->isCard())){
        //this->setPos(0,0);
        card.setSide(1);
        string valor = card.toString();
        imagen = ":/images/Images/Cards/"+ QString::fromStdString(valor)+".png";
        QPixmap ima(imagen);
        QPixmap newPixmap = ima.scaled(QSize(0,0),  Qt::KeepAspectRatio);
        this->setPixmap(newPixmap);
    }*/

}

void cardButton::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event){
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

void cardButton::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
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

void cardButton::dragEnterEvent(QGraphicsSceneDragDropEvent *event)
{
        event->setAccepted(true);
        update();

}

void cardButton::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    if (this->getMove()){

        setPos(30,500);
        update();
    }
}



void cardButton::dragLeaveEvent(QGraphicsSceneDragDropEvent *event)
{
    Q_UNUSED(event);
    update();
}


void cardButton::dropEvent(QGraphicsSceneDragDropEvent *event)
{
    QGraphicsItem::dropEvent(event); // move the item...
    qDebug() << QString("CACAC");
    //this->setPos(0,0);
}
