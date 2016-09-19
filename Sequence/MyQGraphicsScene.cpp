#include "MyQGraphicsScene.h"
#include <QDebug>
#include <QGraphicsSceneMouseEvent>
#include <QKeyEvent>
#include "cardbutton.h"
#include "LinkedList.h"
#include "game.h"
#include "Token.h"


extern CircleList<Player*>* Jugadores;
extern CardButton* cartaJugador;
extern CardButton* cartaTablero;
LinkedList<CardButton*>* tempList = new LinkedList<CardButton*>;
MyQGraphicsScene::MyQGraphicsScene(){informationText= NULL;}


void MyQGraphicsScene::mousePressEvent(QGraphicsSceneMouseEvent *event){
    QGraphicsScene::mousePressEvent(event);
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
                    }
                }
                //Setear Carta seleccionada del Tablero luego de seleccionar la del Jugador
            }if (cartaJugador){
                if (event->scenePos().x()>=200 && event->scenePos().x()<=1030&&
                        event->scenePos().y()>=0 && event->scenePos().y()<=610){
                    if (cartaTablero ==  NULL){
                        cartaTablero = dynamic_cast<CardButton*>(item);
                    }

                } if (event->scenePos().x()>=50 && event->scenePos().x()<=160 &&
                      event->scenePos().y()>=100 && event->scenePos().y()<=250){
                    emit endRound();
                }
            }
        }
        if (cartaJugador && cartaTablero){
            if(informationText){
                removeItem(informationText);
                informationText = NULL;
            }
            if (cartaJugador->getCard()->toString()==cartaTablero->getCard()->toString()){
                if (!cartaTablero->getCard()->hasToken()){
                    Token * addToken = new Token(Jugadores->getElement(),cartaTablero->pos().x()-7,cartaTablero->pos().y()-2.45);
                    addToken->setRotation(90);
                    addItem(addToken);
                    cartaTablero->getCard()->setToken(addToken);
                    cartaTablero->getCard()->setPlayer(Jugadores->getElement());
                    emit endRound();
                    cartaTablero = NULL;
                }else{
                    informationText = new QGraphicsTextItem("Esta carta ya posee un Token.");
                    informationText->setPos(0,650);
                    addItem(informationText);
                }
            }else if (cartaJugador->getCard()->getValue()==11){
                /*  Si la carta es una J:
             **   One-eyed Jack:
             ***       Remueve un token de otro jugador
             **     Two-eyed Jack:
             ***        Puede usar una ficha en cualquier posicion del tablero
             **
             */
                //One-eyed Jack
                if (cartaJugador->getCard()->getType()=="Hearts" ||cartaJugador->getCard()->getType()=="Spades"){
                    if (cartaTablero->getCard()->hasToken()){
                        if (cartaTablero->getCard()->getToken()->getPlayer()!=Jugadores->getElement()){
                            Token* removeToken = cartaTablero->getCard()->getToken(); //Retorna el token de la carta
                            removeItem(removeToken); //Lo remueve de la escena
                            cartaTablero->getCard()->setPlayer(NULL);
                            cartaTablero->getCard()->setToken(NULL); //Borra el token de la carta
                            emit endRound();

                        }else{
                            informationText = new QGraphicsTextItem("No puede eliminar su propio Token");
                            informationText->setPos(0,650);
                            addItem(informationText);
                        }
                    }else{
                        informationText = new QGraphicsTextItem("Elija una carta con Token.");
                        informationText->setPos(0,650);
                        addItem(informationText);
                    }
                    //Two-eyed Jack
                }else if(cartaJugador->getCard()->getType()=="Diamonds" || cartaJugador->getCard()->getType()=="Clubs"){
                    if (!(cartaTablero->getCard()->hasToken())){
                        Token * addToken = new Token(Jugadores->getElement(),cartaTablero->pos().x()-7,cartaTablero->pos().y()-2.45);
                        addToken->setRotation(90);
                        addItem(addToken);
                        cartaTablero->getCard()->setToken(addToken);
                        cartaTablero->getCard()->setPlayer(Jugadores->getElement());
                        emit endRound();
                    }else{
                        informationText = new QGraphicsTextItem("Esta carta ya posee un Token.");
                        informationText->setPos(0,650);
                        addItem(informationText);
                        cartaJugador->resetPos();
                    }
                }
                cartaTablero = NULL;
                //Si la carta del Tablero es un comodin
            }else if(cartaTablero->getCard()->getValue()==0){
                if (!(cartaTablero->getCard()->hasToken())){
                    Token * addToken = new Token(Jugadores->getElement(),cartaTablero->pos().x()-7,cartaTablero->pos().y()-2.45);
                    addToken->setRotation(90);
                    addItem(addToken);
                    cartaTablero->getCard()->setToken(addToken);
                    cartaTablero->getCard()->setPlayer(Jugadores->getElement());
                    emit endRound();
                }else{
                    informationText = new QGraphicsTextItem("Esta carta ya posee un Token.");
                    informationText->setPos(0,650);
                    addItem(informationText);
                    cartaJugador->resetPos();
                }
                cartaTablero = NULL;
            }else{
                //Si no ocurre ningun caso posible, pone los punteros a NULL.
                cartaJugador->resetPos();
                cartaJugador = NULL;
                cartaTablero = NULL;
            }

        }

    }
}

void MyQGraphicsScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->scenePos().x()>1150 && event->scenePos().x()<1300 &&
        event->scenePos().y()>100 && event->scenePos().y()<600){
    }
    QGraphicsScene::mouseMoveEvent(event);
}

void MyQGraphicsScene::keyPressEvent(QKeyEvent * event) {
    if(event->key() == Qt::Key_Backspace) {
        // remove all selected items
        while(!selectedItems().isEmpty()) {
            removeItem(selectedItems().front());
        }
    } else {
        QGraphicsScene::keyPressEvent(event);
    }
}
