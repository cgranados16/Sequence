#include "Control.h"

#include <QFontDatabase>
#include <QMessageBox>
#include "CircleList.h"
#include "player.h"
#include <QDebug>

#include "Game.h"
#include <QTimeLine>
#include <QGraphicsItemAnimation>
#include <ctime>

extern int playersNum;
extern CircleList<Player> players;
extern QFont myFont;
extern CircleList<Player> Jugadores;
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
    mainWindow();
    signalMapper = new QSignalMapper (this) ;
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

    connect (twoPlayersButton, SIGNAL(clicked()), signalMapper, SLOT(map()));
    connect (threePlayersButton, SIGNAL(clicked()), signalMapper, SLOT(map()));
    connect (fourPlayersButton, SIGNAL(clicked()), signalMapper, SLOT(map()));

    signalMapper -> setMapping (twoPlayersButton, 2) ;
    signalMapper -> setMapping (threePlayersButton, 3) ;
    signalMapper -> setMapping (fourPlayersButton, 4) ;
    connect (signalMapper, SIGNAL(mapped(int)), this, SLOT(setPlayersNum(int))) ;
    connect (signalMapper, SIGNAL(mapped(int)), this, SLOT(inputNames(int))) ;

}

void Control::setPlayersNum(int i){
    playersNum = i;
}

void Control::inputNames(int i){
    scene->clear();
    nextButton= new Button("Next","NextEnter",580,480);
    scene->addItem(nextButton);
    backButton= new Button("Back","BackEnter",100,480);
    scene->addItem(backButton);
    QObject::connect(backButton,SIGNAL(clicked()),this,SLOT(selectionWindow()));
    QString text = ("Ingrese el nombre del jugador ");
    QGraphicsTextItem* item2 = new QGraphicsTextItem(text+QString::number((i%playersNum)+1));
    item2->setDefaultTextColor(Qt::white);
    item2->setPos(160,220);
    scene->addItem(item2);
    playerNameBox = new QLineEdit;
    playerNameBox->setGeometry(180,280,450,30);
    scene->addWidget(playerNameBox);
    connect(playerNameBox, SIGNAL(textChanged(QString)), this, SLOT(changeName(QString))); //Conecta la senal del input a la funcion Change Name

    connect (nextButton, SIGNAL(clicked()), signalMapper, SLOT(map())); //Conecta el boton Next
    connect (playerNameBox, SIGNAL(returnPressed()), signalMapper, SLOT(map())); //Conecta el Enter
    signalMapper -> setMapping (nextButton, i);
    signalMapper -> setMapping (playerNameBox, i);
    connect (signalMapper, SIGNAL(mapped(int)), this, SLOT(addPlayer(int))) ;
    connect(signalMapper, SIGNAL(mapped(int)), this, SLOT(addPlayer(int)));
    playerNameBox->setFocus();
}

void Control::changeName(QString e){
    playerName = e;
    qDebug()<< playerName;

}

void Control::addPlayer(int i){
    if (playerName!=""){
        qDebug()<< QString("Nombre de Jugador: ")+ playerName;
        Player Jugador;
        Jugador.setName(playerName.toStdString());
        Jugador.setTurno(i%playersNum);
        Jugadores.gotoEnd();
        Jugadores.insert(Jugador);
        playerNameBox->clear();
        playerName.clear();
        if (i==1){
            Jugadores.gotoStart();
            for (int i=0;i<Jugadores.getSize();i++){
                Player caca = Jugadores.getElement();
                qDebug() << QString::fromStdString(caca.getName());
                Jugadores.Next();
            }
            startGame();
        }else{
            inputNames(i-1);
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

void Control::startGame(){
    Jugadores.gotoStart();
    this->close();
    Game* board = new Game();
    board->show();
}
