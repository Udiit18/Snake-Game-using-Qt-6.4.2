#ifndef GAME_H
#define GAME_H

#include<QGraphicsView>
#include<QGraphicsScene>
#include "buttons.h"
#include <QWidget>
#include<QMainWindow>
#include<QApplication>
#include<QString>
#include "score.h"
#include<QKeyEvent>
#include"snake_move.h"
#include<QGraphicsPixmapItem>
#include<QGraphicsTextItem>

class Game:public QGraphicsView
{
    Q_OBJECT
public:
    Game(QWidget *parent = 0);
    void keyPressEvent(QKeyEvent* event);
    Score *score;
    void  gameOver();
    void displayMainMenu(QString t, QString p);
    SnakeMove *snake,*snake2;
    QGraphicsScene *gameScene;
    QGraphicsTextItem *titleText;
    Button *Play,*Quit;
    QGraphicsPixmapItem *bg;   
public slots:
    void start();
};

#endif // GAME_H
