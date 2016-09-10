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
#include "Card.h"

class Control;

class cardButton: public QGraphicsPixmapItem
{
    //Q_OBJECT
public:
    cardButton(Card card, int x, int y);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void setImage(QString image);
    void setPos(int x,int y);
    void setMove();
    bool getMove();
    bool isCard(bool check);
    void setSize(double scale);
    Card getCard();
    QPixmap getPixmap();


    void dropEvent(QGraphicsSceneDragDropEvent *event) Q_DECL_OVERRIDE;
    void dragLeaveEvent(QGraphicsSceneDragDropEvent *event)Q_DECL_OVERRIDE;
    void dragEnterEvent(QGraphicsSceneDragDropEvent *event)Q_DECL_OVERRIDE;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) Q_DECL_OVERRIDE;

private:
    Card card;
    QGraphicsPixmapItem* button;
    QString imagen;
    bool move;

    int size[2];

private slots:


};

#endif // BUTTONPLAY_H
