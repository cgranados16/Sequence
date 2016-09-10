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
        void setType(string type);
        int getValue();
        void setValue(int value);
        string toString();
        void setId(int id);
        int getId();
        void setPlayer(string player);
        void setSide(int side);
        int getSide();
        string getPlayer();

    protected:

    private:

        string type;
        int value;
        int id;
        string player;
        int side; //Lado de la Carta 0 = Frente, 1 = volteada
};

#endif // CARD_H
