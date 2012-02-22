#ifndef CELL_OBJECT_HPP
#define CELL_OBJECT_HPP

#include <QGraphicsRectItem>
#include <QPainter>
#include <QObject>

class CellObject : public QGraphicsRectItem{
private:
    static int s_size;
public:
    // Takes coords for scene.
    CellObject(int x, int y);
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) = 0;
    static int get_width();
    static int get_height();
};

class FoodObject : public CellObject{
public:
    // Takes coords for scene.
    FoodObject(int x, int y);
    virtual void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget);
};

class SnakeObject : public CellObject{
public:
    // Takes coords for scene.
    SnakeObject(int x, int y, int player);
    virtual void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget);
private:
    int m_player_number;
};

class SnakeDeadObject : public CellObject{
public:
    SnakeDeadObject(int x, int y);
    virtual void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget);
};

class WallObject : public CellObject{
public:
    // Takes coords for scene.
    WallObject(int x, int y);
    virtual void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget);
};

#endif