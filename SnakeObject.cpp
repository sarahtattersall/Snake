#include "SnakeObject.hpp"
SnakeObject::SnakeObject(int x, int y) : CellObject(x,y){   
}

void SnakeObject::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget){
    setBrush(Qt::green);
    painter->setPen(Qt::green);
    QGraphicsRectItem::paint(painter, option, widget);
}

SnakeDeadObject::SnakeDeadObject(int x, int y) : CellObject(x,y){   
}

void SnakeDeadObject::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget){
    setBrush(Qt::red);
    painter->setPen(Qt::red);
    QGraphicsRectItem::paint(painter, option, widget);
}