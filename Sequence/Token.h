#ifndef TOKEN_H
#define TOKEN_H
#include <QGraphicsPixmapItem>
#include "Card.h"
#include "Player.h"

class Player;
class Token : public QGraphicsPixmapItem
{
public:
    Token(Player* player, qreal x, qreal y);
private:
    Player* player;
    int id;
    QGraphicsPixmapItem* token;
    QPixmap image;
    QPixmap myQPixmap;
    QString imagen;
    const QString PATH = ":/Tokens/Resources/Token";
    const QString png = ".png";


};

#endif // TOKEN_H
