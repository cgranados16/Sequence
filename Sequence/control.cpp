#include "control.h"

#include <QFontDatabase>
#include <QMessageBox>
#include "CircleList.h"
#include "player.h"
#include <QDebug>

extern int playersNum;
extern CircleList<Player> players;
QLineEdit* playerNameBox;
Control::Control()
{
    this->scene = new QGraphicsScene();
    scene->setSceneRect(0, 0, 800, 600);
    scene->setBackgroundBrush(Qt::magenta); // cambia el color de fondo de la pantalla

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff); // no crear scroll horizontal
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff); // no crear scroll vertical

    setFixedSize(800, 600); // le da un tamano fijp al view
    setBackgroundBrush(QBrush(QImage(":/Resources/Resources/Background.png"))); // agregar imagen de fondo
    setScene(this->scene); // cambia la escena por defecto a la que se eta creando

    int id = QFontDatabase::addApplicationFont(":/Resources/Resources/Fonts/press_start_2p/PressStart2P.ttf");
    QString family = QFontDatabase::applicationFontFamilies(id).at(0);
    QFont font(family);
    s= font;
    mainWindow();

}

void Control::mainWindow(){
    scene->clear();
    startButton= new Button("Start",":/Buttons/Resources/Buttons/StartEnter.png",315,300);
    scene->addItem(startButton);
    exitButton= new Button("End",":/Buttons/Resources/Buttons/ExitEnter.png",330,350);
    scene->addItem(exitButton);
}

void Control::selectionWindow(){
    startButton->~Button();
    exitButton->~Button();
    scene->clear();
    Button *backButton= new Button("Back1","/Buttons/Resources/Buttons/BackEnter.png",100,480);
    scene->addItem(backButton);
    Button *twoPlayersButton= new Button("2Players",":/Buttons/Resources/Buttons/2PlayersEnter.png",250,250);
    scene->addItem(twoPlayersButton);
    Button *threePlayersButton= new Button("3Players",":/Buttons/Resources/Buttons/3PlayersEnter.png",250,300);
    scene->addItem(threePlayersButton);
    Button *fourPlayersButton= new Button("4Players",":/Buttons/Resources/Buttons/4PlayersEnter.png",250,350);
    scene->addItem(fourPlayersButton);

    QGraphicsTextItem* item1 = new QGraphicsTextItem("Ingrese numero de jugadores:");
    item1->setFont(s);
    item1->setDefaultTextColor(Qt::white);
    item1->setPos(180,200);
    scene->addItem(item1);
    /*QGraphicsTextItem* item2 = new QGraphicsTextItem("Ingrese el modo de juego:");
    item2->setFont(s);
    item2->setDefaultTextColor(Qt::white);
    item2->setPos(180,300);
    scene->addItem(item2);*/
}

void Control::inputNames(int i){
    scene->clear();
    Button *nextButton= new Button("Next",":/Buttons/Resources/Buttons/NextEnter.png",580,480);
    scene->addItem(nextButton);
    Button *backButton= new Button("Back2",":/Buttons/Resources/Buttons/BackEnter.png",100,480);
    scene->addItem(backButton);
    QString text = ("Ingrese el nombre del jugador ");
    QGraphicsTextItem* item2 = new QGraphicsTextItem(text+QString::number(i));
    item2->setFont(s);
    item2->setDefaultTextColor(Qt::white);
    item2->setPos(180,220);
    scene->addItem(item2);
    playerNameBox = new QLineEdit;
    playerNameBox->setFont(s);
    playerNameBox->setGeometry(185,300,450,30);

    scene->addWidget(playerNameBox);
}


