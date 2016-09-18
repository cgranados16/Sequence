#ifndef MYQGRAPHICSSCENE_H
#define MYQGRAPHICSSCENE_H
#include <QGraphicsScene>


class MyQGraphicsScene :public QGraphicsScene
{
    Q_OBJECT
public:
    MyQGraphicsScene();

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void keyPressEvent(QKeyEvent *event);
signals:
    void endRound();
};

#endif // MYQGRAPHICSSCENE_H

