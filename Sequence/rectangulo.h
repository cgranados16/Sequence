#ifndef RECTANGULO_H
#define RECTANGULO_H

#include <QGraphicsSceneMouseEvent>
#include <QGraphicsRectItem>
#include <QGraphicsTextItem>
#include <QBrush>

class Rectangulo : public QGraphicsRectItem
{
public:
    Rectangulo(int x,int y,int largo, int alto);

    //void keyPressEvent(QKeyEvent *event);
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);
};

#endif // RECTANGULO_H
