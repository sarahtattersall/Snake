#ifndef CELL_OBJECT_HPP
#define CELL_OBJECT_HPP

#include <QGraphicsRectItem>
#include <QPainter>
#include <QObject>
#include "Coord.hpp"

class CellObject : public QGraphicsRectItem{
private:
    static int s_size;
public:
    // Takes coords for scene.
    CellObject(Coord coord);
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) = 0;
    static int get_width();
    static int get_height();
};

class FoodObject : public CellObject{
public:
    // Takes coords for scene.
    FoodObject(Coord coord);
    virtual void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget);
};

class SnakeObject : public CellObject{
public:
    // Takes coords for scene.
    SnakeObject(Coord coord, int player);
    virtual void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget);
private:
    int m_player_number;
};

class SnakeDeadObject : public CellObject{
public:
    SnakeDeadObject(Coord coord);
    virtual void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget);
};

class WallObject : public CellObject{
public:
    // Takes coords for scene.
    WallObject(Coord coord);
    virtual void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget);
};

#endif