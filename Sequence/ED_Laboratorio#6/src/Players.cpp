#include "Players.h"

Players::Players(){
    this->name = "";
    this->turno = 0;
}

void Players::setName(string name){
    this->name=name;
}

string Players::getName(){
    return name;
}

void Players::setTurno(int turno){
    this->turno=turno;
}

int Players::getTurno(){
    return turno;
}

Players::~Players()
{
    //dtor
}
