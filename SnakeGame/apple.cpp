#include "apple.h"

#include <QBrush>

apple::apple(QGraphicsItem *parent):QGraphicsPixmapItem(parent)
{   
    setPixmap(QPixmap(":/Images/Images/apple.png"));
    score = 1;

}
