#include "MyQGraphicsScene.h"
#include <QDebug>
#include <QGraphicsSceneMouseEvent>
#include <QKeyEvent>
#include "cardbutton.h"
#include "LinkedList.h"
#include "game.h"
#include "Token.h"

extern LinkedList<Card*> *Trash;
extern CircleList<Player*> Jugadores;
extern CardButton* cartaJugador;
extern CardButton* cartaTablero;
LinkedList<CardButton*>* tempList = new LinkedList<CardButton*>;
MyQGraphicsScene::MyQGraphicsScene(){}


void MyQGraphicsScene::mousePressEvent(QGraphicsSceneMouseEvent *event){
    QGraphicsScene::mousePressEvent(event);
    qDebug() << event->scenePos();
    foreach(auto item, items(event->scenePos())) {
        if(item->type() == QGraphicsItem::UserType+1) {
            if (event->scenePos().x()>=1120 && event->scenePos().x()<=1300 &&
                    event->scenePos().y()>=50 && event->scenePos().y()<=640){
                if (cartaJugador ==  NULL){
                    cartaJugador = dynamic_cast<CardButton*>(item);
                    cartaJugador->setPos(cartaJugador->getX()-30,cartaJugador->getY());
                }else{
                    /*Pregunta si las dos cartas apuntan al mismo
                     *  Si no se cambia la carta seleccionada por el Jugador
                     */
                    CardButton* temp = dynamic_cast<CardButton*>(item);
                    if (cartaJugador->getCard()->toString() != temp->getCard()->toString()){
                        cartaJugador->resetPos(); //reinicia la posicion de la carta
                        cartaJugador = dynamic_cast<CardButton*>(item);
                        cartaJugador->setPos(cartaJugador->getX()-30,cartaJugador->getY());
                        qDebug() << "Son la misma";
                    }
                    qDebug() << "Ya tiene";
                }
                qDebug() << QString::fromStdString(cartaJugador->getCard()->toString());
            //Setear Carta seleccionada del Tablero luego de seleccionar la del Jugador
            }if (cartaJugador){
                if (event->scenePos().x()>=200 && event->scenePos().x()<=1030&&
                      event->scenePos().y()>=0 && event->scenePos().y()<=610){
                if (cartaTablero ==  NULL){
                    cartaTablero = dynamic_cast<CardButton*>(item);
                }
                qDebug() << QString::fromStdString(cartaTablero->getCard()->toString());
                }
            }else{
                qDebug() << "Noup";
            }
        }
        if (cartaJugador && cartaTablero){
            qDebug() << "entra";
            if (cartaJugador->getCard()->toString()==cartaTablero->getCard()->toString() || cartaJugador->getCard()->getValue()==11){
                if (cartaJugador->getCard()->getPlayer()!=0){
                    Token * addToken = new Token(Jugadores.getElement(),cartaTablero->pos().x()-7,cartaTablero->pos().y()-2.45);
                    addToken->setRotation(90);
                    addItem(addToken);
                    //cartaTablero->getCard()->setToken(addToken);
                    //Trash->append(value1);
                }else if (cartaTablero->getCard()->getPlayer()!=0){
                    qDebug() <<"DICKS OUT2";
                    //Trash.append(value2);
                }
                emit endRound();

            }
            //Borra los punteros
            cartaJugador->resetPos();
            cartaJugador = NULL;
            cartaTablero = NULL;

        }
    }
}




void MyQGraphicsScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->scenePos().x()>1150 && event->scenePos().x()<1300 &&
        event->scenePos().y()>100 && event->scenePos().y()<600){
        //qDebug() << "Custom scene moved.";
    }
    QGraphicsScene::mouseMoveEvent(event);
}

void MyQGraphicsScene::keyPressEvent(QKeyEvent * event) {
    if(event->key() == Qt::Key_Backspace) {
        // remove all selected items
        qDebug() << "selected items" << selectedItems().size();
        while(!selectedItems().isEmpty()) {
            removeItem(selectedItems().front());
        }
    } else {
        QGraphicsScene::keyPressEvent(event);
    }
}
