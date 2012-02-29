#include <assert.h>
#include "CellObject.hpp"
int CellObject::s_size = 10;
CellObject::CellObject(Coord coord) : QGraphicsRectItem(coord.get_x(),coord.get_y(),s_size,s_size){    
}

int CellObject::get_width(){
    return s_size;
}

int CellObject::get_height(){
    return s_size;
}
/*
FoodObject::FoodObject(Coord coord) : CellObject(coord){	
}

void FoodObject::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget){
    setBrush(Qt::yellow);
    painter->setPen(Qt::yellow);
	QGraphicsRectItem::paint(painter, option, widget);
}

SnakeObject::SnakeObject(Coord coord, int player) : CellObject(coord){  
    m_player_number = player; 
}

void SnakeObject::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget){
    if (m_player_number == 0){
        setBrush(Qt::green);
        painter->setPen(Qt::green);
    } else{
        assert(m_player_number == 1);
        setBrush(Qt::cyan);
        painter->setPen(Qt::cyan);
    }
    
    QGraphicsRectItem::paint(painter, option, widget);
}

SnakeDeadObject::SnakeDeadObject(Coord coord) : CellObject(coord){   
}

void SnakeDeadObject::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget){
    setBrush(Qt::red);
    painter->setPen(Qt::red);
    QGraphicsRectItem::paint(painter, option, widget);
}

WallObject::WallObject(Coord coord) : CellObject(coord){ 
}

void WallObject::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget){
    setBrush(Qt::blue);
    painter->setPen(Qt::blue);
    QGraphicsRectItem::paint(painter, option, widget);
}*/