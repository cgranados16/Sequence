#ifndef CARDDECK_H
#define CARDDECK_H

#include "ArrayStack.h"
#include "Card.h"
#include <ctime>

class Card;

class CardDeck : public ArrayStack<Card>
{
public:
    CardDeck();
    virtual ~CardDeck();
    void random();
    void swap(int pos, int swapPos);
    ArrayList<Card> defaultBoard();
private:
    int id;

};

#endif // CARDDECK_H
