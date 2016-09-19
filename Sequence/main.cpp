#include <QApplication>
#include <QFontDatabase>
#include "Control.h"
#include "Game.h"
#include "CircleList.h"
#include "Player.h"
#include "ArrayStack.h"
#include "CardDeck.h"

Control * game; // puntero al controlador


int SIZE_LIST;
int TOTAL_PLAYERS;
CardButton* cartaJugador = NULL;
CardButton* cartaTablero = NULL;

int main(int argc, char *argv[]){
    QApplication a(argc, argv);
    //Crea una fuente de texto personalizada y la añade al proyecto.
    int id = QFontDatabase::addApplicationFont(":/Resources/Resources/Fonts/press_start_2p/PressStart2P.ttf");
    QString family = QFontDatabase::applicationFontFamilies(id).at(0);
    QFont font(family);
    QFont myFont= font;
    QApplication::setFont(myFont); //Escoge la fuente de texto predeterminada

    //PRUEBA PRUEBA PRUEBA PRUEBA PRUEBA PRUEBA
   /* SIZE_LIST = 7;
    Player* Jugador = new Player();
    Jugador->setName("Carlos");
    Jugador->setTurno(1);
    Jugadores.gotoEnd();
    Jugadores.insert(Jugador);

    Player* Jugador2 = new Player();
    Jugador2->setName("Marcelo");
    Jugador2->setTurno(2);
    Jugadores.gotoEnd();
    Jugadores.insert(Jugador2);
    TOTAL_PLAYERS = 2;*/

    //END PRUEBA END PRUEBA END PRUEBAEND PRUEBA END PRUEBA


    // se va a programa
    game = new Control(); // se crea la instancia del juego
    game->show(); // muestra la escena con sus objetos



    //Game *board = new Game();
    //board->show();






    return a.exec();
}
