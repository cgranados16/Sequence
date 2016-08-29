#include <iostream>
#include "ArrayStack.h"
#include "Card.h"
#include "CircleList.h"
#include "Player.h"
#include "LinkedList.h"
using namespace std;

int main(){

    ArrayStack<Card> CardsDeck(54);
    for (int i=1;i<14;i++){
        Card miCarta;
        miCarta.setType("Corazones");
        miCarta.setValue(i);
        miCarta.toString();
        CardsDeck.push(miCarta);
    }
    for (int i=1;i<14;i++){
        Card miCarta;
        miCarta.setType("Diamantes");
        miCarta.setValue(i);
        miCarta.toString();
        CardsDeck.push(miCarta);
    }
    for (int i=1;i<14;i++){
        Card miCarta;
        miCarta.setType("Picas");
        miCarta.setValue(i);
        miCarta.toString();
        CardsDeck.push(miCarta);
    }
    for (int i=1;i<14;i++){
        Card miCarta;
        miCarta.setType("Trebol");
        miCarta.setValue(i);
        miCarta.toString();
        CardsDeck.push(miCarta);
    }
    int size=CardsDeck.getSize();
    cout<<"Size de la lista: "<<size<<endl<<endl;

   /* cout<<endl;
    for (int i=0;i<3;i++){
        Card a=CardsDeck.pop();
        cout<<"Toma una carta: "<<endl;
        a.toString();
    }
    size=CardsDeck.getSize();
    cout<<"Size de la lista: "<<size<<endl;*/


    CircleList<Player> Jugadores;
    Player Jugador;
    Jugador.setName("Zurdo");
    Jugador.setTurno(1);
    Jugadores.insert(Jugador);
    Jugador.setName("Carlos");
    Jugador.setTurno(1);
    Jugadores.insert(Jugador);
    Jugador.setName("Marcelo");
    Jugador.setTurno(1);
    Jugadores.insert(Jugador);
    Jugador.setName("Juan");
    Jugador.setTurno(1);
    Jugadores.insert(Jugador);
    Player actual;
    string actualName;
    Card miCarta;
    for (int i=0;i<3;i++){
        actual=Jugadores.getElement();
        actualName=actual.getName();
        cout<<"Turno de: "<<actualName<<endl;
        Card a=CardsDeck.pop();
        cout<<"Toma una carta: "<<endl;
        a.setPlayer(actualName);
        a.toString();
    }
    for (int i=0;i<CardsDeck.getSize();i++){
        if (miCarta.getPlayer()==actualName){

        }
    }
    cout<<"Turno de: "<<actualName<<endl;
    Jugadores.Next();


}
