#include "snake_move.h"
#include "snakepart.h"
#include <QTimer>
#include "apple.h"
#include <QFont>
#include<QWidget>

SnakeMove::SnakeMove(QGraphicsItem *parent):QGraphicsRectItem(parent)
{
    snakeHead = new SnakePart(this);
    snakeHead->setForward(NULL);
    snakeHead->setBackward(NULL);
    snakeHead->setPos(200,200);
    snakeHead->setDirection("RIGHT");
    snakeHead->part = "HEAD";
    snakeHead->setImage();
    snakeTail = snakeHead;

    t = new QTimer();
    connect(t,SIGNAL(timeout()),this,SLOT(move()));

    foodTimer = new QTimer();
    connect(foodTimer,SIGNAL(timeout()),this,SLOT(makeFood()));

    direction = "RIGHT";

    addPart();
    addPart();
    addPart();

    text = new QGraphicsTextItem(this);
    text->setVisible(true);

    text->setPlainText("Press Space to continue");
    text->setPos(300,240);
    text->setFont(QFont("Courier",36));

    music = new QMediaPlayer;
    audioOutput = new QAudioOutput;
    music->setAudioOutput(audioOutput);
}

void SnakeMove::keyPressEvent(QKeyEvent *event)
{
    music ->setSource(QUrl(":/Audio/Audio/up.mp3"));
    if(event->key() == Qt::Key_Down && snakeHead->getDirection() != "UP") {
        direction = "DOWN";        
        music->play();
    }
    else if(event->key() == Qt::Key_Up && snakeHead->getDirection() != "DOWN") {
        direction = "UP";        
        music->play();
    }
    else if(event->key() == Qt::Key_Right && snakeHead->getDirection() != "LEFT") {
        direction = "RIGHT";        
        music->play();
    }
    else if(event->key() == Qt::Key_Left && snakeHead->getDirection() != "RIGHT") {
        direction = "LEFT";        
        music->play();
    }
    else if(event->key() == Qt::Key_Space)
    {
        if(t->isActive()){
            foodTimer->stop();
            t->stop();
            text->setVisible(true);
        }
        else
        {
            foodTimer->start(3000);
            t->start(90);
            text->setVisible(false);
        }
    }    
}

void SnakeMove::makeBoard()
{
    qDebug()<<"hello";
    for(int i = 0 ;i <9*5;i++)
    {
        for(int j = 0; j < 14*5; j++)
        {
            QGraphicsRectItem *rect= new QGraphicsRectItem(this);
            rect->setRect(j*20,i*20,20,20);
        }
    }
}

void SnakeMove::move() {
    snakeHead->setDirection(direction);
    moveSnake();
}

void SnakeMove::makeFood()
{
    apple * f1 = new apple(this);
    f1->setX(rand() % (1260/20)* 20);
    f1->setY(rand() % (580/20) * 20) ;
}

void SnakeMove::addPart(){
    SnakePart *part = new SnakePart(this);
    SnakePart *temp = snakeHead;
    while(temp->getBackward() != NULL)
    {
        temp = temp->getBackward();
    }
    temp->setBackward(part);
    part->setForward(temp);
    part->setBackward(NULL);
    part->addBehind();
    part->setDirection(temp->getDirection());
    snakeTail = part;
    part->part = "TAIL";
    if(temp != snakeHead)
        temp->part = "PART";
    part->setImage();
    temp->setImage();
}

void SnakeMove::moveSnake()
{
   SnakePart *temp = snakeTail;
   while(temp!=NULL)
   {
       temp->move();
       temp = temp->getForward();
   }
}
