#include <iostream>
#include <cstdlib>
#include <ctime>
#include "ArrayStack.h"
#include "Card.h"
#include "CircleList.h"
#include "Player.h"
#include "LinkedList.h"
using namespace std;

int main(){

    ArrayList<Card> CardsDeck(54);
    int id=0;
    for (int i=1;i<14;i++){
        Card miCarta;
        miCarta.setType("Corazones");
        miCarta.setValue(i);
        miCarta.setId(id++);
        CardsDeck.append(miCarta);
    }
    for (int i=1;i<14;i++){
        Card miCarta;
        miCarta.setType("Diamantes");
        miCarta.setValue(i);
        miCarta.setId(id++);
        CardsDeck.append(miCarta);
    }
    for (int i=1;i<14;i++){
        Card miCarta;
        miCarta.setType("Picas");
        miCarta.setValue(i);
        miCarta.setId(id++);
        CardsDeck.append(miCarta);
    }
    for (int i=1;i<14;i++){
        Card miCarta;
        miCarta.setType("Trebol");
        miCarta.setValue(i);
        miCarta.setId(id++);
        CardsDeck.append(miCarta);
    }

    cout<<"Mazo1"<<endl;
    ArrayStack<Card> Mazo1(54);
    srand((int) time(0));
    while (Mazo1.getSize()!=CardsDeck.getSize()){
        int r = (rand() % CardsDeck.getSize());
        int que;
        for (int i=0;i<CardsDeck.getSize();i++){
            Card comp=Mazo1.getValue();
            que=Mazo1.secuencial(r);
            if (que==-1){
                CardsDeck.gotoPos(r);
                Card insertar=CardsDeck.getValue();
                Mazo1.push(insertar);
                insertar.toString();
            }
        }
    }
    cout<<"Mazo 2"<<endl;
    ArrayStack<Card> Mazo2(54);
    srand((int) time(0));
    while (Mazo2.getSize()!=CardsDeck.getSize()){
        int r = (rand() % CardsDeck.getSize());
        int que;
        for (int i=0;i<CardsDeck.getSize();i++){
            Card comp=Mazo2.getValue();
            que=Mazo2.secuencial(r);
            if (que==-1){
                CardsDeck.gotoPos(r);
                Card insertar=CardsDeck.getValue();
                Mazo2.push(insertar);
                insertar.toString();
            }
        }

    }
    int size=Mazo1.getSize();
    cout<<"Size del random: "<<size<<endl;
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
    int numPlayers;
    cout<<"Ingrese el numero de jugadores";
    cin>>numPlayers;
    string playerName;
    for (int i=1;i<=numPlayers;i++){
        cout<<"Ingrese nombre del jugador "<<i;
        cin>>playerName;
        Jugador.setName(playerName);
        Jugador.setTurno(i);
        Jugadores.gotoEnd();
        Jugadores.insert(Jugador);
    }
    Player actual;
    string actualName;
    Card miCarta;
    Jugadores.gotoStart();
    ArrayStack<Card> Player1(7);
    actual=Jugadores.getElement();
    actualName=actual.getName();
    cout<<"Turno de: "<<actualName<<endl;
    for (int i=0;i<7;i++){
        Card a=Mazo1.pop();
        a.setPlayer(actualName);
        Player1.append(a);
    }
    cout<<"Mazo de "<<actualName<<endl;
    for (int i=0;i<Player1.getSize();i++){
        Card a= Player1.getValue();
        if (a.getPlayer()==actualName);
            a.toString();
        Player1.next();
    }
    Jugadores.Next();
    ArrayStack<Card> Player2(7);
    actual=Jugadores.getElement();
    actualName=actual.getName();
    cout<<"Turno de: "<<actualName<<endl;
    for (int i=0;i<7;i++){
        Card a=Mazo1.pop();
        a.setPlayer(actualName);
        Player2.append(a);
    }
    cout<<"Mazo de "<<actualName<<endl;
    for (int i=0;i<Player2.getSize();i++){
        Card a= Player2.getValue();
        if (a.getPlayer()==actualName);
            a.toString();
        Player2.next();
    }

    size=Mazo1.getSize();
    cout<<"Size del random: "<<size<<endl;
}
