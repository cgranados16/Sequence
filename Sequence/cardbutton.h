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
    CardButton(Card *card , int x, int y , int height = 75, int width = 75);
    void setImage(QString image);
    void setMove();
    bool getMove();
    bool isCard(bool check);
    void setSize(int x, int y);
    Card *getCard();
    QPixmap getPixmap();
    void setPos(int x, int y);
    void resetPos();
    int type() const;
    int getX();
    int getY();

    /*
     * Events
     */
    void mousePressEvent(QGraphicsSceneMouseEvent*event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent*);
    void hoverEnterEvent(QGraphicsSceneHoverEvent*);
    void mouseMoveEvent(QGraphicsSceneMouseEvent*event);

private:
    Card* card;
    int xPos;
    int yPos;
    int height;
    int width;
    QGraphicsPixmapItem* Button;
    QString imagen;
    QPixmap image;
    bool move;
    QPixmap ima;


signals:
    void clicked();


};

#endif // BUTTONPLAY_H
