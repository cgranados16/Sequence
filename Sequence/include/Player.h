#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include "Card.h"
#include "ArrayList.h"
using namespace std;

class Player
{
    public:
        Player();
        virtual ~Player();
        void setName(string name);
        string getName();
        void setTurno(int turno);
        int getTurno();
    protected:

    private:
        string name;
        int turno;
};

#endif // Player_H
