#include <QApplication>
#include "control.h"
#include "game.h"
#include "CircleList.h"
#include "Player.h"
#include "ArrayStack.h"

Control * game; // puntero al controlador
Game* board;
CircleList<Player> Jugadores;
int playersNum;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // se va a programa
    /*game = new Control(); // se crea la instancia del juego
    game->show(); // muestra la escena con sus objetos
*/
    board = new Game();
    board->show();
    return a.exec();
}
