#ifndef CONTROL_H
#define CONTROL_H

#include "rectangulo.h"
#include "button.h"

#include <QSpinBox>
#include <QLineEdit>
#include <QBrush>
#include <QImage>
#include <QObject>
#include <QPushButton>
using namespace std;


class Button;
class Control : public QGraphicsView
{

public:
    Control();
    QGraphicsScene* scene; // creo que debe ir private
    void mainWindow();
    void selectionWindow();
    void inputNames(int i);
    void board();


private:
    Button* startButton;
    Button* exitButton;
    QFont s;


public slots:

};

#endif // CONTROL_H

