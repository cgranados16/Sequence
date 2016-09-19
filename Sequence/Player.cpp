#include "Player.h"
#include <iostream>
using namespace std;

Player::Player(){
    this->name = name;
    this->turno = turno;
    this->sequence=0;
    mano = new ArrayList<Card*>(SIZE_LIST);

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

void Player::appendCard(Card* carta){
    mano->append(carta);
}

Card* Player::removeCard(int pos){
    mano->gotoPos(pos);
    Card* deletedCard = mano->remove();
    return deletedCard;
}

void Player::addSequence()
{
    this->sequence++;
}

int Player::getSequence()
{
    return sequence;
}

ArrayList<Card*>* Player::getMano(){
    return mano;
}

Player::~Player()
{
    //dtor
}
