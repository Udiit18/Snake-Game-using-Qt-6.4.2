#ifndef BUTTONS_H
#define BUTTONS_H

#include<QGraphicsRectItem>
#include<QGraphicsSceneMouseEvent>
#include<QGraphicsTextItem>
#include<QBrush>
class Button:public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    Button(QString name, QGraphicsItem *parent = nullptr);

    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);

    QGraphicsTextItem *text;
signals:
    void clicked();
private:
    QString name;
};

#endif // BUTTONS_H
