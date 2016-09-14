#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include "Card.h"
#include "ArrayList.h"

extern int SIZE_LIST;

using namespace std;

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
        void appendCard(Card carta);
        ArrayList<Card> *getMano();
protected:

    private:
        string name;
        int turno;
        ArrayList<Card> *mano;
};

#endif // Player_H
