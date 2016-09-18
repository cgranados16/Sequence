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
    qDebug() << imagen;
    QPixmap myQPixmap(imagen);
    image = myQPixmap.scaled(DEFAULT_HEIGHT,DEFAULT_WIDHT,Qt::KeepAspectRatio,Qt::SmoothTransformation);
    setPixmap(image);
    setPos(x,y);
}
