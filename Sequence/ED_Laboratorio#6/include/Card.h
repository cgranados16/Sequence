#ifndef CARD_H
#define CARD_H
#include <iostream>

using namespace std;

class Card
{
    public:
        Card();
        virtual ~Card();
        string getType();
        void setType(string type);
        char getValue();
        void setValue(int value);
        void toString();
    protected:

    private:
        string type;
        int value;
};

#endif // CARD_H
