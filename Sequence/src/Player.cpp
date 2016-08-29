#include "Player.h"
#include <iostream>
#define SIZE_LIST 3
using namespace std;

Player::Player(){
    this->name = name;
    this->turno = turno;
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

Player::~Player()
{
    //dtor
}
