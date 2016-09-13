#ifndef PLAYERS_H
#define PLAYERS_H
#include <iostream>

using namespace std;

class Players
{
    public:
        Players();
        virtual ~Players();
        void setName(string name);
        string getName();
        void setTurno(int turno);
        int getTurno();

    protected:

    private:
        string name;
        int turno;
};

#endif // PLAYERS_H
