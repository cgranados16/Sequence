#ifndef BUTTON_H
#define BUTTON_H
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

class Button: public QGraphicsPixmapItem, public QObject
{
    //Q_OBJECT
public:
    Button(QString id, QString image, int x, int y);
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void setImage(QString image);
    void setPos(int x,int y);
    void setScale(int scale);
    QPixmap getPixmap();
    ~Button();
private:
    QGraphicsPixmapItem* button;
    QString id;
    int x;
    int y;

private slots:


};

#endif // BUTTONPLAY_H
