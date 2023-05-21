#include "snakepart.h"
#include <QBrush>
#include "apple.h"
#include <typeinfo>
#include<QGraphicsItem>
#include<QList>
#include<QMediaPlayer>
#include<QUrl>
#include<QAudioOutput>
#include "game.h"
extern Game *game;


SnakePart::SnakePart(QGraphicsItem *parent):QGraphicsPixmapItem(parent)
{
    setZValue(1);
    music = new QMediaPlayer;
    audioOutput = new QAudioOutput;
    music->setAudioOutput(audioOutput);
}

SnakePart *SnakePart::getForward()
{
    return forward;
}

void SnakePart::setForward(SnakePart *value)
{
    forward = value;
}

SnakePart *SnakePart::getBackward()
{
    return backward;
}

void SnakePart::setBackward(SnakePart *value)
{
    backward = value;
}

QString SnakePart::getDirection()
{
    return direction;
}

void SnakePart::setDirection( QString value)
{
    direction = value;
}


void SnakePart::move() {    
    static int first;

    if (direction == "DOWN")
        this->setY(this->y()+20);
    else if(direction == "UP")
        this->setY(this->y()-20);
    else if(direction == "LEFT")
        this->setX(this->x()-20);
    else if(direction == "RIGHT")
        this->setX(this->x()+20);
    if(this->getForward()!= NULL)
        direction = this->getForward()->direction;

    if(first)
    {
        if(this->y() >= 600 ){
            this->setY(0);
        }
        else if(this->y()<0){

            this->setY(600);
        }
        else if(this->x() < 0){

            this->setX(1260);
        }
        else if(this->x() >= 1260){
            this->setX(0);
        }
    }
    first++;
    if(part == "HEAD")
        checkCollidingObjects();
    setImage();
}

void SnakePart::addBehind()
{
    int x=0;
    int y=0;

    if(this->getForward()->getDirection() == "UP")
    {
        x = this->getForward()->x();
        y = this->getForward()->y() + 20;
    }
    else if(this->getForward()->getDirection() == "DOWN")
    {
        x = this->getForward()->x();
        y = this->getForward()->y() - 20;
    }
    else if(this->getForward()->getDirection() == "RIGHT")
    {
        y = this->getForward()->y();
        x = this->getForward()->x() - 20;
    }
    else if(this->getForward()->getDirection() == "LEFT")
    {
        y = this->getForward()->y();
        x = this->getForward()->x() + 20;
    }
    setPos(x,y);
}

void SnakePart::setImage()
{
    if(part == "HEAD")
    {
        if(direction == "UP")
        {
          setPixmap(QPixmap(":/Images/Images/headup.png").scaled(20,20));
        }
        else if(direction == "DOWN")
        {
           setPixmap(QPixmap(":/Images/Images/headDown.png").scaled(20,20));
        }
        else if(direction == "LEFT")
        {
            setPixmap(QPixmap(":/Images/Images/headLeft.png").scaled(20,20));
        }
        else if(direction == "RIGHT")
        {
            setPixmap(QPixmap(":/Images/Images/head.png").scaled(20,20));
        }
        setZValue(2);
    }
    else if(part == "TAIL")
    {
        if(direction == "UP")
        {
          setPixmap(QPixmap(":/Images/Images/tailUp.png").scaled(20,20));
        }
        else if(direction == "DOWN")
        {
           setPixmap(QPixmap(":/Images/Images/tailDown.png").scaled(20,20));
        }
        else if(direction == "LEFT")
        {
            setPixmap(QPixmap(":/Images/Images/tailLeft.png").scaled(20,20));
        }
        else if(direction == "RIGHT")
        {
            setPixmap(QPixmap(":/Images/Images/tail.png").scaled(20,20));
        }
    }
    else if (part == "PART")
    {
        if(direction == this->backward->getDirection())
        {
            if(direction == "LEFT" ||direction ==  "RIGHT")
                setPixmap(QPixmap(":/Images/Images/left-right.png").scaled(20,20));
            else if (direction == "UP" || direction == "DOWN")
                setPixmap(QPixmap(":/Images/Images/up-down.png").scaled(20,20));
        }
        else
        {
            if((direction == "UP" && this->backward->getDirection() == "LEFT")|| (direction == "RIGHT" && this->backward->getDirection() == "DOWN"))
                setPixmap(QPixmap(":/Images/Images/leftUp-downRight.png").scaled(20,20));
            else if((direction == "UP" && this->backward->getDirection() == "RIGHT")|| (direction == "LEFT" && this->backward->getDirection() == "DOWN"))
                setPixmap(QPixmap(":/Images/Images/rightUp-downLeft.png").scaled(20,20));
            else if((direction == "LEFT" && this->backward->getDirection() == "UP")|| (direction == "DOWN" && this->backward->getDirection() == "RIGHT"))
                setPixmap(QPixmap(":/Images/Images/upLeft-rightDown.png").scaled(20,20));
            else
                setPixmap(QPixmap(":/Images/Images/upRight-leftDown.png").scaled(20,20));
        }
    }
}

void SnakePart::checkCollidingObjects()
{
    QList <QGraphicsItem *> coll = this->collidingItems();

    for(int i = 0,n = coll.length(); i < n; i++)
    {

        apple *f = dynamic_cast<apple *>(coll[i]);
        if(f)
        {            
            music ->setSource(QUrl("qrc:/Audio/eat.mp3"));
            QPointF thisCenter(x()+10,y()+10);
            QPointF foodCenter(f->x()+10,f->y()+10);
            QLineF ln(thisCenter,foodCenter);
            if(ln.length() == 0)
            {
                music->play();
                game->gameScene->removeItem(f);
                game->snake->addPart();
                game->score->setScore(game->score->getScore()+f->score);
                delete f;

            }
        }
        else if(coll[i])
        {
            if(typeid(*coll[i])== typeid(SnakePart))
            {
                game->gameOver();
            }
        }
    }
}
