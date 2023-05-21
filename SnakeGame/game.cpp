#include "game.h"


Game::Game(QWidget *parent):QGraphicsView(parent)
{
    //making the view or window
    setFixedSize(1260,600);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    //making the game scene
    gameScene = new QGraphicsScene(this);
    gameScene->setSceneRect(0,0,1260,600);    
    //adding the gameScene to the view
    setScene(gameScene);
    snake2 = NULL;
    snake = NULL;   
}

void Game::keyPressEvent(QKeyEvent *event)
{
    if(snake)
    snake->keyPressEvent(event);
    else
        QGraphicsView::keyPressEvent(event);
}

void Game::displayMainMenu(QString title,QString play)
{
  //Create the title
    bg = new QGraphicsPixmapItem();
    bg->setPixmap(QPixmap(":/Images/Images/bg - Copy.jpg").scaled(1260,600));
    gameScene->addItem(bg);
    titleText = new QGraphicsTextItem(title);
    QFont titleFont("Courier" , 50);
    titleText->setFont( titleFont);
    int xPos = width()/2 - titleText->boundingRect().width()/2;
    int yPos = 150;
    titleText->setPos(xPos,yPos);
    gameScene->addItem(titleText);
    //create Button
    Button * playButton = new Button(play,titleText);
    int pxPos = 0 ;
    int pyPos = 80;
    playButton->setPos(pxPos,pyPos);
    connect(playButton,SIGNAL(clicked()) , this , SLOT(start()));
    //gameScene->addItem(playButton);


    //Create Quit Button
    Button * quitButton = new Button("Quit",titleText);
    int qxPos = 240;
    int qyPos = 80;
    quitButton->setPos(qxPos,qyPos);
    connect(quitButton, SIGNAL(clicked()),this,SLOT(close()));
    //gameScene->addItem(quitButton);
}
void Game::start(){
    gameScene->removeItem(bg);
    bg->setPixmap(QPixmap(":/Images/Images/PlayBackground.png").scaled(1260,600));
    gameScene->addItem(bg);
    score = new Score();
    gameScene->addItem(score);
    snake = new SnakeMove();
    snake->setFlag(QGraphicsItem::ItemIsFocusable);
    snake->setFocus();
    score->setVisible(true);
    score->setScore(0);
    gameScene->addItem(snake);
    gameScene->removeItem(titleText);
    delete titleText;
    if (snake2)
    snake2->deleteLater();
    snake2 = snake;

}

void Game::gameOver(){    
    displayMainMenu("Game Over!!!","Play Again");
    gameScene->removeItem(snake);    
}
