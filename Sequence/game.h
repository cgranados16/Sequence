#ifndef GAME_H
#define GAME_H
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QItemSelectionModel>
#include "CardButton.h"
#include "Card.h"
#include "CircleList.h"
#include "ArrayStack.h"
#include "CardDeck.h"
#include <QGenericMatrix>


class Game : public QGraphicsView
{
    Q_OBJECT
public:
    Game();
    void showInfo(Player *Jugador);
    void mousePressEvent(QGraphicsSceneMouseEvent *pMouseEvent);
    void moveToTrash();

public slots:
    void nextPlayer();
    void showBoard(int random);

    void back();
private:
    ArrayStack<Card*> *Baraja;
    Player* actual;
    int round;
    QGraphicsTextItem* stringTurno;
    QGraphicsTextItem* stringRound;
    ArrayList<CardButton*> *HandButtons;
    QSignalMapper* signalMapper;
    QItemSelectionModel *select;
    CardDeck * cardBoard;
    QGraphicsScene* scene;

};
#endif // GAME_H
