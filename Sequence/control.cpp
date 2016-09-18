#include "Control.h"

#include <QFontDatabase>
#include <QMessageBox>
#include "CircleList.h"
#include "player.h"
#include <QDebug>

#include <QTimer>
#include "Game.h"
#include <QTimeLine>
#include <QGraphicsItemAnimation>
#include <ctime>

extern int TOTAL_PLAYERS;
extern CircleList<Player*> Jugadores;
QLineEdit* playerNameBox;

extern Game* board;


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
    signalMapper = new QSignalMapper (this) ;
    mainWindow();

}

void Control::mainWindow(){
    scene->clear();
    //Crea el boton Start
    startButton= new Button("Start","StartEnter",315,300);
    scene->addItem(startButton);
    QObject::connect(startButton,SIGNAL(clicked()),this,SLOT(selectionWindow()));

    //Crea el boton Exit
    exitButton= new Button("End","ExitEnter",330,350);
    scene->addItem(exitButton);
    QObject::connect(exitButton,SIGNAL(clicked()),this,SLOT(close()));
}

void Control::selectionWindow(){
    Jugadores.clear();
    scene->clear();
    backButton= new Button("Back","BackEnter",100,480);
    scene->addItem(backButton);
    QObject::connect(backButton,SIGNAL(clicked()),this,SLOT(mainWindow()));
    Button *twoPlayersButton= new Button("2Players","2PlayersEnter",250,250);
    scene->addItem(twoPlayersButton);
    Button *threePlayersButton= new Button("3Players","3PlayersEnter",250,300);
    scene->addItem(threePlayersButton);
    Button *fourPlayersButton= new Button("4Players","4PlayersEnter",250,350);
    scene->addItem(fourPlayersButton);
    QGraphicsTextItem* item1 = new QGraphicsTextItem("Ingrese numero de jugadores:");
    item1->setDefaultTextColor(Qt::white);
    item1->setPos(180,200);
    scene->addItem(item1);

    QSignalMapper* playerMap = new QSignalMapper (this) ;

    connect (twoPlayersButton, SIGNAL(clicked()), playerMap, SLOT(map()),Qt::UniqueConnection);
    connect (threePlayersButton, SIGNAL(clicked()), playerMap, SLOT(map()),Qt::UniqueConnection);
    connect (fourPlayersButton, SIGNAL(clicked()), playerMap, SLOT(map()),Qt::UniqueConnection);

    playerMap -> setMapping (twoPlayersButton, 2) ;
    playerMap -> setMapping (threePlayersButton, 3) ;
    playerMap -> setMapping (fourPlayersButton, 4) ;
    connect (playerMap, SIGNAL(mapped(int)), this, SLOT(setPlayersNum(int))) ;
}

void Control::setPlayersNum(int i){
    TOTAL_PLAYERS = i;
    if (TOTAL_PLAYERS>=3){
        SIZE_LIST = 6;
    }else{
        SIZE_LIST = 7;
    }
    qDebug() << TOTAL_PLAYERS;
    inputNames(1);
}

void Control::inputNames(int playerNum){
    scene->clear();
    nextButton= new Button("Next","NextEnter",580,480);
    scene->addItem(nextButton);
    backButton= new Button("Back","BackEnter",100,480);
    scene->addItem(backButton);
    QObject::connect(backButton,SIGNAL(clicked()),this,SLOT(selectionWindow()),Qt::UniqueConnection);
    QString text = ("Ingrese el nombre del jugador ");
    QGraphicsTextItem* playerCount = new QGraphicsTextItem(text+QString::number(playerNum));
    playerCount->setDefaultTextColor(Qt::white);
    playerCount->setPos(160,220);
    scene->addItem(playerCount);
    playerNameBox = new QLineEdit;
    playerNameBox->setGeometry(180,280,450,30);
    playerNameBox->setMaxLength(10);
    connect(playerNameBox, SIGNAL(textChanged(QString)), this, SLOT(changeName(QString))); //Conecta la senal del input a la funcion Change Name
    connect (playerNameBox, SIGNAL(returnPressed()), signalMapper, SLOT(map())); //Conecta el Enter
    connect (nextButton, SIGNAL(clicked()), signalMapper, SLOT(map()),Qt::UniqueConnection); //Conecta el boton Next
    signalMapper -> setMapping (nextButton, playerNum);
    signalMapper -> setMapping (playerNameBox, playerNum);
    connect (signalMapper, SIGNAL(mapped(int)), this, SLOT(addPlayer(int)),Qt::UniqueConnection) ;
    connect(signalMapper, SIGNAL(mapped(int)), this, SLOT(addPlayer(int)),Qt::UniqueConnection);
    scene->addWidget(playerNameBox);
    playerNameBox->setFocus();
}

void Control::changeName(QString e){
    playerName = e;
    qDebug()<< playerName;

}

void Control::addPlayer(int i){
    if (playerName!=""){
        qDebug()<< QString("Nombre de Jugador: ")+ playerName;
        Player* Jugador = new Player();
        Jugador->setName(playerName.toStdString());
        Jugador->setTurno(i);
        Jugadores.gotoEnd();
        Jugadores.insert(Jugador);
        playerNameBox->clear();
        playerName.clear();
        if (i>=TOTAL_PLAYERS){
            loadingScreen();

        }else{
            inputNames(i+1);
        }
    }else{
        QGraphicsTextItem* WarningMsg = new QGraphicsTextItem("¡Nombre no puede estar vacio!");
        WarningMsg->setDefaultTextColor(Qt::white);
        WarningMsg->setPos(180,320);
        scene->addItem(WarningMsg);
        /*
         * Crea una pequena animacion con el Warning Message
         *
         * */
        /*        QTimeLine *timer = new QTimeLine(5000);
        timer->setFrameRange(0, 100);
        QGraphicsItemAnimation *animation = new QGraphicsItemAnimation;
        animation->setItem(WarningMsg);
        animation->setTimeLine(timer);
        srand((int) time(0));
        for (int i = 0; i < 40; ++i){
             animation->setPosAt(i/200.0, QPointF(rand() % 182 + 178,320));
        }
        scene->addItem(WarningMsg);
        timer->start();*/
    }
}

void Control::loadingScreen(){
    scene->clear();
    QGraphicsTextItem* loadingText = new QGraphicsTextItem("Cargando...");
    loadingText->setDefaultTextColor(Qt::white);
    loadingText->setPos(230,300);
    loadingText->setScale(2);
    scene->addItem(loadingText);
    QTimer::singleShot(0.01, this, SLOT(startGame()));

}

void Control::startGame(){
    Jugadores.gotoStart();
    Game* board = new Game();
    this->close();
    board->show();
}

