#ifndef CARDBUTTON_H
#define CARDBUTTON_H

#include <QGraphicsRectItem>
#include <QGraphicsTextItem>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QBrush>
#include <QGraphicsSceneMouseEvent>
#include "control.h"
#include <QKeyEvent>
#include <QObject>

class Control;

class cardButton: public QGraphicsPixmapItem, public QObject
{
    //Q_OBJECT
public:
    cardButton(QString type, int value, int x, int y);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
    void setImage(QString image);
    void setPos(int x,int y);
    QPixmap getPixmap();
private:
    QGraphicsPixmapItem* button;
    int value;
    QString type;
    int x;
    int y;
private slots:


};

#endif // BUTTONPLAY_H
