#ifndef GAME_H
#define GAME_H
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QItemSelectionModel>
#include "CardButton.h"
#include <QGenericMatrix>


class Game : public QGraphicsView
{
    Q_OBJECT
public:
    Game();
    QGraphicsScene* scene;
    void showInfo(Player Jugador);

public slots:
    void nextRound();
    void test();

private:   
    Player actual;
    int round;
    QGraphicsTextItem* stringTurno;
    QGraphicsTextItem* stringRound;
    ArrayList<CardButton*> *HandButtons;
    QSignalMapper* signalMapper;
    QItemSelectionModel *select;

signals:
    selectionChanged();
};
#endif // GAME_H
