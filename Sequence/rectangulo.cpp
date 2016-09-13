#include "rectangulo.h"

Rectangulo::Rectangulo(int x, int y, int largo, int alto)
{
    setRect(x, y, largo, alto); // crea un rectangulo en 0, 0 de largo x alto
    setBrush(Qt::black); // fijar el color del rectangulo a negro
    setAcceptHoverEvents(true); // acepta los hover events
}

/*
void Rectangulo::keyPressEvent(QKeyEvent * event)
{
    if (event->key() == Qt::Key_Left)
    {
        setPos(x() - 10, y());
    }
    if (event->key() == Qt::Key_Right)
    {
        setPos(x() + 10, y());
    }
}
*/

// sobreescritura de el hover enter
// reviza si el mouse esta sobre el elemento
void Rectangulo::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    setBrush(Qt::blue); // cambia el color del rectangulo a azul
}

// sobreescritura de el hover leave
// reviza si el mause esta sobre el elemento
void Rectangulo::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    setBrush(Qt::black); // cambia el color del rectangulo a negro
}
