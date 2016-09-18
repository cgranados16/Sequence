#ifndef CARD_H
#define CARD_H
#include <iostream>
#include "Player.h"
#include <QObject>
#include <QString>
using namespace std;

class Player;
class Token;
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
        void setSide(int side);
        int getSide();
        void setPlayer(Player* player);
        Player* getPlayer();
        void setToken(Token *token);
        bool hasToken();

protected:

    private:
        string type;
        int value;
        int id;
        Player* player;
        int side; //Lado de la Carta 0 = Frente, 1 = volteada
        Token* token;
};

#endif // CARD_H
