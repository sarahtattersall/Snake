#ifndef SCENE_HPP
#define SCENE_HPP

#include "Rules.hpp"
#include "Board.hpp"
#include "Coord.hpp"

#include <boost/shared_ptr.hpp>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include <QKeyEvent>
#include <QDebug>


class Scene : public QGraphicsScene{
    Q_OBJECT
public:
    Scene(shared_ptr<Board> board, shared_ptr<Rules> rules);
    void keyPressEvent(QKeyEvent *event);
    ~Scene();
public slots:
    void move_snake();
private:
    QGraphicsView view;    
    QPainter painter;
    shared_ptr<Board> m_board;
    shared_ptr<Rules> m_rules;
    QTransform m_transform;
    QTimer* m_timer;
    bool m_playing;
    // A bool to determine if a key has been pressed for the given turn.
    bool m_key_press;

    void end_game();
    void update_view();
    // Maps board point x to the view, taking into consideration
    // size of objects
    int map_to_view(int x, int size);
    QGraphicsItem* find_item(Coord coord);
    Coord get_scene_coord(CellOccupier* occupier);
};

#endif
