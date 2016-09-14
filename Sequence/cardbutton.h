#ifndef CardButton_H
#define CardButton_H

#include <QGraphicsRectItem>
#include <QGraphicsTextItem>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QBrush>
#include <QGraphicsSceneMouseEvent>
#include "Control.h"
#include <QKeyEvent>
#include <QObject>
#include "Card.h"

class Control;

class CardButton: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    CardButton(Card card , int x, int y ,int height = 75, int width = 75);
    void mousePressEvent(QGraphicsSceneMouseEvent*);
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent*);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent*);
    void hoverEnterEvent(QGraphicsSceneHoverEvent*);
    void mouseMoveEvent(QGraphicsSceneMouseEvent*event);
    void setImage(QString image);
    void setPos(int x,int y);
    void setMove();
    bool getMove();
    bool isCard(bool check);
    void setSize(int x, int y);
    Card getCard();
    QPixmap getPixmap();
    void mouseReleaseEvent(QGraphicsSceneMouseEvent*) Q_DECL_OVERRIDE;

private:
    Card card;
    int height;
    int width;
    QGraphicsPixmapItem* Button;
    QString imagen;
    QPixmap image;
    bool move;
    QPixmap ima;


signals:
    void clicked();
    void selected();


};

#endif // BUTTONPLAY_H
