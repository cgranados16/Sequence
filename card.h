#ifndef CARD_H
#define CARD_H
#include <iostream>
#include "Player.h"
#include <QObject>
#include <QString>
using namespace std;

class Player;
class Card
{

    public:
        Card();
        virtual ~Card();
        string getType();
        void setType(QString type);
        int getValue();
        void setValue(int value);
        void toString();
        void setId(int id);
        int getId();
        void setPlayer(string player);
        string getPlayer();

    protected:

    private:
        QString type;
        int value;
        int id;
        string player;
};

#endif // CARD_H
