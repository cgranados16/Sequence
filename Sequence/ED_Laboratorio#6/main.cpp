#include <iostream>
#include "ArrayStack.h"
#include "ArrayList.h"
#include "LinkedStack.h"
#include "CircleList.h"
#include "Card.h"
#include "Player.h"
using namespace std;

int main(){
    ArrayList<Card> CardsDeck(19);
    for (int i=1;i<14;i++){
        Card miCarta;
        miCarta.setType("Corazones");
        miCarta.setValue(i);
        miCarta.toString();
        CardsDeck.insert(miCarta);


    }
    //CardsDeck.next();
    int a=CardsDeck.getPos();
    cout<<"Posicion: "<<a<<endl;
    a=CardsDeck.getSize();
    cout<<"Size de la lista: "<<a<<endl;
    Card Cartita=CardsDeck.remove();
    Cartita.toString();
    a=CardsDeck.getSize();
        cout<<"Size: "<<a;
    CardsDeck.gotoStart();

    CircleList<Player> Jugadores;
    Player miPlayo;
    miPlayo.setName("Zurdo");
    miPlayo.setTurno(1);
    Jugadores.insert(miPlayo);
    a=Jugadores.getSize();
    cout<<endl<<endl<<a;
    miPlayo.setName("Jorge");
    miPlayo.setTurno(1);
    Jugadores.insert(miPlayo);
    a=Jugadores.getSize();
    int e=Jugadores.getPos();





}
