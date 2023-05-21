#ifndef APPLE_H
#define APPLE_H
#include <QGraphicsPixmapItem>
class apple:public QGraphicsPixmapItem
{
public:
    apple(QGraphicsItem *parent = 0);
    int score;
};
#endif // APPLE_H
