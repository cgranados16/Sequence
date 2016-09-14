#include <QString>
#include "Card.h"
#include <iostream>
#include <stdexcept>
#include <string>
#include <sstream>
using namespace std;

Card::Card(){
    this->type="";
    this->value=0;
}
string Card::getType(){
    return type;
}

void Card::setType(string type){
    this->type= type;
}

int Card::getValue(){
    return value;
}

void Card::setValue(int value){
    if (0>value && value<13){
        throw runtime_error("Entrada invalida");
    }
    this->value = value;
}

string Card::toString(){
    string name;
    if (value==1 || value>10){
        switch(value){
            case 1:
                name= "A"; break;
            case 11:
                name = "J"; break;
            case 12:
                name = "Q"; break;
            case 13:
                name = "K"; break;
        }
        name += type;
    }else{
        name = std::to_string(value)+type;
    }
    return name;
}

void Card::setId(int id){
    this->id = id;
}
int Card::getId(){
    return id;
}


void Card::setPlayer(string player){
    this->player = player;
}

string Card::getPlayer(){
    return player;
}

void Card::setSide(int side){
    this->side = side;
}

int Card::getSide(){
    return side;
}

Card::~Card(){
    type="";
    value=0;
}
