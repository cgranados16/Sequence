#ifndef CARDDECK_H
#define CARDDECK_H

#include "ArrayStack.h"
#include "Card.h"
#include "matriz.h"


class Card;

class CardDeck : public ArrayStack<Card*>
{
public:
    CardDeck();
    virtual ~CardDeck();
    Matriz<Card*> *defaultBoard();
    Matriz<Card *> *randomBoard();
    ArrayStack<Card *>* getStack();

private:
    int id;

};

#endif // CARDDECK_H
