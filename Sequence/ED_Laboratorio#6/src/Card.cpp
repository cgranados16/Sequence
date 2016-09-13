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

char Card::getValue(){
    return value;
}

void Card::setValue(int value){
    if (0>value && value<13){
        throw runtime_error("Entrada invalida");
    }
    this->value = value;
}
void Card::toString(){
    if (value==1 || value>10){
        string name;
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
        cout<<name<<" de "<<type<<endl;
    }else{
        cout<<value<<" de "<<type<<endl;
    }
}

Card::~Card(){
    //dtor
}
