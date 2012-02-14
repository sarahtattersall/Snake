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

#endif