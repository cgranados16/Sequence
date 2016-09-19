#-------------------------------------------------
#
# Project created by QtCreator 2016-09-09T03:48:49
#
#-------------------------------------------------

QT       += core gui
RC_FILE = myapp.rc

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Sequence
TEMPLATE = app



SOURCES += main.cpp \
    ArrayList.cpp \
    ArrayStack.cpp \
    Button.cpp \
    Card.cpp \
    CardButton.cpp \
    CircleList.cpp \
    LinkedList.cpp \
    Node.cpp \
    Player.cpp \
    Control.cpp \
    Game.cpp \
    CardDeck.cpp \
    MyQGraphicsScene.cpp \
    Matriz.cpp \
    Token.cpp \
    LinkedStack.cpp

HEADERS  += \
    ArrayList.h \
    ArrayStack.h \
    Card.h \
    CardButton.h \
    CircleList.h \
    LinkedList.h \
    Node.h \
    Player.h \
    Game.h \
    Control.h \
    Button.h \
    CardDeck.h \
    MyQGraphicsScene.h \
    Matriz.h \
    Token.h \
    LinkedStack.h

RESOURCES += \
    resources.qrc
