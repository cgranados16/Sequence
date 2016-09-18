#ifndef CONTROL_H
#define CONTROL_H

#include "Button.h"
#include <QSpinBox>
#include <QLineEdit>
#include <QBrush>
#include <QImage>
#include <QObject>
#include <QPushButton>
#include <QSignalMapper>
using namespace std;


class Button;
class Control : public QGraphicsView
{
    Q_OBJECT
public:
    Control();
    QGraphicsScene* scene; // creo que debe ir private


private:
    Button* startButton;
    Button* exitButton;
    Button* nextButton;
    Button *backButton;
    QSignalMapper* signalMapper;
    QLineEdit* playerNameBox;
    QString playerName;

signals:
    void enterPressed();
public slots:
    void mainWindow();
    void selectionWindow();
    void inputNames(int playerNum);
    void addPlayer(int i);

    void setPlayersNum(int i);
    void loadingScreen();
    void startGame();
    void changeName(QString e);
};

#endif // CONTROL_H

