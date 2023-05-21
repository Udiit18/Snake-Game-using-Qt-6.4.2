#include "game.h"
#include <QApplication>
Game *game;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    game = new Game();
    game->show();
    game->displayMainMenu("Snake Game","Play");
    return a.exec();
}
