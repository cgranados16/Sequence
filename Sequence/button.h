#ifndef BUTTON_H
#define BUTTON_H
#include <QGraphicsTextItem>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QBrush>
#include <QGraphicsSceneMouseEvent>
#include "Control.h"
#include <QKeyEvent>
#include <QObject>

class Control;

class Button: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Button(QString id,QString image, int x, int y);
    void hoverEnterEvent(QGraphicsSceneHoverEvent*);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent*);
    void mousePressEvent(QGraphicsSceneMouseEvent*);
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

signals:
    void clicked();

};

#endif // BUTTONPLAY_H
