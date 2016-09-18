#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include "Card.h"
#include "ArrayList.h"
#include "Token.h"

extern int SIZE_LIST;

using namespace std;

class Token;
class Card;
template<typename Card>
class ArrayList;

class Player
{
    public:
        Player();
        virtual ~Player();
        void setName(string name);
        string getName();
        void setTurno(int turno);
        int getTurno();
        void appendCard(Card *carta);
        ArrayList<Card*> *getMano();
        void setToken(Token *token);
        Token *getToken();
protected:

    private:
        string name;
        int turno;
        ArrayList<Card*> *mano;
        Token* token;
};

#endif // Player_H
