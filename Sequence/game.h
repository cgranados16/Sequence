#ifndef GAME_H
#define GAME_H
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QItemSelectionModel>
#include "CardButton.h"
#include "Card.h"
#include "CircleList.h"
#include "LinkedList.h"
#include "ArrayStack.h"
#include "CardDeck.h"
#include "MyQGraphicsScene.h"

class Game : public QGraphicsView
{
    Q_OBJECT
public:
    Game();
    virtual ~Game();
    void showInfo(Player *Jugador);
    void mousePressEvent(QGraphicsSceneMouseEvent *pMouseEvent);
    void moveToTrash();

    bool secuenciaFilas();
    bool secuenciaColumna();
    bool secuenciaDiagonales();
    MyQGraphicsScene *getScene();
    void winEvent();
    void checkWin();
public slots:
    void nextPlayer();
    void back();

private:
    ArrayStack<Card*> *Baraja;
    Player* actual;
    int round;
    QGraphicsTextItem* stringTurno;
    QGraphicsTextItem* stringRound;
    QGraphicsTextItem* stringTeam;
    ArrayList<CardButton*> *HandButtons;
    CardDeck* cardBoard;
    MyQGraphicsScene* scene;
    Matriz<Card*>* board;
    LinkedList<Card*>* discartPile;
    Button* undoButton;
    LinkedList<Card*>* sequenceCards;
};
#endif // GAME_H
