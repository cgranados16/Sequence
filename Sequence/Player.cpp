#include "Player.h"
#include <iostream>
using namespace std;

Player::Player(){
    this->name = name;
    this->turno = turno;
    mano = new ArrayList<Card>(SIZE_LIST);
}

void Player::setName(string name){
    this->name=name;
}

string Player::getName(){
    return name;
}

void Player::setTurno(int turno){
    this->turno=turno;
}

int Player::getTurno(){
    return turno;
}

void Player::appendCard(Card carta){
    mano->append(carta);
}

ArrayList<Card>* Player::getMano(){
    return mano;
}

Player::~Player()
{
    //dtor
}
