#ifndef CELL_OBJECT_HPP
#define CELL_OBJECT_HPP

#include <QGraphicsRectItem>
#include <QPainter>
#include <QObject>
#include "Coord.hpp"

class CellObject : public QGraphicsRectItem{
private:
    static const int s_size = 10;
public:
    // Takes coords for scene.
    CellObject(Coord coord) : QGraphicsRectItem(coord.get_x(),coord.get_y(),s_size,s_size) {};
    static int get_width(){
        return s_size;
    }
    static int get_height(){
        return s_size;
    }
};

#endif