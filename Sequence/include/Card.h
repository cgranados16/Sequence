#ifndef CARD_H
#define CARD_H
#include <iostream>
#include "Player.h"

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
        void toString();
        void setPlayer(string player);
        string getPlayer();

    protected:

    private:
        string type;
        int value;
        string player;
};

#endif // CARD_H