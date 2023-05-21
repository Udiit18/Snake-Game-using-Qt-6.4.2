#ifndef SNAKE_MOVE_H
#define SNAKE_MOVE_H
#include <QKeyEvent>
#include <QGraphicsItem>
#include "snakepart.h"
#include<QMediaPlayer>
#include<QAudioOutput>

class SnakeMove:public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    SnakeMove(QGraphicsItem *parent = 0);

    void keyPressEvent(QKeyEvent *event);
    void makeBoard();
    void addPart();
    void moveSnake();

    QMediaPlayer *music;
    QAudioOutput *audioOutput;
public slots:
    void move();
    void makeFood();
private:
    SnakePart *snakeHead;
    SnakePart *snakeTail;
    QString direction;
    QTimer *t;
    QTimer *foodTimer;
    QGraphicsTextItem *text;
};

#endif // SNAKE_MOVE_H
