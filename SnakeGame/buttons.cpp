#include "buttons.h"


Button::Button(QString name, QGraphicsItem *parent):QGraphicsRectItem(parent)
{
    //Draw Rect
    setRect(0,0,200,50);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::darkCyan);
    setBrush(brush);

    //Text
    text = new QGraphicsTextItem(name,this);
    int xPos = rect().width()/2-text->boundingRect().width()/2;
    int yPos = rect().height()/2-text->boundingRect().height()/2;
    text->setPos(xPos,yPos);

    //Allowing Hover Events
    setAcceptHoverEvents(true);
}

void Button::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(event)
    {
        emit clicked();

    }
}
void Button::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    if(event)
    {
        QBrush brush;
        brush.setStyle(Qt::SolidPattern);
        brush.setColor(Qt::cyan);
        setBrush(brush);
    }
}

void Button::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    if(event)
    {
        QBrush brush;
        brush.setStyle(Qt::SolidPattern);
        brush.setColor(Qt::darkCyan);
        setBrush(brush);
    }
}
