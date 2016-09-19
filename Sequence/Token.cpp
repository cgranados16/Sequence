#include "Token.h"
#define DEFAULT_HEIGHT 100
#define DEFAULT_WIDHT 60
#include <QDebug>

Token::Token(Player *player, qreal x, qreal y)
{
    this->token= new QGraphicsPixmapItem;
    this->player = player;
    this->id =player->getTurno();
    imagen = PATH+ QString::number(id)+png;
    QPixmap myQPixmap(imagen);
    image = myQPixmap.scaled(DEFAULT_HEIGHT,DEFAULT_WIDHT,Qt::KeepAspectRatio,Qt::SmoothTransformation);
    setPixmap(image);
    setPos(x,y);
}

Player *Token::getPlayer(){
    return player;
}

int Token::getId(){
    return id;
}

void Token::setId(int id)
{
    this->id=id;
}

int Token::type() const
{
    // Enable the use of qgraphicsitem_cast with this item.
    return UserType+2;
}
